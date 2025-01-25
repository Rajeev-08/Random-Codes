import java.util.*;
public class Teo extends Exception
{
    static int ac[]={1001,1002,1003,1004};
    static String cu[]={"Customer1","Customer2","Customer3","Customer4"};
    static double ba[]={10000.0,12000.0,5600.0,999.0};
    Teo(String str){
super(str);
    }
    public static void main(String []args){
        try{
        System.out.println("ACCNO" + "\t" + "CUSTOMER" + "\t" +"BALANCE");
                for(int i=0;i<5;i++){
                    System.out.println(ac[i]+ "\t" +cu[i]+ "\t" +ba[i]);
                
                if(ba[i]<10000){
                   Teo t= new Teo("Balance is less than 10000");
                    throw t;
                }
            }
        }catch(Teo e){
            e.printStackTrace();
        }
   
   
    }
    
    
    
    
}