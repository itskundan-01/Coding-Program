import java.util.Random;
import java.util.*;

public class NumberGame{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int random = new Random().nextInt(100) + 1;
        System.out.println("Enter your Guess between 1 to 100:");
        int input = sc.nextInt();
        for(int i=1;input!=random;i++){
            if(input<random){
                System.out.println("Your guess is too low. Try again:");
            } else {
                System.out.println("Your guess is too high. Try again:");
            }
            input = sc.nextInt();
        }
        System.out.println("Congratulations!!, You guessed it right");
    }
}