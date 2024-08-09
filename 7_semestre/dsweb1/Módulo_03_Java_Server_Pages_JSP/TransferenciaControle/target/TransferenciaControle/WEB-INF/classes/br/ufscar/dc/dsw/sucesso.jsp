<%@ page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <% String voceEstaEm = "AT9 - Sala 197"; %>
        
        <%-- Permite que a página incluída acesse variáveis da página que a incluiu --%>
        <%@include file="cabecalho.jsp" %>
        
        Menu de opções:<br/><br/>
        Conteúdo da página<br/>
        Conteúdo da página<br/>
        Conteúdo da página<br/>
        
        <jsp:include page="rodape.jsp"/>
    </body>
</html>