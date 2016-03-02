package fechavalida;

/**
 *
 * Autor: UnoCuatro
 */
public class Fecha {
    
    private int codigoErrorFecha;
    
    public boolean esFecha(int dia, int mes, int anio) {
        if(dia > 0){
            switch(mes) {
                case 4:
                case 6:
                case 9:
                case 11:
                    if(dia<=30){
                        codigoErrorFecha=0;
                        return true;
                    }
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if(dia<=31){
                        codigoErrorFecha=0;
                        return true;
                    }
                    break;
                case 2:
                    if ((anio%4)!=0 && dia<=28){
                        codigoErrorFecha=0;
                        return true;
                    }
                    if ((anio%4)==0 && dia<=29){
                        codigoErrorFecha=0;
                        return true;
                    }
                    break;
                default:
                    codigoErrorFecha=-1;
                    return false;
            }
        }
        codigoErrorFecha=-2;
        return false;
    }
    
    public int dameCodigoErrorFecha(){
        return codigoErrorFecha;
    }
}

