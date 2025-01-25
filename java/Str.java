public class Str {
    static void frequency(String input){
        String s=input.toLowerCase();
        int []fr=new int[5];
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
           switch(c){
            case 'a' : fr[0]++;break;
            case 'e' : fr[1]++;break;
            case 'i' : fr[2]++;break;
            case 'o' : fr[3]++;break;
            case 'u' : fr[4]++;break;
           
           }
        }
           System.out.println("a :"+fr[0]);
           System.out.println("e :"+fr[1]);
           System.out.println("i :"+fr[2]);
           System.out.println("o :"+fr[3]);
           System.out.println("u :"+fr[4]);
        

    }
    static void re(String input){
        String s=input.replaceAll("[aeiouAEIOU]","");
        System.out.println("String without vowel : "+s);
    }
    public static void main(String[] args) {
        String input="welcome TO Programing with JAVA";
        frequency(input);
        re(input);
    }
    
}
