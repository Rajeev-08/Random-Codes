
import java.util.*;
public class Sor{
    public static void main(String[]args){
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=s.nextInt();
        Integer[]a=new Integer[n];
        System.out.println("Enter the elements of array: ");
        for(int i=0;i<n;i++){
             a[i]=s.nextInt();
        }
     
      Arrays.sort(a);
      System.out.println("sorted array in Assending order :"+Arrays.toString(a));
      Arrays.sort(a,Comparator.reverseOrder());
            System.out.println("sorted array in Dessending order :"+Arrays.toString(a));
    
    }
}