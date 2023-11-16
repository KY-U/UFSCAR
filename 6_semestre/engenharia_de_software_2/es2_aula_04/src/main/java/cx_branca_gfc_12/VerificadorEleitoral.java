package cx_branca_gfc_12;

public class VerificadorEleitoral {
    private CartorioEleitoral cartorioEleitoral;
    public VerificadorEleitoral(CartorioEleitoral cartorioEleitoral) {
        this.cartorioEleitoral = cartorioEleitoral;
    }

    public String consultarSituacao(int idade, String cpf) throws Exception {
        if(/*1*/idade < 0 || /*2*/idade > 200)
            /*3*/throw new Exception("idade invalida");

        if(/*4*/cpf == null || /*5*/cpf.length() != 11)
            /*6*/throw new Exception("cpf invalido");

        /*7*/if(idade < 16)
            /*8*/return "nao pode votar";

        /*9*/String status = cartorioEleitoral.verificar(cpf);
        /*10*/if(status.equals("nao existe"))
            /*11*/return "faca um titulo";
            /*12*/else if(status.equals("pendencia"))
                /*13*/return "regularize seu titulo";
            /*14*/else if(status.equals("OK")) {
                /*15*/String ret = "voto obrigatorio";
                if(/*16*/idade <= 17 || /*17*/idade > 70)
                    /*18*/ret = "voto facultativo";

            /*19*/return ret;
        }
        /*20*/return "erro desconhecido";
    }
}
