package forLoops;

public class forLoops {

	public static void main(String[] args) {
		int sum = 0;
		for(int number = 1; number <= 100; number++) {
			sum = sum + number;
			System.out.print(number);
		}
		System.out.print("This is sum= " + sum);

	}

}
