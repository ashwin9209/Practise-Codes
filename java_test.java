class java_test_drive
{
	int[] locationCells;
	int numOfHits = 0;

	public void setLocationCells(int[] locs)
	{
		locationCells = locs;
	}

	public String checkYourself(String stringGuess)
	{
		int guess = Integer.parseInt(stringGuess);
		String result = "miss";
		for (int cell : locationCells)
		{
			if (guess == cell)
			{
				result = "hit";
				numOfHits++;
				break;
			}

		} // out of the loop

		if (numOfHits == locationCells.length)
		{
			result = "kill";
		}

		System.out.println(result);

		return result;

	} // close method

} // close class



public class java_test
{
	public static void main ()
	{
		java_test_drive dot = new java_test_drive();
		int[] locations = {2,3,4};

		dot.setLocationCells(locations);
		String userGuess = "2";
		String result = dot.checkYourself(userGuess);
	}
}