#Programa que imprime a primeira linha em que certa palavra apareceu em um texto

#Baixando o texto
import os
os.system("[ -f pg5710.txt ] || wget https://www.gutenberg.org/cache/epub/5710/pg5710.txt")
os.system("ls -l pg5710.txt")

#Abrindo o arquivo e procurando a linha contendo aa palavra
try:
  arquivo_texto = open("pg5710.txt")
except IOError as excecao:
  print(f"Erro de acesso: {excecao}")
else:
  acabou_o_arquivo = False
  achou = False
  while (not acabou_o_arquivo and not achou):
    uma_linha = arquivo_texto.readline()    # uma única linha
    palavras_total = uma_linha.split()      #lista com cada palavra da linha
    for palavra in palavras_total:
      if (palavra == "lengthened"):
        achou = True
    acabou_o_arquivo = not uma_linha
  #após buscar a palavra
  print()
  if achou:  
    print(uma_linha)
  else:
      print("Palavra não encontrada")
  arquivo_texto.close()