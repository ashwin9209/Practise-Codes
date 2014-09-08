#include<iostream.h>
#include<string.h>
#include<conio.h>

void main()
{
	clrscr();
	char choice, name[25], user_class[10];
	int i, age;

	cout<<"\nEnter your name: ";
	cin>>name;
	cout<<"\nEnter your age: ";
	cin>>age;
	cout<<"\nEnter your class: ";
	cin>>user_class;
	clrscr();
	cout<< "\n\nRound 1";

	do
	{
		cout<<"\n\n\nQ1. Who is Aaliya in the movie Dhoom 3?";
		cout<<"\na) Katrina Kaif\nb) Kareena Kapoor\n";
		cin>>choice;

		switch(choice)
		{
			case 'a': cout<<"Right answer!";
					break;

			case 'b': cout<<"Wrong answer! Please try again.";
					break;

			default: cout<<"Invalid choice! Please try again.";
					break;
		}

	} while(choice != 'a');

	do
	{
		cout<<"\n\n\nQ2. What is Ranbir Kapoor's name in Yeh Jawaani Hai Deewani?";
		cout<<"\na) Bunny\nb) Rabbit\n";
		cin>>choice;

		switch(choice)
		{
			case 'a': cout<<"Right answer!";
					break;

			case 'b': cout<<"Wrong answer! Please try again.";
					break;

			default: cout<<"Invalid choice! Please try again.";
					break;
		}

	} while(choice != 'a');

	do
	{
		cout<<"\n\n\nQ3. Which movie was first named 'Romeo Rajkumar'?";
		cout<<"\na) R...Rajkumar\nb) Maine Pyaar Kyon Kiya\n";
		cin>>choice;

		switch(choice)
		{
			case 'a': cout<<"Right answer!";
					break;

			case 'b': cout<<"Wrong answer! Please try again.";
					break;

			default: cout<<"Invalid choice! Please try again.";
					break;
		}

	} while(choice != 'a');

	cout<< "\n\nWell done "<<name<<". You're selected for Round 2";

	do
	{
		cout<<"\n\n\nQ1. Every cloud has a _________";
		cout<<"\na) Silver Lining\nb) Bronze Lining\n";
		cin>>choice;

		switch(choice)
		{
			case 'a': cout<<"Right answer!";
					break;

			case 'b': cout<<"Wrong answer! Please try again.";
					break;

			default: cout<<"Invalid choice! Please try again.";
					break;
		}

	} while(choice != 'a');

	do
	{
		cout<<"\n\n\nQ2. Good things come to those who _________";
		cout<<"\na) Wait\nb) Dance\n";
		cin>>choice;

		switch(choice)
		{
			case 'a': cout<<"Right answer!";
					break;

			case 'b': cout<<"Wrong answer! Please try again.";
					break;

			default: cout<<"Invalid choice! Please try again.";
					break;
		}

	} while(choice != 'a');

	do
	{
		cout<<"\n\n\nQ3. Roots of success are formed through _________";
		cout<<"\na) Hard Work\nb) Concrete\n";
		cin>>choice;

		switch(choice)
		{
			case 'a': cout<<"Right answer!";
					break;

			case 'b': cout<<"Wrong answer! Please try again.";
					break;

			default: cout<<"Invalid choice! Please try again.";
					break;
		}

	} while(choice != 'a');

	cout<<"\n\nWell done "<<name<<"! You have completed the quiz!";

return 0;
}