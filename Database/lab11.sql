
-- SQL Database Script

-- Create Database
CREATE DATABASE Lab10Exercise2;
GO

USE Lab10Exercise2;
GO

--Create table
Create table items
(ItemNo int,
ItemName varchar(15),
TotalUnits int
)
GO
--insert values
Insert into items
values
(1,'Soap', 10 )
,(2,'Handwash', 20)
,(3,'Shampoo',5)
GO

Create PROCEDURE [dbo].[deleteItem]
@ID int
AS
BEGIN
SET NOCOUNT ON;
DELETE FROM Items WHERE ItemNo = @ID
END

select*from dbo.items
