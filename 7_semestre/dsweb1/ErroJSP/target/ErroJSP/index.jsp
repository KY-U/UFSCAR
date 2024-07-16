<%-- Caso digite errado, gerará erro de diretiva --%>
<%@ page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>

<%--caso a = null resultará em erro--%>
<body>
    <h2>Hello World!</h2>

    <% int a = 2;
    String str = "não pode ser null";
    a = str.length();
    %>
</body>

</html>