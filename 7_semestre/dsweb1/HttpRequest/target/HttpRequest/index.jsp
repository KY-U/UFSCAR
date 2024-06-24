<html>
<body>
    <a href="InterpretarRequestServlet?a=123&b=123">Testa</a><br/>
    <p></p>
    <form name="teste" action="InterpretarRequestServlet">
        <fieldset>
        <legend>Formulário de Envio</legend>
        Nome: <input type="text" name="nome" /> <br/>
        E-mail: <input type="text" name="email" /> <br/>
        Confirmação de e-mail: <input type="text" name="email" /> <br/>
        Senha: <input type="password" name="senha" /><br/>
        Gênero: <input type="radio" name="genero" value="Masculino" /> Masculino
        <input type="radio" name="genero" value="Feminino" /> Feminino <br/>
        Receber notícias: <input type="checkbox" name="receber" value="ok" /><br/>
        <input type="submit" name="enviar" value="Enviar" />
        </fieldset>
</body>
</html>
