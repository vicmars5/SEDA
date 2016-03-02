
package fechavalida;

/**
 *
 * Autor: UnoCuatro
 */
public class Fecha {
    
    private int codigoErrorFecha;
    
    public boolean esFecha(int dia, int mes, int anio) {
        if ((((mes == 4 || mes==6 || mes==9 || mes==11) && dia<=30)
            || ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && dia<=31)
            || (((anio % 4) != 0) && dia <=28 && mes==2)
            || ((anio % 4) == 0 && dia<=29 && mes==2))
            && dia > 0) {
            codigoErrorFecha = 0;
            return true;
        }

        if(mes<1 || mes >12) {
            codigoErrorFecha = -1;
            return false;
        }
        codigoErrorFecha = -2;
        return false;
    }
    
    public int dameCodigoErrorFecha(){
        return codigoErrorFecha;
    }
}

