<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="lab08.aspx.cs" Inherits="WebApplication1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Instagram</title>
</head>
<body>
   <div>
        <asp:Image width="150" height="100" src="https://www.edigitalagency.com.au/wp-content/uploads/first-Instagram-logo-png.png" runat="server"/>
        <asp:Image width="250" height="100" src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2a/Instagram_logo.svg/2560px-Instagram_logo.svg.png" runat="server"/>
        <h3><b>Create an account</b></h3>
        <form action="/contact.html" runat="server">
        <asp:label for="fname" runat="server">First Name: </asp:label>
        <input type="text" placeholder="Firstname" runat="server"/>
        <asp:label for="lname" runat="server">Last Name: </asp:label>
        <input type="text" placeholder="Lastname"/>
        <div>
            <br/>
            <asp:label for="username" runat="server">User Name: </asp:label>
            <input type="text" placeholder="Username"/>
        </div>
        <div>
            <br/>
            <asp:label for="password" runat="server">Password: </asp:label>
            <input type="text" placeholder="Password" maxlength="8" minlength="6"/>
        </div>
            <p>Date of Birth: </p>
            <asp:Calendar ID="calendar1" runat="server"></asp:Calendar>
            <br />
            <br />
            <div>
                 <asp:Label for="country" runat="server">Country</asp:Label>
                <select name="type" id="type">
                    <option value="select">Select</option>
                    <option value="pakistan">Pakistan</option>
                    <option value="india">India</option>
                    <option value="USA">USA</option>
                </select>
                <br />
            </div>
            <br />
            <div>
                <asp:Label for="gender" runat="server">Gender</asp:Label>
                <input type="radio" name="gender" value="male" />Male
                <input type="radio" name="gender" value="Female" />Female

            </div>
            <br />
           <div>
               <input type="checkbox" id="enableprivacy" name="enableprivacy" value="enableprivacy" />
               <asp:label for="privacy" runat="server">Enable Privacy</asp:label>
           </div>
           <br />
            <div>
                <asp:label for="creataccount" runat="server"></asp:label>
                <input type="submit" value="Create Account" />
            </div>
            </form>

   </div>
</body>
</html>
