import math
from decimal import Decimal, getcontext

#4 algarismos significativos
getcontext().prec = 4

def GaussJord(M):
    #verifica dimensão da matriz
    nLin = len(M)
    nCol = len(M[0])
    if nCol != nLin + 1:
        return 'dimensão da matriz imcompatível'
    else:
        #inicialização das variáveis
        MM = []
        xx = []
        for i in range(nLin):
            xx.append(0)
            linha = []
            for j in range(nCol):
                linha.append(M[i][j])
            MM.append(linha)
        #início do escalonamento
        for i in range(nLin):
            #encontrando o pivô na coluna da linha atual
            pivo = i
            for j in range(i+1, nLin):
                if abs(MM[pivo][i]) < abs(MM[j][i]):
                    pivo = j
            #trocando a linha do pivo
            MM[i], MM[pivo] = MM[pivo], MM[i]
            #anulando os elementos abaixo do pivô
            for j in range(i+1, nLin):
                MM[j][i] = MM[j][i] / MM[i][i]
                for k in range(i+1, nCol):
                    MM[j][k] -= MM[j][i] * MM[i][k]
        #fim do escalonamento
        #calculando a solução
        for i in range(nLin-1, -1, -1):
            xx[i] = MM[i][nCol-1]
            for j in range(nLin-1, i, -1):
                xx[i] -= MM[i][j] * xx[j]
            xx[i] /= MM[i][i]
        return xx
#fim GaussJord
A = [[-2.714, -9,	2.286, 9.286, 14, 14.14, 5.143,	-7, -11.29, -9.857],
	[6.571,	-2,	4.857, -1.143, -3.429, -0.7143, -3.857,	12.86, 5.143, 5.143],
	[13.14,	-5.429,	3.143, 10,	-11.14,	-10, 13.57, -13.71,	-13.71, -16.43],
	[5.429,	-8.857,	12.71, 14.14, -10, -11, 4.143, -6.714, 12.86, -21.71],
	[-0.8571, 12, -8.857, -7.857, -11.71, 13.86, -2.714, 4, -9.286, 26],
	[-8, -6, -13.29, -2.286, 4.143, -0.5714, 11.71, -6.429, 1.286, 15.14],
	[14.29,	-2.714,	-8.714,	-3.286,	-10.29,	5, 4.286, -8.286, 8.714, 9.571],
	[11.14,	12.14, -14.14, -0.5714, -2.429,	-2.429,	-10.14,	-4.143,	-11.43, 26.86],
	[-0.4286, 8.571, -8.571, 13.86, -5.286,	-1.857,	-6.857,	-4.286,	12.71, 12.86]]

for i in range(len(A)):
    for j in range(len(A[0])):
        A[i][j] = Decimal(A[i][j])

R = GaussJord(A)
for i in range(len(R)):
	A[i][j] = str(A[i][j])
print(R)
