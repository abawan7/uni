--Group Members 

--Abdullah Awan 21L-7713
--Mudassir Ali 21L-5474
--Abdullah Saeed 21L-7601


--Bank_Management_System
-- Users Table
CREATE TABLE Users (
    UserID INT PRIMARY KEY IDENTITY(1,1),
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    PhoneNumber VARCHAR(15),
    IDCardNumber VARCHAR(50),
    DateOfBirth DATE,
    Address VARCHAR(255),
    Password VARCHAR(255),  -- Ensure you use a hashing method before storing passwords
    AccountStatus VARCHAR(10) DEFAULT 'active'
);

-- Accounts Table
CREATE TABLE Accounts (
    AccountID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Users(UserID),
    AccountNumber VARCHAR(20),
    AccountType VARCHAR(10),
    Balance DECIMAL(18,2),
    LastTransactionDate DATETIME
);

-- Transactions Table
CREATE TABLE Transactions (
    TransactionID INT PRIMARY KEY IDENTITY(1,1),
    AccountID INT FOREIGN KEY REFERENCES Accounts(AccountID),
    Type VARCHAR(50),
    Amount DECIMAL(18,2),
    DateAndTime DATETIME,
    SenderAccount VARCHAR(20),
    ReceiverAccount VARCHAR(20),
    Description VARCHAR(255)
);

-- BillPayments Table
CREATE TABLE BillPayments (
    PaymentID INT PRIMARY KEY IDENTITY(1,1),
    AccountID INT FOREIGN KEY REFERENCES Accounts(AccountID),
    BillType VARCHAR(50),
    Amount DECIMAL(18,2),
    Date DATETIME
);

-- Cards Table
CREATE TABLE Cards (
    CardID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Users(UserID),
    CardType VARCHAR(50),
    CardNumber VARCHAR(20),
    ExpiryDate DATE,
    CardLimit DECIMAL(18,2)
);

-- Cheques Table
CREATE TABLE Cheques (
    ChequeID INT PRIMARY KEY IDENTITY(1,1),
    AccountID INT FOREIGN KEY REFERENCES Accounts(AccountID),
    ChequeNumber VARCHAR(20),
    Amount DECIMAL(18,2),
    DateIssued DATETIME,
    DateEncashed DATETIME,
    Status VARCHAR(50)
);

-- MoneyRequests Table
CREATE TABLE MoneyRequests (
    RequestID INT PRIMARY KEY IDENTITY(1,1),
    SenderUserID INT FOREIGN KEY REFERENCES Users(UserID),
    ReceiverAccount VARCHAR(20),
    Amount DECIMAL(18,2),
    DateRequested DATETIME
);

-- Beneficiaries Table
CREATE TABLE Beneficiaries (
    BeneficiaryID INT PRIMARY KEY IDENTITY(1,1),
    AccountID INT FOREIGN KEY REFERENCES Accounts(AccountID),
    BeneficiaryAccount VARCHAR(20)
);

-- OnlinePurchases Table
CREATE TABLE OnlinePurchases (
    PurchaseID INT PRIMARY KEY IDENTITY(1,1),
    AccountID INT FOREIGN KEY REFERENCES Accounts(AccountID),
    Amount DECIMAL(18,2),
    DateOfPurchase DATETIME,
    CouponCode VARCHAR(20),
    DiscountAmount DECIMAL(18,2)
);

-- EducationPayments Table
CREATE TABLE EducationPayments (
    PaymentID INT PRIMARY KEY IDENTITY(1,1),
    AccountID INT FOREIGN KEY REFERENCES Accounts(AccountID),
    InstitutionName VARCHAR(100),
    Amount DECIMAL(18,2),
    DatePaid DATETIME
);

-- Loans Table
CREATE TABLE Loans (
    LoanID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Users(UserID),
    LoanAmount DECIMAL(18,2),
    InterestRate DECIMAL(5,2),
    StartDate DATETIME,
    EndDate DATETIME
);

-- Donations Table
CREATE TABLE Donations (
    DonationID INT PRIMARY KEY IDENTITY(1,1),
    AccountID INT FOREIGN KEY REFERENCES Accounts(AccountID),
    CharityName VARCHAR(100),
    Amount DECIMAL(18,2),
    DateDonated DATETIME
);

-- BudgetPlanner Table
CREATE TABLE BudgetPlanner (
    PlannerID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Users(UserID),
    MonthlyBudget DECIMAL(18,2),
    AverageSpent DECIMAL(18,2),
    Suggestions VARCHAR(500)
);

-- FamilyCards Table (Secondary)
CREATE TABLE FamilyCards (
    FamilyCardID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Users(UserID),
    ChildName VARCHAR(50),
    ChildDOB DATE,
    CardNumber VARCHAR(20)
);

-- TravelBookings Table (Secondary)
CREATE TABLE TravelBookings (
    BookingID INT PRIMARY KEY IDENTITY(1,1),
    AccountID INT FOREIGN KEY REFERENCES Accounts(AccountID),
    ModeOfTravel VARCHAR(50),
    TicketNumber VARCHAR(20),
    Amount DECIMAL(18,2),
    DateBooked DATETIME
);

-- Leasings Table (Secondary)
CREATE TABLE Leasings (
    LeaseID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Users(UserID),
    Product VARCHAR(100),
    LeaseAmount DECIMAL(18,2),
    StartDate DATETIME,
    EndDate DATETIME
);

-- InvestmentSuggestions Table (Secondary)
CREATE TABLE InvestmentSuggestions (
    SuggestionID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Users(UserID),
    InvestmentType VARCHAR(100),
    Amount DECIMAL(18,2),
    DateSuggested DATETIME
);   -- Inserting into Users Table
INSERT INTO Users (FirstName, LastName, PhoneNumber, IDCardNumber, DateOfBirth, Address, Password)
VALUES ('John', 'Doe', '123-456-7890', 'A123456B', '1990-01-01', '123 Main St, City A, Country X', 'hashed_password123');

INSERT INTO Users (FirstName, LastName, PhoneNumber, IDCardNumber, DateOfBirth, Address, Password)
VALUES ('Jane', 'Smith', '123-456-7891', 'B123456C', '1992-02-12', '124 Main St, City B, Country X', 'hashed_password456');

INSERT INTO Users (FirstName, LastName, PhoneNumber, IDCardNumber, DateOfBirth, Address, Password)
VALUES ('Robert', 'Brown', '123-456-7892', 'C123456D', '1985-05-15', '125 Main St, City C, Country X', 'hashed_password789');

INSERT INTO Users (FirstName, LastName, PhoneNumber, IDCardNumber, DateOfBirth, Address, Password)
VALUES ('Emily', 'Clark', '123-456-7893', 'D123456E', '1988-10-10', '126 Main St, City D, Country X', 'hashed_password012');

INSERT INTO Users (FirstName, LastName, PhoneNumber, IDCardNumber, DateOfBirth, Address, Password)
VALUES ('William', 'Johnson', '123-456-7894', 'E123456F', '1982-06-20', '127 Main St, City E, Country X', 'hashed_password345');   -- Inserting into Accounts Table

INSERT INTO Accounts (UserID, AccountNumber, AccountType, Balance, LastTransactionDate)
VALUES (1, '100000000001', 'Savings', 5000.00, '2023-01-05');

INSERT INTO Accounts (UserID, AccountNumber, AccountType, Balance, LastTransactionDate)
VALUES (2, '100000000002', 'Current', 12000.00, '2023-01-04');

INSERT INTO Accounts (UserID, AccountNumber, AccountType, Balance, LastTransactionDate)
VALUES (3, '100000000003', 'Savings', 7000.00, '2023-01-03');

INSERT INTO Accounts (UserID, AccountNumber, AccountType, Balance, LastTransactionDate)
VALUES (4, '100000000004', 'Savings', 10000.00, '2023-01-02');

INSERT INTO Accounts (UserID, AccountNumber, AccountType, Balance, LastTransactionDate)
VALUES (5, '100000000005', 'Current', 15000.00, '2023-01-01');   -- Inserting into Transactions Table

INSERT INTO Transactions (AccountID, Type, Amount, DateAndTime, SenderAccount, ReceiverAccount, Description)
VALUES (1, 'Deposit', 2000.00, '2023-01-06 10:30:00', NULL, '100000000001', 'Initial deposit');

INSERT INTO Transactions (AccountID, Type, Amount, DateAndTime, SenderAccount, ReceiverAccount, Description)
VALUES (2, 'Transfer', 500.00, '2023-01-06 11:00:00', '100000000002', '100000000001', 'Payment for services');

INSERT INTO Transactions (AccountID, Type, Amount, DateAndTime, SenderAccount, ReceiverAccount, Description)
VALUES (1, 'Deposit', 500.00, '2023-01-06 11:00:00', '100000000002', '100000000001', 'Received payment for services');

INSERT INTO Transactions (AccountID, Type, Amount, DateAndTime, SenderAccount, ReceiverAccount, Description)
VALUES (3, 'Withdrawal', 300.00, '2023-01-07 09:45:00', '100000000003', NULL, 'ATM withdrawal');

INSERT INTO Transactions (AccountID, Type, Amount, DateAndTime, SenderAccount, ReceiverAccount, Description)
VALUES (4, 'Deposit', 500.00, '2023-01-08 12:15:00', NULL, '100000000004', 'Deposited cash');

INSERT INTO Transactions (AccountID, Type, Amount, DateAndTime, SenderAccount, ReceiverAccount, Description)
VALUES (5, 'Online Purchase', 250.00, '2023-01-09 14:10:00', '100000000005', 'ONLINE_STORE', 'Bought items online');



-- Inserting into BillPayments Table

INSERT INTO BillPayments (AccountID, BillType, Amount, Date)
VALUES (1, 'Electricity', 120.00, '2023-01-06');

INSERT INTO BillPayments (AccountID, BillType, Amount, Date)
VALUES (1, 'Water', 40.00, '2023-01-07');

INSERT INTO BillPayments (AccountID, BillType, Amount, Date)
VALUES (2, 'Gas', 60.00, '2023-01-08');

INSERT INTO BillPayments (AccountID, BillType, Amount, Date)
VALUES (3, 'Electricity', 110.00, '2023-01-09');

INSERT INTO BillPayments (AccountID, BillType, Amount, Date)
VALUES (3, 'Internet', 50.00, '2023-01-10');

INSERT INTO BillPayments (AccountID, BillType, Amount, Date)
VALUES (4, 'Water', 45.00, '2023-01-11');

INSERT INTO BillPayments (AccountID, BillType, Amount, Date)
VALUES (5, 'Traffic Challan', 30.00, '2023-01-12');
  -- Inserting into Cards Table

INSERT INTO Cards (UserID, CardType, CardNumber, ExpiryDate, CardLimit)
VALUES (1, 'Debit', '4111111111111111', '2025-12-31', 5000.00);

INSERT INTO Cards (UserID, CardType, CardNumber, ExpiryDate, CardLimit)
VALUES (1, 'Credit', '5111111111111111', '2026-05-31', 10000.00);

INSERT INTO Cards (UserID, CardType, CardNumber, ExpiryDate, CardLimit)
VALUES (2, 'Credit', '5222222222222222', '2026-07-31', 12000.00);

INSERT INTO Cards (UserID, CardType, CardNumber, ExpiryDate, CardLimit)
VALUES (3, 'Debit', '4333333333333333', '2025-11-30', 4500.00);

INSERT INTO Cards (UserID, CardType, CardNumber, ExpiryDate, CardLimit)
VALUES (4, 'Debit', '4444444444444444', '2025-10-31', 4000.00);

INSERT INTO Cards (UserID, CardType, CardNumber, ExpiryDate, CardLimit)
VALUES (4, 'Credit', '5333333333333333', '2026-09-30', 8500.00);

INSERT INTO Cards (UserID, CardType, CardNumber, ExpiryDate, CardLimit)
VALUES (5, 'Debit', '4555555555555555', '2025-09-30', 6500.00);
  -- Inserting into Cheques Table

INSERT INTO Cheques (AccountID, ChequeNumber, Amount, DateIssued, Status)
VALUES (1, 'CHQ0001', 500.00, '2023-01-10', 'Issued');

INSERT INTO Cheques (AccountID, ChequeNumber, Amount, DateIssued, Status)
VALUES (1, 'CHQ0002', 250.00, '2023-01-15', 'Encashed');

INSERT INTO Cheques (AccountID, ChequeNumber, Amount, DateIssued, Status)
VALUES (2, 'CHQ0003', 1000.00, '2023-01-17', 'Issued');

INSERT INTO Cheques (AccountID, ChequeNumber, Amount, DateIssued, DateEncashed, Status)
VALUES (3, 'CHQ0004', 300.00, '2023-01-12', '2023-01-18', 'Encashed');

INSERT INTO Cheques (AccountID, ChequeNumber, Amount, DateIssued, Status)
VALUES (3, 'CHQ0005', 150.00, '2023-01-20', 'Issued');

INSERT INTO Cheques (AccountID, ChequeNumber, Amount, DateIssued, DateEncashed, Status)
VALUES (4, 'CHQ0006', 600.00, '2023-01-14', '2023-01-19', 'Encashed');

INSERT INTO Cheques (AccountID, ChequeNumber, Amount, DateIssued, Status)
VALUES (5, 'CHQ0007', 700.00, '2023-01-18', 'Issued');
  -- Inserting into MoneyRequests Table

INSERT INTO MoneyRequests (SenderUserID, ReceiverAccount, Amount, DateRequested)
VALUES (1, '100000000002', 200.00, '2023-01-15');

INSERT INTO MoneyRequests (SenderUserID, ReceiverAccount, Amount, DateRequested)
VALUES (2, '100000000003', 100.00, '2023-01-16');

INSERT INTO MoneyRequests (SenderUserID, ReceiverAccount, Amount, DateRequested)
VALUES (3, '100000000004', 50.00, '2023-01-17');

INSERT INTO MoneyRequests (SenderUserID, ReceiverAccount, Amount, DateRequested)
VALUES (4, '100000000005', 150.00, '2023-01-18');

INSERT INTO MoneyRequests (SenderUserID, ReceiverAccount, Amount, DateRequested)
VALUES (5, '100000000001', 300.00, '2023-01-19');
  -- Inserting into Beneficiaries Table

INSERT INTO Beneficiaries (AccountID, BeneficiaryAccount)
VALUES (1, '100000000002');

INSERT INTO Beneficiaries (AccountID, BeneficiaryAccount)
VALUES (1, '100000000005');

INSERT INTO Beneficiaries (AccountID, BeneficiaryAccount)
VALUES (2, '100000000003');

INSERT INTO Beneficiaries (AccountID, BeneficiaryAccount)
VALUES (3, '100000000004');

INSERT INTO Beneficiaries (AccountID, BeneficiaryAccount)
VALUES (4, '100000000001');

INSERT INTO Beneficiaries (AccountID, BeneficiaryAccount)
VALUES (4, '100000000003');

INSERT INTO Beneficiaries (AccountID, BeneficiaryAccount)
VALUES (5, '100000000002');   -- Inserting into OnlinePurchases Table

INSERT INTO OnlinePurchases (AccountID, Amount, DateOfPurchase, CouponCode, DiscountAmount)
VALUES (1, 50.00, '2023-01-10', 'NEWYEAR10', 5.00);

INSERT INTO OnlinePurchases (AccountID, Amount, DateOfPurchase, CouponCode, DiscountAmount)
VALUES (1, 25.00, '2023-01-15', 'FREESHIP', 0.00);

INSERT INTO OnlinePurchases (AccountID, Amount, DateOfPurchase, CouponCode, DiscountAmount)
VALUES (2, 100.00, '2023-01-17', NULL, 0.00);

INSERT INTO OnlinePurchases (AccountID, Amount, DateOfPurchase, CouponCode, DiscountAmount)
VALUES (3, 75.00, '2023-01-19', 'SALE15', 11.25);

INSERT INTO OnlinePurchases (AccountID, Amount, DateOfPurchase, CouponCode, DiscountAmount)
VALUES (4, 120.00, '2023-01-21', 'FLASH20', 24.00);

INSERT INTO OnlinePurchases (AccountID, Amount, DateOfPurchase, CouponCode, DiscountAmount)
VALUES (5, 45.00, '2023-01-22', NULL, 0.00);
  -- Inserting into EducationPayments Table

INSERT INTO EducationPayments (AccountID, InstitutionName, Amount, DatePaid)
VALUES (1, 'Tech University', 1000.00, '2023-01-10');

INSERT INTO EducationPayments (AccountID, InstitutionName, Amount, DatePaid)
VALUES (1, 'Alpha College', 500.00, '2023-01-11');

INSERT INTO EducationPayments (AccountID, InstitutionName, Amount, DatePaid)
VALUES (2, 'Beta Institute', 1200.00, '2023-01-15');

INSERT INTO EducationPayments (AccountID, InstitutionName, Amount, DatePaid)
VALUES (3, 'Gamma Academy', 750.00, '2023-01-18');

INSERT INTO EducationPayments (AccountID, InstitutionName, Amount, DatePaid)
VALUES (4, 'Delta School', 650.00, '2023-01-20');

INSERT INTO EducationPayments (AccountID, InstitutionName, Amount, DatePaid)
VALUES (5, 'Epsilon University', 1500.00, '2023-01-21');
  -- Inserting into Loans Table

INSERT INTO Loans (AccountID, LoanAmount, InterestRate, DateIssued, Description)
VALUES (1, 100000.00, 4.5, '2023-01-05', 'Housing loan for property in City A');

INSERT INTO Loans (AccountID, LoanAmount, InterestRate, DateIssued, Description)
VALUES (2, 15000.00, 6.0, '2023-01-10', 'Personal loan for medical expenses');

INSERT INTO Loans (AccountID, LoanAmount, InterestRate, DateIssued, Description)
VALUES (3, 50000.00, 5.5, '2023-01-15', 'Business loan for startup "Tech Innovate"');

INSERT INTO Loans (AccountID, LoanAmount, InterestRate, DateIssued, Description)
VALUES (4, 20000.00, 4.0, '2023-01-20', 'Educational loan for Master's program in BioTech');

INSERT INTO Loans (AccountID, LoanAmount, InterestRate, DateIssued, Description)
VALUES (5, 25000.00, 5.0, '2023-01-25', 'Car loan for purchasing a new Sedan');
  -- Inserting into Donations Table

INSERT INTO Donations (AccountID, CharityName, Amount, DateDonated)
VALUES (1, 'Edhi', 100.00, '2023-01-10');

INSERT INTO Donations (AccountID, CharityName, Amount, DateDonated)
VALUES (1, 'Shaukat Khanum', 150.00, '2023-01-15');

INSERT INTO Donations (AccountID, CharityName, Amount, DateDonated)
VALUES (2, 'Cheepa', 200.00, '2023-01-20');

INSERT INTO Donations (AccountID, CharityName, Amount, DateDonated)
VALUES (3, 'Edhi', 50.00, '2023-01-25');

INSERT INTO Donations (AccountID, CharityName, Amount, DateDonated)
VALUES (3, 'Shaukat Khanum', 75.00, '2023-01-26');

INSERT INTO Donations (AccountID, CharityName, Amount, DateDonated)
VALUES (4, 'Cheepa', 250.00, '2023-01-30');

INSERT INTO Donations (AccountID, CharityName, Amount, DateDonated)
VALUES (5, 'Edhi', 300.00, '2023-02-05');
  -- Inserting into BudgetPlanner Table

INSERT INTO BudgetPlanner (AccountID, MonthlyIncome, MonthlyExpenses, Investment, Savings, DateUpdated)
VALUES (1, 5000.00, 3200.00, 1000.00, 800.00, '2023-02-01');

INSERT INTO BudgetPlanner (AccountID, MonthlyIncome, MonthlyExpenses, Investment, Savings, DateUpdated)
VALUES (2, 6500.00, 4200.00, 1100.00, 1200.00, '2023-02-02');

INSERT INTO BudgetPlanner (AccountID, MonthlyIncome, MonthlyExpenses, Investment, Savings, DateUpdated)
VALUES (3, 4500.00, 3000.00, 900.00, 600.00, '2023-02-03');

INSERT INTO BudgetPlanner (AccountID, MonthlyIncome, MonthlyExpenses, Investment, Savings, DateUpdated)
VALUES (4, 5200.00, 3600.00, 1000.00, 600.00, '2023-02-04');

INSERT INTO BudgetPlanner (AccountID, MonthlyIncome, MonthlyExpenses, Investment, Savings, DateUpdated)
VALUES (5, 7000.00, 5000.00, 1500.00, 500.00, '2023-02-05');
  -- Inserting into FamilyCards Table

INSERT INTO FamilyCards (MainUserID, CardNumber, CardType, ExpiryDate, CardLimit, IssuedFor)
VALUES (1, '6111111111111111', 'Debit', '2025-05-31', 2000.00, 'John Doe Jr.');

INSERT INTO FamilyCards (MainUserID, CardNumber, CardType, ExpiryDate, CardLimit, IssuedFor)
VALUES (2, '6222222222222222', 'Debit', '2025-06-30', 2500.00, 'Mr. Smith');

INSERT INTO FamilyCards (MainUserID, CardNumber, CardType, ExpiryDate, CardLimit, IssuedFor)
VALUES (3, '6333333333333333', 'Debit', '2025-07-31', 1800.00, 'Sophia Brown');

INSERT INTO FamilyCards (MainUserID, CardNumber, CardType, ExpiryDate, CardLimit, IssuedFor)
VALUES (4, '6444444444444444', 'Credit', '2025-08-31', 2200.00, 'Mrs. Clark Senior');

INSERT INTO FamilyCards (MainUserID, CardNumber, CardType, ExpiryDate, CardLimit, IssuedFor)
VALUES (5, '6555555555555555', 'Debit', '2025-09-30', 2100.00, 'Mrs. Johnson');

INSERT INTO FamilyCards (MainUserID, CardNumber, CardType, ExpiryDate, CardLimit, IssuedFor)
VALUES (5, '6666666666666666', 'Debit', '2025-10-31', 1900.00, 'William Johnson Jr.');
 
-- Inserting into TravelBookings Table

INSERT INTO TravelBookings (UserID, BookingType, BookingDate, Amount, Company, Destination)
VALUES (1, 'Flight', '2023-02-10', 250.00, 'PIA', 'London');

INSERT INTO TravelBookings (UserID, BookingType, BookingDate, Amount, Company, Destination)
VALUES (1, 'Bus', '2023-02-15', 20.00, 'Daewoo', 'Lahore');

INSERT INTO TravelBookings (UserID, BookingType, BookingDate, Amount, Company, Destination)
VALUES (2, 'Train', '2023-02-12', 30.00, 'Pakistan Railways', 'Karachi');

INSERT INTO TravelBookings (UserID, BookingType, BookingDate, Amount, Company, Destination)
VALUES (3, 'Flight', '2023-02-18', 200.00, 'AirBlue', 'Dubai');

INSERT INTO TravelBookings (UserID, BookingType, BookingDate, Amount, Company, Destination)
VALUES (4, 'Bus', '2023-02-20', 15.00, 'Faisal Movers', 'Multan');

INSERT INTO TravelBookings (UserID, BookingType, BookingDate, Amount, Company, Destination)
VALUES (5, 'Train', '2023-02-22', 40.00, 'Pakistan Railways', 'Faisalabad');  -- Inserting into Leasings Table

INSERT INTO Leasings (UserID, LeasingType, Amount, StartDate, EndDate, Description)
VALUES (1, 'Car', 20000.00, '2023-02-01', '2026-02-01', 'Toyota Corolla 2023 Model');

INSERT INTO Leasings (UserID, LeasingType, Amount, StartDate, EndDate, Description)
VALUES (2, 'Bike', 5000.00, '2023-02-05', '2025-02-05', 'Honda 125 2023 Model');

INSERT INTO Leasings (UserID, LeasingType, Amount, StartDate, EndDate, Description)
VALUES (3, 'Property', 50000.00, '2023-02-10', '2026-02-10', '2-Bedroom Apartment in Downtown');

INSERT INTO Leasings (UserID, LeasingType, Amount, StartDate, EndDate, Description)
VALUES (4, 'Property', 70000.00, '2023-02-15', '2028-02-15', 'Commercial Space in Main Market');

INSERT INTO Leasings (UserID, LeasingType, Amount, StartDate, EndDate, Description)
VALUES (5, 'Car', 25000.00, '2023-02-20', '2026-02-20', 'Honda Civic 2023 Model');

INSERT INTO Leasings (UserID, LeasingType, Amount, StartDate, EndDate, Description)
VALUES (5, 'Bike', 4000.00, '2023-02-22', '2025-02-22', 'Yamaha YBR 2023 Model');
  -- Inserting into InvestmentSuggestions Table

INSERT INTO InvestmentSuggestions (UserID, SuggestionDate, Description, EstimatedReturn)
VALUES (1, '2023-02-05', 'Invest in Tech Startups in Silicon Valley', 15.0);

INSERT INTO InvestmentSuggestions (UserID, SuggestionDate, Description, EstimatedReturn)
VALUES (1, '2023-02-10', 'Buy Gold as the prices are expected to rise', 5.0);

INSERT INTO InvestmentSuggestions (UserID, SuggestionDate, Description, EstimatedReturn)
VALUES (2, '2023-02-07', 'Real Estate is booming in City X. Consider investing', 10.0);

INSERT INTO InvestmentSuggestions (UserID, SuggestionDate, Description, EstimatedReturn)
VALUES (3, '2023-02-15', 'Mutual Funds have shown consistent growth. Explore options', 7.0);

INSERT INTO InvestmentSuggestions (UserID, SuggestionDate, Description, EstimatedReturn)
VALUES (4, '2023-02-20', 'The stock market is favorable for blue-chip companies. Buy Stocks!', 8.0);

INSERT INTO InvestmentSuggestions (UserID, SuggestionDate, Description, EstimatedReturn)
VALUES (5, '2023-02-25', 'Bonds are a safe option with good returns. Invest in government bonds.', 6.0);



--Store Procedure


--User Table

--Insert
CREATE PROCEDURE sp_InsertUser
    @FirstName VARCHAR(50),
    @LastName VARCHAR(50),
    @PhoneNumber VARCHAR(15),
    @IDCardNumber VARCHAR(50),
    @DateOfBirth DATE,
    @Address VARCHAR(255),
    @UserID INT OUTPUT
AS
BEGIN
    INSERT INTO Users (FirstName, LastName, PhoneNumber, IDCardNumber, DateOfBirth, Address)
    VALUES (@FirstName, @LastName, @PhoneNumber, @IDCardNumber, @DateOfBirth, @Address);
    
    SET @UserID = SCOPE_IDENTITY();
END;

        

--Delete
CREATE PROCEDURE sp_DeleteUser
    @UserID INT
AS
BEGIN
    DELETE FROM Users WHERE UserID = @UserID;
END;


        
--Update
CREATE PROCEDURE sp_UpdateUser
    @UserID INT,
    @FirstName VARCHAR(50) = NULL,
    @LastName VARCHAR(50) = NULL,
    @PhoneNumber VARCHAR(15) = NULL,
    @IDCardNumber VARCHAR(50) = NULL,
    @DateOfBirth DATE = NULL,
    @Address VARCHAR(255) = NULL
AS
BEGIN
    UPDATE Users
    SET 
        FirstName = ISNULL(@FirstName, FirstName),
        LastName = ISNULL(@LastName, LastName),
        PhoneNumber = ISNULL(@PhoneNumber, PhoneNumber),
        IDCardNumber = ISNULL(@IDCardNumber, IDCardNumber),
        DateOfBirth = ISNULL(@DateOfBirth, DateOfBirth),
        Address = ISNULL(@Address, Address)
    WHERE UserID = @UserID;
END;



--Fetch
CREATE PROCEDURE sp_GetUser
    @UserID INT
AS
BEGIN
    SELECT * FROM Users WHERE UserID = @UserID;
END;




--Accounts Table

--Insert
CREATE PROCEDURE sp_InsertAccount
    @UserID INT,
    @Balance DECIMAL(18,2),
    @AccountID INT OUTPUT
AS
BEGIN
    INSERT INTO Accounts (UserID, Balance)
    VALUES (@UserID, @Balance);
    
    SET @AccountID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteAccount
    @AccountID INT
AS
BEGIN
    DELETE FROM Accounts WHERE AccountID = @AccountID;
END;



--Update
CREATE PROCEDURE sp_UpdateAccount
    @AccountID INT,
    @Balance DECIMAL(18,2)
AS
BEGIN
    UPDATE Accounts
    SET Balance = @Balance
    WHERE AccountID = @AccountID;
END;



--Fetch
CREATE PROCEDURE sp_GetAccount
    @AccountID INT
AS
BEGIN
    SELECT * FROM Accounts WHERE AccountID = @AccountID;
END;


--Transactions Table

        
--Insert
CREATE PROCEDURE sp_InsertTransaction
    @AccountID INT,
    @Amount DECIMAL(18,2),
    @Type VARCHAR(50),
    @TransactionID INT OUTPUT
AS
BEGIN
    INSERT INTO Transactions (AccountID, Amount, Type)
    VALUES (@AccountID, @Amount, @Type);
    
    SET @TransactionID = SCOPE_IDENTITY();
END;



        
--Delete
CREATE PROCEDURE sp_DeleteTransaction
    @TransactionID INT
AS
BEGIN
    DELETE FROM Transactions WHERE TransactionID = @TransactionID;
END;




--Update
CREATE PROCEDURE sp_UpdateTransaction
    @TransactionID INT,
    @Amount DECIMAL(18,2),
    @Type VARCHAR(50)
AS
BEGIN
    UPDATE Transactions
    SET 
        Amount = @Amount,
        Type = @Type
    WHERE TransactionID = @TransactionID;
END;



--Fetch
CREATE PROCEDURE sp_GetTransaction
    @TransactionID INT
AS
BEGIN
    SELECT * FROM Transactions WHERE TransactionID = @TransactionID;
END;



--BillPayment Table


--Insert
CREATE PROCEDURE sp_InsertBillPayment
    @AccountID INT,
    @BillType VARCHAR(50),
    @Amount DECIMAL(18,2),
    @Date DATETIME,
    @PaymentID INT OUTPUT
AS
BEGIN
    INSERT INTO BillPayments (AccountID, BillType, Amount, Date)
    VALUES (@AccountID, @BillType, @Amount, @Date);
    
    SET @PaymentID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteBillPayment
    @PaymentID INT
AS
BEGIN
    DELETE FROM BillPayments WHERE PaymentID = @PaymentID;
END;



--Update
CREATE PROCEDURE sp_UpdateBillPayment
    @PaymentID INT,
    @BillType VARCHAR(50) = NULL,
    @Amount DECIMAL(18,2) = NULL,
    @Date DATETIME = NULL
AS
BEGIN
    UPDATE BillPayments
    SET 
        BillType = ISNULL(@BillType, BillType),
        Amount = ISNULL(@Amount, Amount),
        Date = ISNULL(@Date, Date)
    WHERE PaymentID = @PaymentID;
END;



--Fetch
CREATE PROCEDURE sp_GetBillPayment
    @PaymentID INT
AS
BEGIN
    SELECT * FROM BillPayments WHERE PaymentID = @PaymentID;
END;


--Card Table


--Insert
CREATE PROCEDURE sp_InsertCard
    @UserID INT,
    @CardType VARCHAR(50),
    @CardNumber VARCHAR(20),
    @ExpiryDate DATE,
    @CardLimit DECIMAL(18,2),
    @CardID INT OUTPUT
AS
BEGIN
    INSERT INTO Cards (UserID, CardType, CardNumber, ExpiryDate, CardLimit)
    VALUES (@UserID, @CardType, @CardNumber, @ExpiryDate, @CardLimit);
    
    SET @CardID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteCard
    @CardID INT
AS
BEGIN
    DELETE FROM Cards WHERE CardID = @CardID;
END;



--Update
CREATE PROCEDURE sp_UpdateCard
    @CardID INT,
    @CardType VARCHAR(50) = NULL,
    @CardNumber VARCHAR(20) = NULL,
    @ExpiryDate DATE = NULL,
    @CardLimit DECIMAL(18,2) = NULL
AS
BEGIN
    UPDATE Cards
    SET 
        CardType = ISNULL(@CardType, CardType),
        CardNumber = ISNULL(@CardNumber, CardNumber),
        ExpiryDate = ISNULL(@ExpiryDate, ExpiryDate),
        CardLimit = ISNULL(@CardLimit, CardLimit)
    WHERE CardID = @CardID;
END;



--Fetch
CREATE PROCEDURE sp_GetCard
    @CardID INT
AS
BEGIN
    SELECT * FROM Cards WHERE CardID = @CardID;
END;


--Cheque Table


--Insert
CREATE PROCEDURE sp_InsertCheque
    @AccountID INT,
    @ChequeNumber VARCHAR(20),
    @Amount DECIMAL(18,2),
    @DateIssued DATETIME,
    @DateEncashed DATETIME,
    @Status VARCHAR(50),
    @ChequeID INT OUTPUT
AS
BEGIN
    INSERT INTO Cheques (AccountID, ChequeNumber, Amount, DateIssued, DateEncashed, Status)
    VALUES (@AccountID, @ChequeNumber, @Amount, @DateIssued, @DateEncashed, @Status);
    
    SET @ChequeID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteCheque
    @ChequeID INT
AS
BEGIN
    DELETE FROM Cheques WHERE ChequeID = @ChequeID;
END;



--Update
CREATE PROCEDURE sp_UpdateCheque
    @ChequeID INT,
    @ChequeNumber VARCHAR(20) = NULL,
    @Amount DECIMAL(18,2) = NULL,
    @DateIssued DATETIME = NULL,
    @DateEncashed DATETIME = NULL,
    @Status VARCHAR(50) = NULL
AS
BEGIN
    UPDATE Cheques
    SET 
        ChequeNumber = ISNULL(@ChequeNumber, ChequeNumber),
        Amount = ISNULL(@Amount, Amount),
        DateIssued = ISNULL(@DateIssued, DateIssued),
        DateEncashed = ISNULL(@DateEncashed, DateEncashed),
        Status = ISNULL(@Status, Status)
    WHERE ChequeID = @ChequeID;
END;



--Fetch
CREATE PROCEDURE sp_GetCheque
    @ChequeID INT
AS
BEGIN
    SELECT * FROM Cheques WHERE ChequeID = @ChequeID;
END;



--MoneyRequests Table


--Insert
CREATE PROCEDURE sp_InsertMoneyRequest
    @SenderUserID INT,
    @ReceiverAccount VARCHAR(20),
    @Amount DECIMAL(18,2),
    @DateRequested DATETIME,
    @RequestID INT OUTPUT
AS
BEGIN
    INSERT INTO MoneyRequests (SenderUserID, ReceiverAccount, Amount, DateRequested)
    VALUES (@SenderUserID, @ReceiverAccount, @Amount, @DateRequested);
    
    SET @RequestID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteMoneyRequest
    @RequestID INT
AS
BEGIN
    DELETE FROM MoneyRequests WHERE RequestID = @RequestID;
END;



--Update
CREATE PROCEDURE sp_UpdateMoneyRequest
    @RequestID INT,
    @SenderUserID INT = NULL,
    @ReceiverAccount VARCHAR(20) = NULL,
    @Amount DECIMAL(18,2) = NULL,
    @DateRequested DATETIME = NULL
AS
BEGIN
    UPDATE MoneyRequests
    SET 
        SenderUserID = ISNULL(@SenderUserID, SenderUserID),
        ReceiverAccount = ISNULL(@ReceiverAccount, ReceiverAccount),
        Amount = ISNULL(@Amount, Amount),
        DateRequested = ISNULL(@DateRequested, DateRequested)
    WHERE RequestID = @RequestID;
END;



--Fetch
CREATE PROCEDURE sp_GetMoneyRequest
    @RequestID INT
AS
BEGIN
    SELECT * FROM MoneyRequests WHERE RequestID = @RequestID;
END;



--Beneficiaries Table


--Insert
CREATE PROCEDURE sp_InsertBeneficiary
    @AccountID INT,
    @BeneficiaryAccount VARCHAR(20),
    @BeneficiaryID INT OUTPUT
AS
BEGIN
    INSERT INTO Beneficiaries (AccountID, BeneficiaryAccount)
    VALUES (@AccountID, @BeneficiaryAccount);
    
    SET @BeneficiaryID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteBeneficiary
    @BeneficiaryID INT
AS
BEGIN
    DELETE FROM Beneficiaries WHERE BeneficiaryID = @BeneficiaryID;
END;



--Update
CREATE PROCEDURE sp_UpdateBeneficiary
    @BeneficiaryID INT,
    @BeneficiaryAccount VARCHAR(20) = NULL
AS
BEGIN
    UPDATE Beneficiaries
    SET 
        BeneficiaryAccount = ISNULL(@BeneficiaryAccount, BeneficiaryAccount)
    WHERE BeneficiaryID = @BeneficiaryID;
END;



--Fetch
CREATE PROCEDURE sp_GetBeneficiary
    @BeneficiaryID INT
AS
BEGIN
    SELECT * FROM Beneficiaries WHERE BeneficiaryID = @BeneficiaryID;
END;



--OnlinePurchases Table


--Insert
CREATE PROCEDURE sp_InsertOnlinePurchase
    @AccountID INT,
    @Amount DECIMAL(18,2),
    @DateOfPurchase DATETIME,
    @CouponCode VARCHAR(20),
    @DiscountAmount DECIMAL(18,2),
    @PurchaseID INT OUTPUT
AS
BEGIN
    INSERT INTO OnlinePurchases (AccountID, Amount, DateOfPurchase, CouponCode, DiscountAmount)
    VALUES (@AccountID, @Amount, @DateOfPurchase, @CouponCode, @DiscountAmount);
    
    SET @PurchaseID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteOnlinePurchase
    @PurchaseID INT
AS
BEGIN
    DELETE FROM OnlinePurchases WHERE PurchaseID = @PurchaseID;
END;



--Update
CREATE PROCEDURE sp_UpdateOnlinePurchase
    @PurchaseID INT,
    @Amount DECIMAL(18,2) = NULL,
    @DateOfPurchase DATETIME = NULL,
    @CouponCode VARCHAR(20) = NULL,
    @DiscountAmount DECIMAL(18,2) = NULL
AS
BEGIN
    UPDATE OnlinePurchases
    SET 
        Amount = ISNULL(@Amount, Amount),
        DateOfPurchase = ISNULL(@DateOfPurchase, DateOfPurchase),
        CouponCode = ISNULL(@CouponCode, CouponCode),
        DiscountAmount = ISNULL(@DiscountAmount, DiscountAmount)
    WHERE PurchaseID = @PurchaseID;
END;



--Fetch
CREATE PROCEDURE sp_GetOnlinePurchase
    @PurchaseID INT
AS
BEGIN
    SELECT * FROM OnlinePurchases WHERE PurchaseID = @PurchaseID;
END;



--EducationPayments Table


--Insert
CREATE PROCEDURE sp_InsertEducationPayment
    @AccountID INT,
    @InstitutionName VARCHAR(100),
    @Amount DECIMAL(18,2),
    @DatePaid DATETIME,
    @PaymentID INT OUTPUT
AS
BEGIN
    INSERT INTO EducationPayments (AccountID, InstitutionName, Amount, DatePaid)
    VALUES (@AccountID, @InstitutionName, @Amount, @DatePaid);
    
    SET @PaymentID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteEducationPayment
    @PaymentID INT
AS
BEGIN
    DELETE FROM EducationPayments WHERE PaymentID = @PaymentID;
END;



--Update
CREATE PROCEDURE sp_UpdateEducationPayment
    @PaymentID INT,
    @InstitutionName VARCHAR(100) = NULL,
    @Amount DECIMAL(18,2) = NULL,
    @DatePaid DATETIME = NULL
AS
BEGIN
    UPDATE EducationPayments
    SET 
        InstitutionName = ISNULL(@InstitutionName, InstitutionName),
        Amount = ISNULL(@Amount, Amount),
        DatePaid = ISNULL(@DatePaid, DatePaid)
    WHERE PaymentID = @PaymentID;
END;



--Fetch
CREATE PROCEDURE sp_GetEducationPayment
    @PaymentID INT
AS
BEGIN
    SELECT * FROM EducationPayments WHERE PaymentID = @PaymentID;
END;



--Loans Table


--Insert
CREATE PROCEDURE sp_InsertLoan
    @UserID INT,
    @LoanAmount DECIMAL(18,2),
    @InterestRate DECIMAL(5,2),
    @StartDate DATETIME,
    @EndDate DATETIME,
    @LoanID INT OUTPUT
AS
BEGIN
    INSERT INTO Loans (UserID, LoanAmount, InterestRate, StartDate, EndDate)
    VALUES (@UserID, @LoanAmount, @InterestRate, @StartDate, @EndDate);
    
    SET @LoanID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteLoan
    @LoanID INT
AS
BEGIN
    DELETE FROM Loans WHERE LoanID = @LoanID;
END;



--Update
CREATE PROCEDURE sp_UpdateLoan
    @LoanID INT,
    @LoanAmount DECIMAL(18,2) = NULL,
    @InterestRate DECIMAL(5,2) = NULL,
    @StartDate DATETIME = NULL,
    @EndDate DATETIME = NULL
AS
BEGIN
    UPDATE Loans
    SET 
        LoanAmount = ISNULL(@LoanAmount, LoanAmount),
        InterestRate = ISNULL(@InterestRate, InterestRate),
        StartDate = ISNULL(@StartDate, StartDate),
        EndDate = ISNULL(@EndDate, EndDate)
    WHERE LoanID = @LoanID;
END;



--Fetch
CREATE PROCEDURE sp_GetLoan
    @LoanID INT
AS
BEGIN
    SELECT * FROM Loans WHERE LoanID = @LoanID;
END;



--Donations Table


--Insert
CREATE PROCEDURE sp_InsertDonation
    @AccountID INT,
    @CharityName VARCHAR(100),
    @Amount DECIMAL(18,2),
    @DateDonated DATETIME,
    @DonationID INT OUTPUT
AS
BEGIN
    INSERT INTO Donations (AccountID, CharityName, Amount, DateDonated)
    VALUES (@AccountID, @CharityName, @Amount, @DateDonated);
    
    SET @DonationID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteDonation
    @DonationID INT
AS
BEGIN
    DELETE FROM Donations WHERE DonationID = @DonationID;
END;



--Update
CREATE PROCEDURE sp_UpdateDonation
    @DonationID INT,
    @CharityName VARCHAR(100) = NULL,
    @Amount DECIMAL(18,2) = NULL,
    @DateDonated DATETIME = NULL
AS
BEGIN
    UPDATE Donations
    SET 
        CharityName = ISNULL(@CharityName, CharityName),
        Amount = ISNULL(@Amount, Amount),
        DateDonated = ISNULL(@DateDonated, DateDonated)
    WHERE DonationID = @DonationID;
END;



--Fetch
CREATE PROCEDURE sp_GetDonation
    @DonationID INT
AS
BEGIN
    SELECT * FROM Donations WHERE DonationID = @DonationID;
END;



--BudgetPlanner Table

--Insert
CREATE PROCEDURE sp_InsertBudgetPlanner
    @UserID INT,
    @MonthlyBudget DECIMAL(18,2),
    @AverageSpent DECIMAL(18,2),
    @Suggestions VARCHAR(500),
    @PlannerID INT OUTPUT
AS
BEGIN
    INSERT INTO BudgetPlanner (UserID, MonthlyBudget, AverageSpent, Suggestions)
    VALUES (@UserID, @MonthlyBudget, @AverageSpent, @Suggestions);
    
    SET @PlannerID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteBudgetPlanner
    @PlannerID INT
AS
BEGIN
    DELETE FROM BudgetPlanner WHERE PlannerID = @PlannerID;
END;



--Update
CREATE PROCEDURE sp_UpdateBudgetPlanner
    @PlannerID INT,
    @MonthlyBudget DECIMAL(18,2) = NULL,
    @AverageSpent DECIMAL(18,2) = NULL,
    @Suggestions VARCHAR(500) = NULL
AS
BEGIN
    UPDATE BudgetPlanner
    SET 
        MonthlyBudget = ISNULL(@MonthlyBudget, MonthlyBudget),
        AverageSpent = ISNULL(@AverageSpent, AverageSpent),
        Suggestions = ISNULL(@Suggestions, Suggestions)
    WHERE PlannerID = @PlannerID;
END;



--Fetch
CREATE PROCEDURE sp_GetBudgetPlanner
    @PlannerID INT
AS
BEGIN
    SELECT * FROM BudgetPlanner WHERE PlannerID = @PlannerID;
END;




--FamilyCards Table



--Insert
CREATE PROCEDURE sp_InsertFamilyCard
    @UserID INT,
    @ChildName VARCHAR(50),
    @ChildDOB DATE,
    @CardNumber VARCHAR(20),
    @FamilyCardID INT OUTPUT
AS
BEGIN
    INSERT INTO FamilyCards (UserID, ChildName, ChildDOB, CardNumber)
    VALUES (@UserID, @ChildName, @ChildDOB, @CardNumber);
    
    SET @FamilyCardID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteFamilyCard
    @FamilyCardID INT
AS
BEGIN
    DELETE FROM FamilyCards WHERE FamilyCardID = @FamilyCardID;
END;



--Update
CREATE PROCEDURE sp_UpdateFamilyCard
    @FamilyCardID INT,
    @ChildName VARCHAR(50) = NULL,
    @ChildDOB DATE = NULL,
    @CardNumber VARCHAR(20) = NULL
AS
BEGIN
    UPDATE FamilyCards
    SET 
        ChildName = ISNULL(@ChildName, ChildName),
        ChildDOB = ISNULL(@ChildDOB, ChildDOB),
        CardNumber = ISNULL(@CardNumber, CardNumber)
    WHERE FamilyCardID = @FamilyCardID;
END;



--Fetch
CREATE PROCEDURE sp_GetFamilyCard
    @FamilyCardID INT
AS
BEGIN
    SELECT * FROM FamilyCards WHERE FamilyCardID = @FamilyCardID;
END;


--TravelBookings Table


--Insert
CREATE PROCEDURE sp_InsertTravelBooking
    @AccountID INT,
    @ModeOfTravel VARCHAR(50),
    @TicketNumber VARCHAR(20),
    @Amount DECIMAL(18,2),
    @DateBooked DATETIME,
    @BookingID INT OUTPUT
AS
BEGIN
    INSERT INTO TravelBookings (AccountID, ModeOfTravel, TicketNumber, Amount, DateBooked)
    VALUES (@AccountID, @ModeOfTravel, @TicketNumber, @Amount, @DateBooked);
    
    SET @BookingID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteTravelBooking
    @BookingID INT
AS
BEGIN
    DELETE FROM TravelBookings WHERE BookingID = @BookingID;
END;



--Update
CREATE PROCEDURE sp_UpdateTravelBooking
    @BookingID INT,
    @ModeOfTravel VARCHAR(50) = NULL,
    @TicketNumber VARCHAR(20) = NULL,
    @Amount DECIMAL(18,2) = NULL,
    @DateBooked DATETIME = NULL
AS
BEGIN
    UPDATE TravelBookings
    SET 
        ModeOfTravel = ISNULL(@ModeOfTravel, ModeOfTravel),
        TicketNumber = ISNULL(@TicketNumber, TicketNumber),
        Amount = ISNULL(@Amount, Amount),
        DateBooked = ISNULL(@DateBooked, DateBooked)
    WHERE BookingID = @BookingID;
END;



--Fetch
CREATE PROCEDURE sp_GetTravelBooking
    @BookingID INT
AS
BEGIN
    SELECT * FROM TravelBookings WHERE BookingID = @BookingID;
END;


--Leasings Table

--Insert
CREATE PROCEDURE sp_InsertLeasing
    @UserID INT,
    @Product VARCHAR(100),
    @LeaseAmount DECIMAL(18,2),
    @StartDate DATETIME,
    @EndDate DATETIME,
    @LeaseID INT OUTPUT
AS
BEGIN
    INSERT INTO Leasings (UserID, Product, LeaseAmount, StartDate, EndDate)
    VALUES (@UserID, @Product, @LeaseAmount, @StartDate, @EndDate);
    
    SET @LeaseID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteLeasing
    @LeaseID INT
AS
BEGIN
    DELETE FROM Leasings WHERE LeaseID = @LeaseID;
END;



--Update
CREATE PROCEDURE sp_UpdateLeasing
    @LeaseID INT,
    @Product VARCHAR(100) = NULL,
    @LeaseAmount DECIMAL(18,2) = NULL,
    @StartDate DATETIME = NULL,
    @EndDate DATETIME = NULL
AS
BEGIN
    UPDATE Leasings
    SET 
        Product = ISNULL(@Product, Product),
        LeaseAmount = ISNULL(@LeaseAmount, LeaseAmount),
        StartDate = ISNULL(@StartDate, StartDate),
        EndDate = ISNULL(@EndDate, EndDate)
    WHERE LeaseID = @LeaseID;
END;



--Fetch
CREATE PROCEDURE sp_GetLeasing
    @LeaseID INT
AS
BEGIN
    SELECT * FROM Leasings WHERE LeaseID = @LeaseID;
END;



--InvestmentSuggestions Table


--Insert
CREATE PROCEDURE sp_InsertInvestmentSuggestion
    @UserID INT,
    @InvestmentType VARCHAR(100),
    @Amount DECIMAL(18,2),
    @DateSuggested DATETIME,
    @SuggestionID INT OUTPUT
AS
BEGIN
    INSERT INTO InvestmentSuggestions (UserID, InvestmentType, Amount, DateSuggested)
    VALUES (@UserID, @InvestmentType, @Amount, @DateSuggested);
    
    SET @SuggestionID = SCOPE_IDENTITY();
END;


        
--Delete
CREATE PROCEDURE sp_DeleteInvestmentSuggestion
    @SuggestionID INT
AS
BEGIN
    DELETE FROM InvestmentSuggestions WHERE SuggestionID = @SuggestionID;
END;



--Update
CREATE PROCEDURE sp_UpdateInvestmentSuggestion
    @SuggestionID INT,
    @InvestmentType VARCHAR(100) = NULL,
    @Amount DECIMAL(18,2) = NULL,
    @DateSuggested DATETIME = NULL
AS
BEGIN
    UPDATE InvestmentSuggestions
    SET 
        InvestmentType = ISNULL(@InvestmentType, InvestmentType),
        Amount = ISNULL(@Amount, Amount),
        DateSuggested = ISNULL(@DateSuggested, DateSuggested)
    WHERE SuggestionID = @SuggestionID;
END;



--Fetch
CREATE PROCEDURE sp_GetInvestmentSuggestion
    @SuggestionID INT
AS
BEGIN
    SELECT * FROM InvestmentSuggestions WHERE SuggestionID = @SuggestionID;
END;
