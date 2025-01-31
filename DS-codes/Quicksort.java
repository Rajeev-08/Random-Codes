class A{

static int partition(int a[],int l,int r){
    int pivot=a[l];
    int  start=l;
    int end=r;
    int temp;
    while(start<end){
        while(start<r&&a[start]<=pivot){
            start++;
        }
        while(end>l&&a[end]>pivot){
            end--;
        }if(start<end){
       temp=a[end];
       a[end]=a[start];
       a[start]=temp;
    }
}
    temp=a[end];
       a[end]=a[l];
       a[l]=temp;
    
    return end;
}

static void quick(int a[],int l,int r){
    if(l<r){
        int loc=partition(a,l,r);
        quick(a,l,loc-1);
        quick(a,loc+1,r);
    }
}

public static void main(String[] args) {
int a[]={3,7,1,9,2,8};
quick(a,0,5);
for(int i:a){
    System.out.println(i+" ");
}
}
}