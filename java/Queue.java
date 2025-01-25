import java.util.Scanner;
public class Stack{
      int r=-1,f=-1;
      int data;
       int n;
      int q[]=new int[50];

  boolean isfull(int n){
    if(r==n-1){
        return true;
    }
    return false;
    }
  boolean isempty(int n){
    if(r==-1&&f==-1){
        return true;
    }
    return false;
    }

  void enqueue(int data,int n){
        if(isfull(n)){
            System.out.println("Q is full");
        }
        else if(f==-1&&r==-1){
            f=r=0;
            q[r]=data;
        }else{
            r++;
            q[r]=data;
        }
    }

  int dequeue(int n){
    if(isempty(n)){
        System.out.println("empty");
        return ' ';
    }if(f==0&&r==0){

        f=r=-1;
        return q[0];
    }else{
       return q[f++];

    }
   
}
  void display(){
    for(int i=f;i<=r;i++){
       System.out.println(q[i]);
    }

}

public  static void main(String[] args) {
    int choice;
    Scanner s=new Scanner(System.in);
    System.out.println("enter the size of stack :");
    int n=s.nextInt();
   Stack o=new Stack();
    do{
        System.out.println("\n1.PUSH\n2.POP\n3.display\n4.exit\nEnter the choice :");
       choice=s.nextInt();
        switch(choice){
            case 1:System.out.println("enter the data to insert :");
            int data=s.nextInt();
            o.enqueue(data,n);
            break;

            case 2:
             data=o.dequeue(n);
            System.out.println("the element "+data+" is poped");
            break;

            case 3:System.out.println("elements are :");
            o.display();break;
        }
    }while(choice!=4);
    s.close();
      
} 
}


    
