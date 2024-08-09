#Compilando:
#Este comando indica que o compilador deve procurar as classes do pacote javax.servlet.http no arquivo servlet-api.jar
#Depois, indica que o arquivo .java está no diretório src/br/ufscar/dc/dsw e que o arquivo .class deve ser gerado no 
#diretório dist/WEB-INF/classes
javac -cp /home/caio/software/apache-tomcat-9.0.88/lib/servlet-api.jar src/br/ufscar/dc/dsw/AloMundoServlet.java -d dist/WEB-INF/classes/

#Empacotando:
#O comando cria um arquivo WAR, incluindo todos os arquivos e diretórios do diretório dist. Este arquivo WAR contém uma 
#aplicação web Java pronta para ser implantada em um servidor de aplicação compatível com Java EE, no caso, Apache Tomcat.
jar -cvf AloMundo.war -C dist .