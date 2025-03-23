import java.util.*;
import java.io.*;

public class LeakyBucket{
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

        while(n!=0){
            System.out.println("incoming size "+incoming);
            if(incoming<=(bucketsize-store)){
                store+=incoming;
                System.out.println("Bucketbuffer size is "+store+" out of "+bucketsize);
            }else{
                
                System.out.println("packet loss: "+(incoming-(bucketsize-store)));
                System.out.println("Buffer is full");
                store=bucketsize;
            }
            store-=outgoing;
            System.out.println("after outgoing "+store +" packets are left out of "+bucketsize);
            n--;
            Thread.sleep(1000);

        }

    }
}
