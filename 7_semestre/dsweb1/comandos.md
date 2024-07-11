#### Comandos Maven:

**Criar Projeto:**
- mvn archetype:generate -DarchetypeGroupId=org.apache.maven.archetypes -DarchetypeArtifactId=maven-archetype-webapp -DarchetypeVersion=1.4
- **groupId:** br.ufscar.dc.dsw
- **artifactId:** NomeDoProjeto

**Wrapper**
- mvn -N io.takari:maven:wrapper

**Deploy:**
- mvn tomcat7:deploy
- mvn tomcat7:redeploy <- automaticamente faz o deploy também, caso não exista
- mvn tomcat7:undeploy

**Caso queira apenas gerar o .war (sem fazer deploy):**
- mvn package