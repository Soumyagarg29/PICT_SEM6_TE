import java.util.Scanner;
import java.security.NoSuchAlgorithmException;
import java.security.MessageDigest;


public class MD5{
    public static void main(String[] args) throws NoSuchAlgorithmException
    {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();

        System.out.println("The input string is :"  + input);

        String hash = calculate(input);


        System.out.println(hash);

    } 

    public static String calculate(String input) throws NoSuchAlgorithmException
    {
        MessageDigest md5 = MessageDigest.getInstance("MD5");
        md5.update(input.getBytes());
        byte[] bytes = md5.digest();
        StringBuilder sb=new StringBuilder();
        for(byte b : bytes)
        {       System.out.println(b);
                sb.append(Integer.toString((b & 0xff) + 0x100 , 16).substring(1));

        }
        return sb.toString();

    }
}