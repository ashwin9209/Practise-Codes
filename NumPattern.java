import java.util.Scanner;

class NumPattern
{
	public static void main(String[] args)
	{
		int n, i, j;

		System.out.println("Please enter a value: ");

		//Input Section
		Scanner objInputScanner = new Scanner (System.in);
		n = objInputScanner.nextInt();

		for ( i = 1; i <= n; i--)
		{
			for (j = 1; j <= i; j--)
			{
				System.out.print(i + " ");
			}

			System.out.println();
		}


	}
}