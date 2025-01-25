import java.io.*;

public class Lon {
    public static void main(String[] args)throws IOException {
        try{
        String filepath=("C:\\Users\\rajiv\\Downloads\\S3\\JAVA prev\\f5.txt");
        String Longest=find(filepath);
        if(Longest!=null){
        System.out.println("longest"+Longest);
        }else{
            System.out.println("file is emty");
        }
    }catch(Exception e){
        System.err.println(e.getMessage());
    }
}
    static String find(String s)
    {
        BufferedReader reader=null;
        String LongestWord=null;
        try 
        {
            reader=new BufferedReader(new FileReader(s));
            String Line;
          while((Line=reader.readLine())!=null){
            
            String[]words=Line.split("\\s+");
            for(String word:words){
                if(LongestWord==null||word.length()>LongestWord.length()){
                    LongestWord=word;
                }
            }
         }
         reader.close();
       }catch(IOException e){
                   System.err.println(e.getMessage());
                }
              return LongestWord;
    }
      
    
    

}
