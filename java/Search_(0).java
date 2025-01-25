
abstract class Dummy {
   protected int[] dataArray; 

   public Dummy(int[] dataArray) {
        this.dataArray = dataArray;
    }
    abstract int search(int target);

}
class Linear extends Dummy{
    public Linear(int []dataArray){
        super(dataArray);
    }
    int  search(int target){
        for(int i=0;i<dataArray.length;i++){
            if(dataArray[i]==target){
                return i;
            }
        }
        return -1;
    }
}
class Binary extends Dummy{
    int l=0,h=dataArray.length-1;
    public Binary(int []dataArray){
        super(dataArray);
    }
    int search(int target){
        while (l<=h){
            int mid=(l+h)/2;
            if(dataArray[mid]==target){
                return mid;
            }else if(dataArray[mid]<target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return -1;
    }
}
class Search{
    public static void main(String[] args) {
        int dataArray[]={2,4,5,6,7,9,10,12};
        Dummy obj1=new Linear(dataArray);
        Dummy obj2=new Binary(dataArray);
        int l=obj1.search(7);
        int b=obj1.search(7);
        System.out.println("linear search : "+l);
        System.out.println("Binary search : "+b);
    }
}