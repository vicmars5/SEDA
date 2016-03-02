package fechavalida;

/**
 *
 * Autor UnoCuatro
 */
public class FechaValida {

    public static void main(String[] args) {

        System.out.println("VERIFICADOR DE FECHA V1.0\n");
        
        prueba(12, 9, 1979);
        prueba(0, 1, 2011);
        prueba(1, 13, 2011);
        prueba(12, -1, 2011);
        prueba(31, 4, 2011);
        prueba(29, 2, 2011);
        prueba(29, 2, 2016);
        prueba(28, 2, 2011);
        prueba(21, 3, -34);
        prueba(0, 0, 0);
        prueba(14, 2, 2016);
    }
    
    public static void prueba(int dia, int mes, int anio){
        Fecha f;
        f = new Fecha();

        System.out.println("Dame el dia: " + dia);
        System.out.println("Dame el mes: " + mes);
        System.out.println("Dame el año: " + anio);

        if(f.esFecha(dia, mes, anio)){
            System.out.println("Fecha valida!\n");
        }
        else {
            switch(f.dameCodigoErrorFecha()){
                case -1:
                    System.out.println("Mes no valido! \n");
                    break;
                case -2:
                    System.out.println("Dia no valido! \n");
                    break;
            }
        }

        System.out.println("Presione ENTRAR para continuar... \n");
        ScanF.get();
    }
}
