#### Comandos Maven:

**Criar Projeto:**
- mvn archetype:generate -DarchetypeGroupId=org.apache.maven.archetypes -DarchetypeArtifactId=maven-archetype-webapp -DarchetypeVersion=1.4
- **groupId:** br.ufscar.dc.dsw
- **artifactId:** NomeDoProjeto

**Wrapper:**
- mvn -N io.takari:maven:wrapper

**Adicionar Dependências:**

```
<dependency>
    <groupId>javax.servlet</groupId>
    <artifactId>javax.servlet-api</artifactId>
    <version>4.0.0</version>
    <scope>provided</scope>
</dependency>
<dependency>
    <groupId>javax.servlet.jsp</groupId>
    <artifactId>jsp-api</artifactId>
    <version>2.1</version>
    <scope>provided</scope>
</dependency>

<!-- JSTL -->
<dependency>
    <groupId>javax.servlet</groupId>
    <artifactId>jstl</artifactId>
    <version>1.2</version>
    <scope>runtime</scope>
</dependency>
...


<plugin>
    <groupId>org.apache.tomcat.maven</groupId>
    <artifactId>tomcat7-maven-plugin</artifactId>
    <version>2.2</version>
    <configuration>
        <url>http://localhost:8080/manager/text</url>
        <server>TomcatServer</server>
        <path>/${project.artifactId}</path>
    </configuration>
</plugin>

<!--Native2Ascii-->
<plugin>
	<groupId>org.codehaus.mojo</groupId>
	<artifactId>native2ascii-maven-plugin</artifactId>
	<version>1.0-beta-1</version>
	<executions>
		<execution>
			<id>native2ascii-utf8-resources</id>
			<goals>
				<goal>native2ascii</goal>
			</goals>
			<configuration>
				<dest>${project.build.directory}/classes</dest>
				<src>${project.resources[0].directory}</src>
				<encoding>UTF-8</encoding>
			</configuration>
		</execution>
	</executions>
</plugin>
```

**Deploy:**
- mvn tomcat7:deploy
- mvn tomcat7:redeploy <- automaticamente faz o deploy também, caso não exista
- mvn tomcat7:undeploy

**Caso queira apenas gerar o .war (sem fazer deploy):**
- mvn package