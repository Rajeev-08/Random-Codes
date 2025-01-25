import java.util.Scanner;
class Node{
    int data;
    Node prev;
    Node next;
    public Node(int data){
        this.data=data;
        next=null;
        prev=null;
    }
}

class Dll {
    Node head;
    Node ptr;
    void insert(int data){
        Node newNode=new Node(data);
        if(head==null){
            head=newNode;
        }else{
           ptr=head;
            while(ptr.next!=null){
                ptr=ptr.next;
            }
            ptr.next=newNode;
            newNode.prev=ptr;
        }
    }

    void delete(int data){
        ptr=head;
        while(ptr!=null){
            if(ptr.data==data){
                if(ptr.prev!=null){
                    ptr.prev.next=ptr.next;
                }else{
                    head=ptr.next;
                }
            if(ptr.next!=null){
                ptr.next.prev=ptr.prev;
            }
            
            return;
            }
            ptr=ptr.next;
        }
    }


    void display(){
        ptr=head;
        System.out.println("elements are :");
        while(ptr!=null){
            System.out.print(ptr.data+"->");
            ptr=ptr.next;
        }
        System.out.print("null");
      
    }
}

class M{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        Dll l=new Dll();
        int choice,data;
        do{
            System.out.println("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter a choice :");
            choice=s.nextInt();
            switch(choice){
                case 1:
                    System.out.println("enter the data to insert :");
                    data=s.nextInt();
                    l.insert(data);
                    break;
                case 2:System.out.println("enter the element to delete :");
                    data=s.nextInt();
                    l.delete(data);
                    break;
                case 3:l.display();
                       break;
                
            }
        }while(choice!=4);
        s.close();
    }
}