import java.util.*;
import java.io.*;

public class Leaky{
    public static void main(String[]args) throws Exception{
        int n,incoming,outgoing,store=0,bucketsize;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the no.of input:");
        n=sc.nextInt();
        System.out.println("enter the bucket size :");
        bucketsize=sc.nextInt();
        System.out.println("enetr the outgoing rate :");
        outgoing=sc.nextInt();
        System.out.println("Enter the incoming rate :");
        incoming=sc.nextInt();

        while(n>0){
            System.out.println("incoming size "+incoming);
            if(incoming<=(bucketsize-store)){
                store+=incoming;
                System.out.println(store+" full out of "+bucketsize);
            }else{
                
                System.out.println("bucket is full and "+(incoming-(bucketsize-store))+"are overflowed");
                store=bucketsize;
            }
            store-=outgoing;
            System.out.println("after outgoing"+store +"is available in "+bucketsize);
            n--;
            Thread.sleep(1000);

        }


    }
}
