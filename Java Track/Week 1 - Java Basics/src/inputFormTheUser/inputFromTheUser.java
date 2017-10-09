package inputFormTheUser;
//import the Scanner Class
import java.util.*;

public class inputFromTheUser {

	public static void main(String[] args) {
		//Scan for input
		Scanner scanner = new Scanner(System.in);
		//Tell the user what to do
		System.out.print("Enter a number: ");
		//Save the user input to a Variable
		int userInput = scanner.nextInt();
		
		int potentialFactor = 2;
		//Find a divisible number 
		while(userInput % potentialFactor != 0) {
			potentialFactor++;
		}
		if(potentialFactor == userInput) {
			System.out.print("Number is Prime");
		} else {
			System.out.print("Number is NOT prime, Factor: " + potentialFactor);
		}

	}

}
