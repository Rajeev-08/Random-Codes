import java.util.*;
public class Sort
{
    public static void main(String[]args){
        Scanner s=new Scanner(System.in);
        Integer[]a=new Integer[5];
        System.out.println("Enter 5 elements :");
        for(int i=0;i<5;i++){
            a[i]=s.nextInt();
        }
        Arrays.sort(a);
        System.out.println("Sorted Array in Accending order : "+Arrays.toString(a));
        Arrays.sort (a,Comparator.reverseOrder());
                System.out.println("Sorted Array in deccending order : "+Arrays.toString(a));

}
}