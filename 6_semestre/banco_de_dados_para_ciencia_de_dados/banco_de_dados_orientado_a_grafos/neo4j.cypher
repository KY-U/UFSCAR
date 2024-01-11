//criando as pessoas
CREATE (p:Pessoa{Name:"Lucas",Idade:20,Local:"Varginha"});
CREATE (p:Pessoa{Name:"Caio",Idade:21,Local:"São Paulo"});
CREATE (p:Pessoa{Name:"Bob Esponja",Idade:37,Local:"Fenda do Biquini"});
CREATE (p:Pessoa{Name:"Naruto",Idade:33,Local:"Konoha"});
CREATE (p:Pessoa{Name:"Jesus",Idade:30,Local:"Belém"});

//garantindo que cada nome é único
CREATE CONSTRAINT FOR (p:Pessoa) REQUIRE p.Name IS UNIQUE;

//criando relações de seguidores
MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Lucas') AND (m.Name='Jesus')
CREATE(n)-[s:SEGUE{Data:'18-03-2003'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Caio') AND (m.Name='Jesus')
CREATE(n)-[s:SEGUE{Data:'27-05-2002'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Bob Esponja') AND (m.Name='Jesus')
CREATE(n)-[s:SEGUE{Data:'01-05-1999'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Naruto') AND (m.Name='Jesus')
CREATE(n)-[s:SEGUE{Data:'21-09-1999'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Lucas') AND (m.Name='Naruto')
CREATE(n)-[s:SEGUE{Data:'21-09-2011'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Caio') AND (m.Name='Naruto')
CREATE(n)-[s:SEGUE{Data:'23-07-2010'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Lucas') AND (m.Name='Bob Esponja')
CREATE(n)-[s:SEGUE{Data:'01-05-2009'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Caio') AND (m.Name='Bob Esponja')
CREATE(n)-[s:SEGUE{Data:'01-05-2008'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Naruto') AND (m.Name='Lucas')
CREATE(n)-[s:SEGUE{Data:'20-03-2003'}]->(m);

MATCH(n:Pessoa), (m:Pessoa)
WHERE(n.Name='Bob Esponja') AND (m.Name='Caio')
CREATE(n)-[s:SEGUE{Data:'28-05-2002'}]->(m);

//criando mensagens
//mensagens postadas
MATCH(n:Pessoa)
WHERE(n.Name='Jesus')
CREATE(m:Mensagem{txt:'Ame o seu próximo como a si mesmo', Data:'04-02-2000'})
CREATE(n)-[:POSTOU]->(m);

MATCH(n:Pessoa)
WHERE(n.Name='Caio')
CREATE(m:Mensagem{txt:'Eu simplesmente AMO Jesus Cristo de Nazaré', Data:'05-02-1969'})
CREATE(n)-[:POSTOU]->(m);

//mensagens respondidas
MATCH(n:Pessoa), (m:Mensagem)
WHERE(n.Name='Bob Esponja') AND (m.txt='Ame o seu próximo como a si mesmo')
CREATE(n)-[r:RESPONDEU{txt:"HEHEHEHEHEHEHE", Data:'04-02-2000'}]->(m);

//mensagens propagadas
MATCH(n:Pessoa), (m:Mensagem)
WHERE(n.Name='Lucas') AND (m.txt='Eu simplesmente AMO Jesus Cristo de Nazaré')
CREATE(n)-[p:PROPAGOU{Data:'10-05-2005'}]->(m);

MATCH(n:Pessoa), (m:Mensagem)
WHERE(n.Name='Naruto') AND (m.txt='Eu simplesmente AMO Jesus Cristo de Nazaré')
CREATE(n)-[p:PROPAGOU{Data:'11-06-2004'}]->(m);

QUESTÕES:
//1- QUESTAO: Recupere o conjunto de seguidores de uma pessoa.
MATCH (seguidor:Pessoa)-[:SEGUE]->(p:Pessoa {Name: 'Jesus'})
RETURN seguidor;

//2- QUESTAO: Recupere o conjunto de seguidos de uma pessoa.
MATCH (p:Pessoa {Name: 'Bob Esponja'})-[:SEGUE]->(seguido:Pessoa)
RETURN seguido;

//3- QUESTAO: Apresente o conjunto de pessoas em comum entre 2 pessoas.
MATCH(comum:Pessoa)
WHERE (:Pessoa {Name: 'Caio'})-[:SEGUE]->(comum:Pessoa) AND (:Pessoa {Name: 'Naruto'})-[:SEGUE]->(comum:Pessoa)
RETURN comum;

//4- QUESTAO: Recupere o conjunto de mensagens produzidas por uma pessoa.
MATCH (p:Pessoa {Name: 'Jesus'})-[:POSTOU]->(m:Mensagem)
RETURN m;

//5- QUESTAO :Recupere o conjunto de mensagens respondidas de uma determinada mensagem.
MATCH(m:Mensagem)
WHERE(m.txt='Ame o seu próximo como a si mesmo')
MATCH (p:Pessoa)-[r:RESPONDEU]->(m:Mensagem)
RETURN r.txt;

//6- QUESTAO: Recupere o conjunto de mensagens que foram retransmitidas (propagadas).
MATCH (p:Pessoa)-[:PROPAGOU]->(m:Mensagem)
RETURN m