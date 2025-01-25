import java.util.Scanner;
public class Stack{
      int top=-1;
      int data;
       int n;
      int stack[]=new int[50];

  boolean isfull(int n){
    if(top==n-1){
        return true;
    }
    return false;
    }
  boolean isempty(int n){
    if(top==-1){
        return true;
    }
    return false;
    }

  void push(int data,int n){
        if(isfull(n)){
            System.out.println("stack is full");
        }
        stack[++top]=data;
    }

  int pop(int n){
    if(isempty(n)){
        System.out.println("empty");
        return ' ';
    }
    return stack[top--];
}
  void display(){
    for(int i=top;i>=0;i--){
       System.out.println(stack[i]);
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
            o.push(data,n);
            break;

            case 2:
             data=o.pop(n);
            System.out.println("the element "+data+" is poped");
            break;

            case 3:System.out.println("elements are :");
            o.display();break;
        }
    }while(choice!=4);
    s.close();
      
} 
}


    
