#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main_exit;
void close(void)
{
	printf("\n\n\n\nThis C Mini Project is developed by ANJAN KORADIA!\n\n\n");
}

int generateRandomNumber(int n)
{
	srand(time(NULL));
	return rand() % n;
}

int compare(char c, char p)
{
	if (c == p)
	{
		return -1;
	}
	else if (c == 'r' && p == 's')
	{
		return 1;
	}
	else if (c == 's' && p == 'r')
	{
		return 0;
	}
	else if (c == 'r' && p == 'p')
	{
		return 0;
	}
	else if (c == 'p' && p == 'r')
	{
		return 1;
	}
	else if (c == 's' && p == 'p')
	{
		return 1;
	}
	else if (c == 'p' && p == 's')
	{
		return 0;
	}
}
void fordelay()
{
	int i;
	long n = 3;
	for (i = 0; i <= n; i++)
	{
		printf(".");
		Sleep(500);
	}
}
void game()
{
	int n, i, temp, playerscore = 0, compscore = 0;
	char playerchar, compchar, name;
	char dict[] = {'r', 'p', 's'};
	printf("\nWelcome to the Rock,Paper,scissors Game.\n\n\n");
	printf("Enter your name : ");
	scanf("%s", &name);
	getchar();

	printf("\nHow many rounds you want to play : ");
	scanf("%d", &n);
	printf("\n");
	system("cls");

	printf("\n\nLet's start the Game.\n\nLODING");
	fordelay();

	for (i = 1; i <= n; i++)
	{

		printf("\n\n--------------- Round : %d ---------------\n\n", i);
		printf("Choose:\n1 for Rock\n2 for Paper\n3 for Scissor\n\n");
		printf("Your Turn : ");
		scanf("%d", &temp);
		getchar();
		playerchar = dict[temp - 1];
		printf("You choose : %c\n\n", playerchar);

		printf("Computer %d's Turn\n", i);
		temp = generateRandomNumber(3) + 1;
		compchar = dict[temp - 1];
		printf("Computer choose : %c\n\n", compchar);

		if (compare(compchar, playerchar) == 1)
		{
			compscore += 1;
		}
		else if (compare(compchar, playerchar) == -1)
		{
			compscore += 1;
			playerscore += 1;
		}
		else if (compare(compchar, playerchar) == 0)
		{
			playerscore += 1;
		}
		printf("Your score : %d\n", playerscore);
		printf("Computr score : %d\n\n", compscore);
	}

	system("cls");
	printf("\n\nCalculating Final Result");
	fordelay();

	printf("\n\n---------------Final Result---------------\n\n");
	printf("Your total score : %d\n", playerscore);
	printf("Computer total score : %d\n\n", compscore);

	if (playerscore > compscore)
	{
		printf("You Win The Game.\n\n");
	}
	else if (playerscore < compscore)
	{
		printf("Computer Win The Game.\n\n");
	}
	else if (playerscore == compscore)
	{
		printf("Game Draw.\n\n");
	}
}

int main()
{
	char pass[10], password[10] = "anjan";
	int i = 0;

	printf("\n\n\tEnter the password to start the game : ");
	scanf("%s", pass);
	if (strcmp(pass, password) == 0)
	{
		printf("\n\nPassword Match!\nLOADING");
		fordelay(3);
		system("cls");
		game();
	}
	else
	{
		printf("\n\nWrong password!!\a\a\a");
	login_try:
		printf("\nEnter 1 to try again and 0 to exit:");
		scanf("%d", &main_exit);
		if (main_exit == 1)
		{
			system("cls");
			main();
		}

		else if (main_exit == 0)
		{
			system("cls");
			close();
		}

		else
		{
			printf("\nInvalid!");
			fordelay();
			system("cls");
			goto login_try;
		}
	}
	return 0;
}
