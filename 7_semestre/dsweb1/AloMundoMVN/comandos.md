**Comandos Maven:**

- mvnw tomcat7:deploy
- mvnw tomcat7:redeploy <- automaticamente faz o deploy também, caso não exista
- mvnw tomcat7:undeploy

**Caso queira apenas gerar o .war (sem fazer deploy):**
- mvn package