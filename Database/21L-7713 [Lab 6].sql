Create database ATM
go 
use ATM
go

create table [User](
[userId] int primary key,
[name] varchar(20) not null,
[phoneNum] varchar(15) not null,
[city] varchar(20) not null
)
go

create table CardType(
[cardTypeID] int primary key,
[name] varchar(15),
[description] varchar(40) null
)
go
create Table [Card](
cardNum Varchar(20) primary key,
cardTypeID int foreign key references  CardType([cardTypeID]),
PIN varchar(4) not null,
[expireDate] date not null,
balance float not null
)
go


Create table UserCard(
userID int foreign key references [User]([userId]),
cardNum varchar(20) foreign key references [Card](cardNum),
primary key(cardNum)
)
go
create table [Transaction](
transId int primary key,
transDate date not null,
cardNum varchar(20) foreign key references [Card](cardNum),
amount int not null
)


INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (1, N'Ali', N'03036067000', N'Narowal')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (2, N'Ahmed', N'03036047000', N'Lahore')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (3, N'Aqeel', N'03036063000', N'Karachi')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (4, N'Usman', N'03036062000', N'Sialkot')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (5, N'Hafeez', N'03036061000', N'Lahore')
GO


INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (1, N'Debit', N'Spend Now, Pay Now')
GO
INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (2, N'Credit', N'Spend Now, Pay later')
GO

INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1234', 1, N'1770', CAST(N'2022-07-01' AS Date), 43025.31)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1235', 1, N'9234', CAST(N'2020-03-02' AS Date), 14425.62)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1236', 1, N'1234', CAST(N'2019-02-06' AS Date), 34325.52)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1237', 2, N'1200', CAST(N'2021-02-05' AS Date), 24325.3)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1238', 2, N'9004', CAST(N'2020-09-02' AS Date), 34025.12)
GO

INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1234')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1235')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (2, N'1236')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (3, N'1238')
GO
Insert  [dbo].[UserCard] ([userID], [cardNum]) VALUES (4, N'1237')

INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (1, CAST(N'2017-02-02' AS Date), N'1234', 500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (2, CAST(N'2018-02-03' AS Date), N'1235', 3000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (3, CAST(N'2020-01-06' AS Date), N'1236', 2500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (4, CAST(N'2016-09-09' AS Date), N'1238', 2000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (5, CAST(N'2020-02-10' AS Date), N'1234', 6000)
GO



--Q1
create function Balance(@cardd int)
returns int
as
begin

declare @returnvalue int
select @returnvalue=balance from [Card] where [Card].cardNum=@cardd
return @returnvalue
end

select dbo.Balance(1234)

--Q2
create function dbo.getDetails(@userID int)
returns table
as
return select*
from [User] where [User].userId=@userID

select* from dbo.getDetails(2)

--Q3
create procedure details
@username varchar(20)
as
begin
select * from [User] where [User].name=@username
End
go

declare @userName varchar(20)='Ali'
execute details
@username=@userName

--Q4
create procedure card_Details
@userID int
as
begin 
select C.cardNum,C.balance
from [Card] C
join UserCard UD on UD.cardNum=C.cardNum
where UD.userID=@userID
End
go

declare @temp int=2
execute card_Details
@userID=@temp

--Q5
create procedure Login
@card_Num int,
@Pin int,
@output_Status int output
as
begin
	if exists(select * from [Card] where cardNum=@card_Num and PIN=@Pin)
		begin
			set @output_Status = 1
		end
	else
		begin
			set @output_Status = 0
		end
END
go

declare @cardnum int=1234,@PIN int=1770,@output int
execute Login
@card_Num=@cardnum,
@Pin=@PIN,
@output_Status=@output output
select @output as Output


--PostLab
--Q6

create procedure Cards
@userID int,
@num_Card int output
as
begin
	set	@num_Card=0

	select @num_Card=count(*)
	from [UserCard] UC
	where UC.userID=@userID
END

declare @cardcount int
exec Cards @userID=1,
@num_Card=@cardcount output
select @cardcount as output

--Q7
create procedure updatePIN
@cardNum nvarchar(10),
@oldPin nvarchar(4),
@newPin nvarchar(4)
as
begin
declare @crntPin nvarchar(4)
select @crntPin=C.PIN
from [Card] C
where cardNum=@cardNum

if @crntPin=@oldPin
	begin
		update [Card]
		set PIN=@newPin
		where cardNum=@cardNum

		print 'PIN is Updated'
	end
else
	begin
		print 'Error'
	end
end

exec updatePIN
@cardNum='1234', @oldPin='1770',@newPin='1000'



Select * from [User]
Select * from UserCard
Select * from [Card]
Select * from CardType
Select * from [Transaction]

--Q8
CREATE PROCEDURE Withdraw
    @CardNumber NVARCHAR(20),
    @PIN INT,
    @Amount DECIMAL(10, 2)
AS
BEGIN
    DECLARE @LoginStatus INT
    DECLARE @TransType INT

    EXEC Login @CardNumber, @PIN, @LoginStatus OUTPUT

    IF @LoginStatus = 1
    BEGIN
       
        DECLARE @NextTransID INT
        SELECT @NextTransID = ISNULL(MAX(transId), 0) + 1
        FROM [Transaction]

        ALTER TABLE [Transaction]
		ADD TransType INT;
        INSERT INTO [Transaction] (transId, transDate, cardNum, amount, TransType)
        VALUES (@NextTransID, GETDATE(), @CardNumber, @Amount, 1)

        UPDATE [Card]
        SET balance = balance - @Amount
        WHERE cardNum = @CardNumber

        SET @TransType = 1
    END
    ELSE
    BEGIN
        
        INSERT INTO [Transaction] (transId, transDate, cardNum, amount, TransType)
        VALUES ((SELECT ISNULL(MAX(transId), 0) + 1 FROM [Transaction]), GETDATE(), @CardNumber, @Amount, 4)

        SET @TransType = 4
    END

    SELECT @TransType AS TransType
END


DECLARE @CardNum NVARCHAR(20) = '1234'
DECLARE @PIN INT = 1770
DECLARE @Amount DECIMAL(10, 2) = 500.00

EXEC Withdraw @CardNumber = @CardNum, @PIN = @PIN, @Amount = @Amount


--Triggers

--Q1
go
create trigger t1 on Students
instead of delete
as
begin
print 'You Do Not Have The Permission To Delete The Student'
end
go

--Q2
go
create trigger t2 on Courses
instead of insert
as
begin
print 'You Do Not Have The Permission To Insert In Courses'
end
go

--Q3
go
create table Notify
(
NotificationID int primary key,
StudentID int,
Notification nvarchar(50)
);
CREATE TRIGGER NotifyStudentRegistration
ON Registration
AFTER INSERT
AS
BEGIN
    DECLARE @StudentID VARCHAR(7);
    DECLARE @Semester VARCHAR(15);
    DECLARE @CourseID INT;
    DECLARE @GPA FLOAT;
    DECLARE @NotificationString VARCHAR(255);

    SELECT @StudentID = R.RollNumber, @Semester = R.Semester, @CourseID = R.CourseID, @GPA = R.GPA
    FROM Registration AS R;

    IF @GPA > 2.0
    BEGIN
        print 'Registeration Successful'
    END
    ELSE
    BEGIN
        print 'Registeration Unsuccessful'
    END;
	INSERT INTO Notify (StudentID, Notification)
    VALUES (@StudentID, @NotificationString);
END;

select * from Notify

--Q4
CREATE TRIGGER EnforceFeeChargesLimit
ON Registration
INSTEAD OF INSERT
AS
BEGIN
    DECLARE @StudentID VARCHAR(7);
    DECLARE @Semester VARCHAR(15);
    DECLARE @CourseID INT;
    DECLARE @TotalDues INT;
    
   
    SELECT @StudentID = R.RollNumber, @Semester = R.Semester, @TotalDues = cf.TotalDues, @CourseID = R.CourseID
    FROM Registration AS R
    INNER JOIN ChallanForm AS cf ON R.Semester = cf.Semester AND R.RollNumber = cf.RollNumber;

    IF @TotalDues > 20000
    BEGIN
        PRINT 'Error: Student cannot enroll in Course for Semester due to excessive fee charges.';
    END
    ELSE
    BEGIN

        INSERT INTO Registration (Semester, RollNumber, CourseID, Section, GPA)
        SELECT Semester, RollNumber, CourseID, Section, GPA
        FROM inserted;
    END;
END;

--Q5
CREATE TRIGGER PreventDeleteLowSeats
ON Courses_Semester
INSTEAD OF DELETE
AS
BEGIN
    DECLARE @CourseID INT;
    DECLARE @Semester VARCHAR(15);
    DECLARE @AvailableSeats INT;

    SELECT @CourseID = d.CourseID, @Semester = d.Semester
    FROM deleted AS d;

    SELECT @AvailableSeats = AvailableSeats
    FROM Courses_Semester
    WHERE CourseID = @CourseID AND Semester = @Semester;

    IF @AvailableSeats < 10
    BEGIN
        PRINT 'Not possible';
    END
    ELSE
    BEGIN
        DELETE FROM Courses_Semester
        WHERE CourseID = @CourseID AND Semester = @Semester;
        PRINT 'Successfully deleted';
    END;
END;


--Q6
CREATE TRIGGER PreventInstructorsModification
ON Instructors
AFTER INSERT, UPDATE, DELETE
AS
BEGIN

    IF EXISTS (SELECT 1 FROM inserted) OR EXISTS (SELECT 1 FROM deleted)
    BEGIN

    END;
END;

