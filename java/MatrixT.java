import java.util.Scanner;
public class MatrixT{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
       System.out.println("Enter the no of rows of Matrix A : ");
       int r1=s.nextInt();
       System.out.println("Enter the no of cols of Matrix A : ");
       int c1=s.nextInt();
       System.out.println("Enter the no of rows of Matrix B : ");
       int r2=s.nextInt();
       System.out.println("Enter the no of cols of Matrix B : ");
       int c2=s.nextInt();
            
        int A[][]=new int[r1][c1];
        int B[][]=new int[r2][c2];
        
       System.out.println("MATRIX A");
       for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            System.out.println("A["+i+"]["+j+"] : ");
            A[i][j]=s.nextInt();
        }
       }
        for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            System.out.println("B["+i+"]["+j+"] : ");
            B[i][j]=s.nextInt();
        }
       }
       System.out.println("MATRIX A");
for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
        System.out.print(A[i][j] + "\t");
    }
    System.out.println();
}
System.out.println();


System.out.println("MATRIX B");
for(int i=0;i<r2;i++){
    for(int j=0;j<c2;j++){
        System.out.print(B[i][j] + "\t");
    }
    System.out.println();
}
System.out.println();

System.out.println("is the MATRIX A is square : "+isSquare(r1,c1));
System.out.println("is the MATRIX B is square : "+isSquare(r2,c2));


int [][]M=mul(A, B);
System.out.println("tarnspose");
print(transpose(M));

    }
    
    static int[][] mul(int A[][],int B[][]){
        int r1=A.length;
        int c1=A[0].length;
        int r2=B.length;
        int c2=B[0].length;
        int C[][]=new int [r1][c2];



System.out.println("MATRIX C");
for(int i=0;i<r1;i++){
    for(int j=0;j<c2;j++){
        for(int k=0;k<c1;k++){
                C[i][j]+=A[i][k]*B[k][j];
        }
        System.out.print(C[i][j] + "\t");
    }
    System.out.println();
}
System.out.println();
return C;
    }



static boolean isSquare(int r,int c){
     return r==c;
}

static int[][] transpose(int[][]C){
          int r=C.length;
         int c=C[0].length;
         int [][]T=new int[c][r];
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                T[j][i]=C[i][j];
            }
         }
return T;
}

static void print(int [][]H){
    int r=H.length;
    int c=H[0].length;
    for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                System.out.print(H[i][j]+ "\t");
            }
            System.out.println();
        }
        System.out.println();
           
}
}