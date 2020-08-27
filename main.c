#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "airline.h"
#define SIZE 10

/*
Created by: Gary Lloyd M. Senoc
Date Created: 27/08/20
Project Name: Airline Reservation
*/

int main(){
	
	int seats[SIZE],opt,numSeat,val;
	initSeats(seats,SIZE);
	
	do{
			system("cls");
			printf("\n\nWelcome to MGM Airlines!\n\n");
			displaySeats(seats,SIZE);
			printf("\n\nPlease type 1 for \"first class\"\n");
			printf("Please type 2 for \"economy\": ");
			scanf("%d",&opt);
			
			val = assignSeat(seats,SIZE,opt);
			(val==-1) ? Exit() : boardPass(val);
			
	}while(isAvailable(seats,SIZE));
	
		displaySeats(seats,SIZE);
		printf("\n\nThe First Class Section and Economy section are already full.\n");
		Exit();
		
	return 0;
}
