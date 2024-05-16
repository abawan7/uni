
create database umerlab05
use umerlab05
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Items](
	[ItemNo] [int] NOT NULL,
	[Name] [varchar](10) NULL,
	[Price] [int] NULL,
	[Quantity in Store] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[ItemNo] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Items] ([ItemNo], [Name], [Price], [Quantity in Store]) VALUES (100, N'A', 1000, 100)
INSERT [dbo].[Items] ([ItemNo], [Name], [Price], [Quantity in Store]) VALUES (200, N'B', 2000, 50)
INSERT [dbo].[Items] ([ItemNo], [Name], [Price], [Quantity in Store]) VALUES (300, N'C', 3000, 60)
INSERT [dbo].[Items] ([ItemNo], [Name], [Price], [Quantity in Store]) VALUES (400, N'D', 6000, 400)
/****** Object:  Table [dbo].[Courses]    Script Date: 02/17/2017 13:04:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Customers](
	[CustomerNo] [varchar](2) NOT NULL,
	[Name] [varchar](30) NULL,
	[City] [varchar](3) NULL,
	[Phone] [varchar](11) NULL,
PRIMARY KEY CLUSTERED 
(
	[CustomerNo] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C1', N'AHMED ALI', N'LHR', N'111111')
INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C2', N'ALI', N'LHR', N'222222')
INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C3', N'AYESHA', N'LHR', N'333333')
INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C4', N'BILAL', N'KHI', N'444444')
INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C5', N'SADAF', N'KHI', N'555555')
INSERT [dbo].[Customers] ([CustomerNo], [Name], [City], [Phone]) VALUES (N'C6', N'FARAH', N'ISL', NULL)
/****** Object:  Table [dbo].[Order]    Script Date: 02/17/2017 13:04:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Order](
	[OrderNo] [int] NOT NULL,
	[CustomerNo] [varchar](2) NULL,
	[Date] [date] NULL,
	[Total_Items_Ordered] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[OrderNo] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Order] ([OrderNo], [CustomerNo], [Date], [Total_Items_Ordered]) VALUES (1, N'C1', CAST(0x7F360B00 AS Date), 30)
INSERT [dbo].[Order] ([OrderNo], [CustomerNo], [Date], [Total_Items_Ordered]) VALUES (2, N'C3', CAST(0x2A3C0B00 AS Date), 5)
INSERT [dbo].[Order] ([OrderNo], [CustomerNo], [Date], [Total_Items_Ordered]) VALUES (3, N'C3', CAST(0x493C0B00 AS Date), 20)
INSERT [dbo].[Order] ([OrderNo], [CustomerNo], [Date], [Total_Items_Ordered]) VALUES (4, N'C4', CAST(0x4A3C0B00 AS Date), 15)
/****** Object:  Table [dbo].[OrderDetails]    Script Date: 02/17/2017 13:04:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[OrderDetails](
	[OrderNo] [int] NOT NULL,
	[ItemNo] [int] NOT NULL,
	[Quantity] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[OrderNo] ASC,
	[ItemNo] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[OrderDetails] ([OrderNo], [ItemNo], [Quantity]) VALUES (1, 200, 20)
INSERT [dbo].[OrderDetails] ([OrderNo], [ItemNo], [Quantity]) VALUES (1, 400, 10)
INSERT [dbo].[OrderDetails] ([OrderNo], [ItemNo], [Quantity]) VALUES (2, 200, 5)
INSERT [dbo].[OrderDetails] ([OrderNo], [ItemNo], [Quantity]) VALUES (3, 200, 60)

GO
/****** Object:  ForeignKey [FK__OrderDeta__ItemN__4316F928]    Script Date: 02/03/2017 13:55:38 ******/
ALTER TABLE [dbo].[OrderDetails]  WITH CHECK ADD FOREIGN KEY([ItemNo])
REFERENCES [dbo].[Items] ([ItemNo])
GO
/****** Object:  ForeignKey [FK__OrderDeta__Order__4222D4EF]    Script Date: 02/03/2017 13:55:38 ******/
ALTER TABLE [dbo].[OrderDetails]  WITH CHECK ADD FOREIGN KEY([OrderNo])
REFERENCES [dbo].[Order] ([OrderNo])
GO


select * from customers
select * from items
select * from orderdetails
select * from [Order]


--Views


--1

CREATE VIEW OrderTotalPrice AS
SELECT OrderNumber, ItemPrice * ItemQuantity AS TotalPrice
FROM Orders
WHERE TotalPrice = ItemPrice * ItemQuantity;


--2

CREATE VIEW TopSellingItems AS
SELECT ItemName
FROM Items
WHERE QuantitySold > 20;


--3

CREATE VIEW StarCustomers AS
SELECT CustomerName
FROM Purchases
WHERE PurchaseAmount > 2000;


--4
CREATE VIEW CustomersWithPhone AS
SELECT * 
FROM Customers 
WHERE PhoneNumber IS NOT NULL
WITH CHECK OPTION;


--5
CREATE VIEW CustomersWithoutItemC WITH CHECK OPTION AS
SELECT * 
FROM Customers
WHERE CustomerName NOT IN (SELECT CustomerName FROM Orders WHERE ItemOrdered = 'Item C');



--Stored Procedure


--1
CREATE PROCEDURE PlaceOrder
    @OrderNumber INT,
    @ItemNumber INT,
    @OrderedQuantity INT
AS
BEGIN
    DECLARE @Quantity INT
    SELECT @Quantity= orderDetails.Quantity
    FROM OrderDetails
    WHERE OrderDetails.ItemNo = @ItemNumber

    IF @Quantity < @OrderedQuantity
    BEGIN
        PRINT 'Only ' + CAST(@Quantity AS VARCHAR(10)) + ' is present, which is less than your required quantity.'
    END
    ELSE
    BEGIN
        INSERT INTO OrderDetails (OrderNo, ItemNo, Quantity)
        VALUES (@OrderNumber, @ItemNumber, @OrderedQuantity)
        
        UPDATE OrderDetails
        SET orderDetails.Quantity = Quantity - @OrderedQuantity
        WHERE ItemNo = @ItemNumber
        
        PRINT 'Order placed successfully!'
    END
END

EXEC PlaceOrder @OrderNumber = 4, @ItemNumber = 400, @OrderedQuantity = 6


--Post Lab


--1
CREATE PROCEDURE SignupCustomer 
    @CustomerNo INT, 
    @Name VARCHAR(100), 
    @City VARCHAR(100), 
    @Phone VARCHAR(10), 
    @Flag INT OUTPUT
AS
BEGIN
    IF EXISTS (SELECT 1 FROM Customers WHERE CustomerNo = @CustomerNo)
        SET @Flag = 1
    ELSE IF @City IS NULL
        SET @Flag = 2
    ELSE IF LEN(@Phone) <> 6
        SET @Flag = 3
    ELSE
    BEGIN
        INSERT INTO Customers (CustomerNo, Name, City, Phone) VALUES (@CustomerNo, @Name, @City, @Phone);
        SET @Flag = 0;
    END
END;

DECLARE @ResultFlag INT;
EXEC SignupCustomer 123, 'John Doe', 'New York', '123456', @ResultFlag OUTPUT;
PRINT @ResultFlag;


--2
CREATE PROCEDURE CancelOrder 
    @CustomerNo INT, 
    @OrderNo INT
AS
BEGIN
    IF EXISTS (SELECT 1 FROM Orders WHERE OrderNo = @OrderNo AND CustomerNo = @CustomerNo)
    BEGIN
        DELETE FROM OrderDetails WHERE OrderNo = @OrderNo;
        DELETE FROM Orders WHERE OrderNo = @OrderNo;
    END
    ELSE
    BEGIN
        DECLARE @CustomerName VARCHAR(100);
        SELECT @CustomerName = Name FROM Customers WHERE CustomerNo = @CustomerNo;
        PRINT 'Order no ' + @OrderNo + ' is not of ' + @CustomerNo + ' ' + @CustomerName;
    END
END;

EXEC CancelOrder 123, 789;


--3
CREATE PROCEDURE GetCustomerPoints 
    @CustomerName VARCHAR(100)
AS
BEGIN
    DECLARE @TotalPoints INT;
    SELECT @TotalPoints = SUM(PurchaseAmount) / 100 FROM Purchases WHERE CustomerName = @CustomerName;
    PRINT @CustomerName + ' has ' + @TotalPoints + ' points.';
END;

EXEC GetCustomerPoints 'John Doe';






