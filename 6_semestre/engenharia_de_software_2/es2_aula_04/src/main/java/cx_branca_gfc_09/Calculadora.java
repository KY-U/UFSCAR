package cx_branca_gfc_09;

public class Calculadora {
    /**
     * @param n - inteiro
     * @param valorMaximo - valor maximo que pode ter o somatorio
     * @return - o somatorio de 0 ate |n|, caso somatorio seja <= valorMaximo
     * @throws Exception - caso o somatorio seja > valorMaximo
     */
    public int somatoriaLimitada(int n, int valorMaximo) throws Exception {
        /*1*/int resultado = 0, i = 0;
        /*2*/if(n < 0) {
            /*3*/n = -n;
        }

        while(/*4*/i<=n && /*5*/resultado <= valorMaximo) {
            /*6*/resultado = resultado + i;
            /*6*/i++;
        }

        /*7*/if(resultado > valorMaximo)
            /*8*/throw new Exception("valor maximo foi ultrapassado");
        else
            /*9*/return resultado;
    }
}
