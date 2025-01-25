public class Sample {
    private int[]numbers;
    public Sample(int[]numbers){
        this.numbers=numbers;
    }
   static void sort(int []a){
    int n=a.length,temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    System.out.println("sorted array");
    for(int i=0;i<n;i++){
        System.out.print(a[i]+" ");
    }

   }
   public static void main(String[] args) {
    int []a={3,6,1,8,9,4,10,34,5};
    Sample o=new Sample(a);
    sort(a);
;   }




}
