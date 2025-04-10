import java.io.*;
import java.util.Scanner;
public class Dvr{
    static int graph[][],rt[][],via[][],e,v;
    public static void main(String[]args)throws Exception{
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the No.of Vertices :");
        v=sc.nextInt();
        System.out.println("enter the No.of Edges :");
        e=sc.nextInt();

        graph=new int[v][v];
        rt=new int[v][v];
        via=new int[v][v];

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i==j){
                    graph[i][j]=0;
                }else{
                    graph[i][j]=999;
                }
            }
        }
        for(int i=0;i<e;i++){
            System.out.println("Enter the data For the Edge "+(i+1));
            System.out.println("source:");
            int s=sc.nextInt();
            s--;
            System.out.println("dest:");
            int d=sc.nextInt();
            d--;
            System.out.println("cost:");
            int c=sc.nextInt();
            graph[s][d]=c;
            graph[d][s]=c;
        }

        dvr("initial routing table is:");

        System.out.println("Enter the data for the edge whose cost has changed");
        System.out.println("source:");
            int s=sc.nextInt();
            s--;
            System.out.println("dest:");
            int d=sc.nextInt();
            d--;
            System.out.println("cost:");
            int c=sc.nextInt();
            graph[s][d]=c;
            graph[d][s]=c;

        dvr("new routing table is :");
    }

    static void dvr(String msg){
        System.out.println();
        init_t();
        updata_t();
        System.out.println(msg);
        print_t();
        System.out.println();
    }

    static void init_t(){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i==j){
                    rt[i][j]=0;
                    via[i][j]=i;
                }else{
                    rt[i][j]=999;
                    via[i][j]=-1;
                }
            }
        }
    }

    static void updata_t(){
        int k=0;
        for(int i=0;i<(4*v);i++){
            update(k);
            k++;
            if(k==v){
                k=0;
            }
        }
    }


    static void update(int source){
        for(int i=0;i<v;i++){
            if(graph[source][i]!=999){
                int dist=graph[source][i];
                for(int j=0;j<v;j++){
                    int inter_dist=rt[i][j];
                    if(via[i][j]==source){
                        inter_dist=999;
                    }
                    if(inter_dist+dist<rt[source][j]){
                        rt[source][j]=inter_dist+dist;
                        via[source][j]=i;
                    }
                }
            }
        }
    }

    static void print_t(){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                System.out.print("Dist "+rt[i][j]+" ");
            }
            System.out.println();
        }
    }
}
