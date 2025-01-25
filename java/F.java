import java.io.*;
import java.util.Scanner;

public class F {

    static int count(BufferedReader br){
        int c=0;
        String sc;
        try{
        while((sc=br.readLine())!=null){
            String array[]=sc.split("\\s+");
            c+=array.length;

                }
                br.close();
            }catch(Exception e){
                System.out.println(e);
            }
                return c;
    }
    public static void main(String[] args) {
        try{
            Scanner sc=new Scanner(System.in);
           
            FileReader fr=new FileReader("n.txt");
            BufferedReader br= new BufferedReader(fr);
            String s;
            int size=count(br);
           String[]str=new String[size];
           int i=0;
           br = new BufferedReader(new FileReader("n.txt")); 
            
            while((s=br.readLine())!=null){
                String []ar=s.split(" ");
                for(String word:ar){
                    str[i]=word;
                    i++;
                }

            }
            
            for(String j:str){
                System.out.print(j+" ");

            }
           fr.close();
           br.close();

        }catch(Exception e){
            System.out.println(e);
        }
    }
    
}
