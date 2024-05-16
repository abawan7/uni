create database lab10db;

use lab10db

create table department(
deptid int primary key,
dname varchar(80) not null

)

create table student(
rollno int primary key,
name varchar (80) not null,
dept_id int foreign key references department (deptid),
batch int not null

)
create table course(
courseid int primary key,
cname varchar(80) not null,
credithrs int not null,
deptid int foreign key references department (deptid)

)
create table section(
sectionid int primary key,
courseid int foreign key references course (courseid),
capacity int not null

)
create table enrolled(
studentrollno int foreign key references student (rollno),
sectionid int foreign key references section (sectionid)
primary key(studentrollno,sectionid)

)

create table faculty(
facultyid int primary key,
fname varchar(80) not null,
deptid int foreign key references department (deptid)
)


INSERT INTO department (deptid, dname) VALUES (1, 'Computer Science');
INSERT INTO department (deptid, dname) VALUES (2, 'Electrical Engineering');
INSERT INTO department (deptid, dname) VALUES (3, 'Mechanical Engineering');


INSERT INTO student (rollno, name, dept_id, batch) VALUES (1001, 'John Doe', 1, 2023);
INSERT INTO student (rollno, name, dept_id, batch) VALUES (1002, 'Jane Smith', 2, 2022);
INSERT INTO student (rollno, name, dept_id, batch) VALUES (1003, 'Bob Johnson', 1, 2024);


INSERT INTO course (courseid, cname, credithrs, deptid) VALUES (101, 'Data Structures', 3, 1);
INSERT INTO course (courseid, cname, credithrs, deptid) VALUES (102, 'Digital Signal Processing', 4, 2);
INSERT INTO course (courseid, cname, credithrs, deptid) VALUES (103, 'Mechanics', 4, 3);


INSERT INTO section (sectionid, courseid, capacity) VALUES (201, 101, 50);
INSERT INTO section (sectionid, courseid, capacity) VALUES (202, 102, 40);
INSERT INTO section (sectionid, courseid, capacity) VALUES (203, 103, 30);
INSERT INTO section (sectionid, courseid, capacity) VALUES (204, 101, 30);


INSERT INTO enrolled (studentrollno, sectionid) VALUES (1001, 201);
INSERT INTO enrolled (studentrollno, sectionid) VALUES (1002, 202);
INSERT INTO enrolled (studentrollno, sectionid) VALUES (1003, 203);


INSERT INTO faculty (facultyid, fname, deptid) VALUES (501, 'Dr. Smith', 1);
INSERT INTO faculty (facultyid, fname, deptid) VALUES (502, 'Dr. Johnson', 2);
INSERT INTO faculty (facultyid, fname, deptid) VALUES (503, 'Dr. Brown', 3);


select * from faculty
select * from enrolled
select * from section
select * from course
select * from student
select * from department

--1
create table auditing(
auditid int IDENTITY(1,1) primary key,--auto increment
lastchangeon date not null
)

go
create trigger q1
on department
after update,insert,delete
as begin
insert into auditing values(getdate())
end

disable trigger q1 on department--for next question
go
create trigger q11
on student
after update,insert,delete
as begin
insert into auditing values(getdate())
end

disable trigger q11 on student--for next question
go
create trigger q111
on faculty
after update,insert,delete
as begin
insert into auditing values(getdate())
end

disable trigger q111 on faculty--for next question

update faculty set fname ='Dr.Umer' where facultyid=501

select * from auditing

--2
alter table auditing add description varchar(20)

go
create trigger q222
on faculty
after update,insert,delete
as begin
insert into auditing values(getdate(),'faculty')
end

go
create trigger q2
on department
after update,insert,delete
as begin
insert into auditing values(getdate(),'department')
end

go
create trigger q22
on student
after update,insert,delete
as begin
insert into auditing values(getdate(),'student')
end

go

update faculty set fname ='Dr.Ahmad' where facultyid=501

select * from auditing

--3
go
create view enrollment
as 
select course.courseid,course.cname,section.sectionid,section.capacity from course join section on course.courseid = section.courseid


--4
go
create procedure enrollment1
@studentid int,
@courseid int,
@sectionid int
as begin
declare @capacity int
select @capacity=capacity from enrollment where courseid=@courseid and sectionid=@sectionid
if(@capacity>0)
begin
insert into enrolled values(@studentid,@sectionid)
end
else
print 'could not insert'
end

execute enrollment1 1003,102,202

select * from enrolled

--q5
go
create trigger q5
on department
instead of update,insert,delete
as begin
print 'not allowed to modify departments'
end

insert into department values(4,'CV')

--q6
go
create trigger q6
on database
for alter_table,drop_table
as begin
print 'not allowed to alter or drop tables'
end