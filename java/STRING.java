public class STRING {

 public static void reverseString(String input){
            char[]c=input.toCharArray();
            for(int i=input.length()-1;i>=0;i--){
                System.out.print(c[i]);
            }

        }

 public static void find(String input){
            
            char c[]=input.toCharArray();
            System.out.println();
            System.out.println("duplicates");
            for(int i=0;i<c.length;i++){
                int count=1;
                for(int j=i+1;j<c.length;j++){
                    if(c[i]==c[j]&&c[i]!=' '){
                        count++;
                        c[j]='0';
                        
                    }

                }
                if(count>1&&c[i]!='0')
                    System.out.print(c[i]+" ");
                
            }
        }
        static void rev(String input){
            String[]words=input.split(" ");
            String re="";
            for(int i=words.length-1;i>=0;i--){
                re+=words[i]+" ";

            }
            System.out.println(re.substring(0, re.length()-1));
        }
       
    public static void main(String[] args) {
        String input="hello java im really tired";
        System.out.println("reversed string");
        reverseString(input);
        
        find(input);

       rev(input);
    }
}
