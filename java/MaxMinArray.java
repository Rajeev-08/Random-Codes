//Q4

import java.util.*;
public class MaxMin {
    public static void main(String[]args)
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        int n=s.nextInt();
        int a[]=new int[n];
        System.out.println("enter the elements of the array : ");
        for(int i=0;i<n;i++){
            a[i]=s.nextInt();
        }
        s.close();
        Arrays.sort(a);
        int min=a[1]-a[0];
                        System.out.println("min value pairs : (" +a[0]+","+a[1]+")");

                System.out.println("min value : "+min);



        

    }
    
}
