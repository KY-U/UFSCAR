# Criação de um arquivo binário com 20 inteiros
from random import seed
from random import randint
seed()
try:
  arquivo_binario = open("arquivo_binario_20_int.dat", "wb")  # w cria; b é binário
except IOError as excecao:
  print(f"Erro de acesso: {excecao}")
else:
  # Escrevendo 20 inteiros
  int_bytes_total = []
  for i in range(20):
   num = randint(0,100)
   int_bytes = num.to_bytes(8, "big")  # conversão para 8 bytes, big-endian
   arquivo_binario.write(int_bytes)  # gravação dos bytes no arquivo
   int_bytes_total.append(int_bytes) 
  print(f"Escritos {len(int_bytes_total) * 8} bytes: {int_bytes_total}")

  arquivo_binario.close()