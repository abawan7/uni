<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Register.aspx.cs" Inherits="WebApplication1.Register" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Instagram - Create an Account</title>
    <style>
        body {
            font-family: 'Arial', sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
        }
        .container {
            width: 80%;
            margin: auto;
            overflow: hidden;
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 5px rgba(0,0,0,0.1);
            margin-top: 50px;
        }
        .header-logo {
            display: block;
            margin: 20px auto;
        }
        .form-group {
            margin-bottom: 15px;
        }
        .form-group label {
            display: block;
            margin-bottom: 5px;
        }
        .form-group input[type="text"],
        .form-group input[type="password"],
        .form-group select {
            width: 100%;
            padding: 10px;
            border: 1px solid #ddd;
            border-radius: 4px;
            box-sizing: border-box;
        }
        .form-group input[type="submit"] {
            width: 100%;
            padding: 10px;
            background-color: #5C6DF8;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }
        .form-group input[type="submit"]:hover {
            background-color: #475ae0;
        }
        .form-group input[type="radio"] {
            margin-right: 5px;
        }
        .gender-label {
            display: inline-block;
            margin-right: 15px;
        }
        #enableprivacy {
            margin-right: 5px;
        }
    </style>
</head>
<body>
   <div class="container">
        <img style="height: 70px" class="header-logo" src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2a/Instagram_logo.svg/2560px-Instagram_logo.svg.png" alt="Instagram Logo" runat="server"/>
        <h3><b>Create an account</b></h3>
        <form id="form1" runat="server">
            <div class="form-group">
                <asp:Label for="fname" runat="server">First Name:</asp:Label>
                <asp:TextBox ID="fname" CssClass="form-control" placeholder="Firstname" runat="server"/>
            </div>
            <div class="form-group">
                <asp:Label for="lname" runat="server">Last Name:</asp:Label>
                <asp:TextBox ID="lname" CssClass="form-control" placeholder="Lastname" runat="server"/>
            </div>
            <div class="form-group">
                <asp:Label for="username" runat="server">User Name:</asp:Label>
                <asp:TextBox ID="username" CssClass="form-control" placeholder="Username" runat="server"/>
            </div>
            <div class="form-group">
                <asp:Label for="password" runat="server">Password:</asp:Label>
                <asp:TextBox ID="password" TextMode="Password" CssClass="form-control" placeholder="Password" runat="server" />
            </div>
            <div class="form-group">
                <asp:Label runat="server">Date of Birth:</asp:Label>
                <asp:Calendar ID="calendar1" runat="server"></asp:Calendar>
            </div>
            <div class="form-group">
                <asp:Label for="country" runat="server">Country:</asp:Label>
                <asp:DropDownList ID="country" runat="server">
                    <asp:ListItem Value="select">Select</asp:ListItem>
                    <asp:ListItem Value="pakistan">Pakistan</asp:ListItem>
                    <asp:ListItem Value="india">India</asp:ListItem>
                    <asp:ListItem Value="usa">USA</asp:ListItem>
                </asp:DropDownList>
            </div>
            <div class="form-group">
                <asp:Label runat="server">Gender:</asp:Label>
                <label class="gender-label">
                    <asp:RadioButton ID="male" GroupName="gender" Text="Male" runat="server"/>
                </label>
                <label class="gender-label">
                    <asp:RadioButton ID="female" GroupName="gender" Text="Female" runat="server"/>
                </label>
            </div>
            <div class="form-group">
                <asp:CheckBox ID="enableprivacy" runat="server" />
                <asp:Label for="enableprivacy" runat="server">Enable Privacy</asp:Label>
            </div>
            <div class="form-group">
                <asp:Button ID="createAccount" Text="Create Account" runat="server" />
            </div>
        </form>
   </div>
</body>
</html>
