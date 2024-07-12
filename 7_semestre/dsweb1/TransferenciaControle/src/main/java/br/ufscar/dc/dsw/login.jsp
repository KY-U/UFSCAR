<%@ page contentType="text/html" pageEncoding="UTF-8"%>
<%
	String usuario = request.getParameter("usuario");
	String senha = request.getParameter("senha");
	if(usuario.equalsIgnoreCase(senha)) {
%>
		<jsp:forward page="sucesso.jsp">
    		<jsp:param name="nomeCompleto" value="Fulano da Silva" />
    		<jsp:param name="ultimoAcesso" value="29/03/2019" />
		</jsp:forward>
<% } else { %>
		<jsp:forward page="index.jsp" />
<% } %>