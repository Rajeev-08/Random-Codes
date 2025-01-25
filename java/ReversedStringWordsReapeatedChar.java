class F{
    public static void main(String[] args) {
        String s="hello java im coding";


        int l=s.length();
        System.out.println("reve string");
        for(int i=l-1;i>=0;i--){
            System.out.print(s.charAt(i));
        }
    String c[]=s.split("\\s");
    int le=c.length;
    System.out.println();
    System.out.println("reve words");

    for(int i=le-1;i>=0;i--){
        System.out.print(" "+c[i]);
    }
    System.out.println();
    System.out.println("repeated char");

    for(int i=0;i<l;i++){
        int j=0;
        for( j=i+1;j<l;j++){
            if(s.charAt(i)==s.charAt(j)){
                System.out.print(s.charAt(i)+" ");
                break;
            }
        }
    }

    }
}

