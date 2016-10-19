#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

//FUNCTION PROTOTYPES
void table(double (*pf)(double i, int m, double n), double a, int m, double n);
double md1(double i, int m, double n);
double md2(double i, int m, double n);
double md3(double i, int m, double n);
int version_info();
int loader();
int loader_dots();

//VARIABLE DECLARATIONS
int m;				//NUMBER OF COMPOUNDING PERIODS PER YEAR
double n;			//NUMBER OF YEARS
double a;			//AMOUNT OF EACH MONTHLY PAYMENT
char freq;			//FREQUENCY OF COMPOUNDING INTEREST
int i;				//LOADER VARIABLE COUNT
int loader()
{
	int load_var;
	for (load_var=0; load_var<=100; load_var++)
	{
		fflush(stdout);
		usleep(100000);
		printf("%d PERCENT LOADED..\r",  load_var);
	}
}


int loader_dots()
{
		int lvar_out;
		for (lvar_out = 0; lvar_out < 4; lvar_out++)
		{
			fflush(stdout);
			sleep(1);
			printf(".");
		}
}

int version_info()
{
	int cred_anim;
	char cred[100]="FUTURE VALUE OF A SERIES OF MONTHLY DEPOSITS";
	loader();
	for (cred_anim= 0; cred_anim < strlen(cred); cred_anim++)
	{
		fflush(stdout);
		usleep(100000);
		printf("%1c", cred[cred_anim] );
	}
	
	printf("\n\n\n");
	sleep(1);
	char copyright[] = "Copyright © 2016 Sahil Sanghavi @ CodeLearner Labs Inc.";
	for (i = 0; i < strlen(copyright); i++)
	{
		fflush(stdout);
		usleep(10000);
		printf("%c", copyright[i] );
	}
	printf("\n");
	char ver[] = "Version 4.7";
	
	for (i = 0; i < strlen(ver); i++)
	{
		fflush(stdout);
		usleep(20000);
		printf("%c", ver[i] );
	}	
	printf("\n");
	return 0;
}

/*
int credits()
{
	printf("\n\nProudly developed by CodeLearnerLabs Inc.\n");
	//printf("*Program logic by Torna Lunkad©\n");
	printf("Copyright © 2016 Sahil Sanghavi @ CodeLearner Labs Inc.\n");
	printf("Exiting program...\n\n\n");
}
*/



main() 
{
	version_info();

	//ACCEPT 'a' , 'n'
	printf("\nPlease sit back and answer a few questions...\n\n");
	sleep(2);
	printf("Amount of each monthly payment: Rs. ");
	scanf("%lf", &a);
	
	printf("Number of years: ");
	scanf("%lf", &n);

	//ACCEPT FREQUENCY OF COMPOUNDING
	do 
	{
		printf("FREQUENCY OF COMPOUNDING INTEREST (A, S, Q, M, D, C): ");
		scanf("%1s", &freq);
		freq = toupper(freq);
		
		if (freq == 'A') {
			m = 1;
			printf("\n\t\tANNUAL COMPOUNDING SHIT\n");
		}	
		else if (freq == 'S') {
			m = 2;
			printf("\n\t\tSEMI-ANNUAL COMPOUNDING SHIT\n");
		}	
		else if (freq == 'Q') {
			m = 4;
			printf("\n\t\tQUARTERLY COMPOUNDING SHIT\n");
		}
		else if (freq == 'M') {
			m = 12;
			printf("\n\t\tMONTHLY COMPOUNDING SHIT\n");
		}
		else if (freq == 'D') {
			m = 360;
			printf("\n\t\tDAILY COMPOUNDING SHIT\n");
		}
		else if (freq == 'C') {
		//	m = 0;
			printf("\n\t\tCONTINUOUS COMPOUNDING SHIT\n");
		}
		else
			printf("\nERROR - PLEASE REPEAT THAT SHIT\n");

	} while (freq != 'A' && freq != 'S' && freq != 'Q' && 
			 freq != 'M' && freq != 'D' && freq != 'C');

		//TABLE CALCULATION SHIT
		if (freq == 'C')
			table(md3, a, m, n);		//CONTINUOUS COMPOUNDING SHITTY CALCULATIONS
		else if (freq == 'D')
			table(md2, a, m, n);		//DAILY COMPOUNDING SHITTY CALCULATIONS
		else
			table(md1, a, m, n);		//ANNUAL, SEMI-ANNUAL, QUATERLY, MONTHLY COMPOUNDING SHITTY CALCULATIONS
}

void table (double (*pf)(double i, int m, double n), double a, int m, double n)
//TABLE GENERATOR (THIS FUNCTION ACCEPTS A POINTER TO ANOTHER FUNCTION AS AN ARGUEMENT)
//i.e. double (*pf)(double i, int m, double n) is a POINTER TO FUNCTION md1, md2 or md3 DEPENDING UPON char freq
{

	int irate;
	double i;
	double f;
	
	printf("Generating table, please wait\n");
	sleep(1);
	printf("----------------------------------------------------------------\n");
	sleep(1);
	printf("\tINTEREST RATE	|		FUTURE VALUE\n");
	printf("\t		|	          (Rupees)\n");
	sleep(1);
	printf("----------------------------------------------------------------\n\n");
	
	for (irate = 1; irate <= 20; ++irate) 
	{
		i = 0.1 * irate;
		f = a * (*pf)(i, m, n);										//ACCESSES THE FUNCTION PASSED AS AN ARGUEMENT *pf (i, m, n)
		printf("\t%2d		|		%.2f\n", irate, f);
		fflush(stdout);
		sleep(1);
	}

	printf("----------------------------------------------------------------\n\n");
	
	printf("\n\nDone!");
	
	printf("\nEXITING");
	
	loader_dots();
	
	printf(".\n\n");

	return;
}

double md1(double i, int a, double n)			//MONTHLY DEPOSITS, |A|S|Q|M| COMPOUNDING SHIT
{
	double factor, ratio;
	
	factor = 1 + i/m;
	ratio = 12 * (pow (factor, m*n) - 1) / i;
	return(ratio);
}

double md2(double i, int a, double n)			//MONTHLY DEPOSITS, DAILY COMPOUNDING SHIT
{
	double factor, ratio;
	
	factor = 1 + i/m;
	ratio = (pow (factor, m*n) - 1) / (pow (factor, m/12) - 1);
	return(ratio);
}

double md3(double i, int dummy, double n)		//MONTHLY DEPOSITS, CONTINUOUS COMPOUNDING SHIT
{
	double ratio;
	
	ratio = (exp(i*n) - 1) / (exp (i/12) - 1);
	return(ratio);
}