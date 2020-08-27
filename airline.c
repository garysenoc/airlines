#include <stdio.h>
#include <string.h>

//sets all index of array to 0
void initSeats(int seats[], int size){
	memset(seats, 0, size*sizeof(seats[0])); 
}

void Exit(void){
	printf("\nNext flight leaves in 3 hours.\n\n");
	system("pause");
}

//Display the values of index in Array
void displaySeats(int seats[], int size){
	int i;
	for(i =0;i<size;i++){
		(i==0) ? printf("\nFirst Class Section: ") : i==5? printf("\nEconomy Section:    ") : printf("");	
		printf("[%d] ",seats[i]);
	}
}

//return the number of seats in specific section
int assignSeat(int st[], int size, int seatType){
	int avail,opt;
	if(seatType ==1){
		avail = assignFirstClass(st,size);
		if(avail!=-1)
			return avail;
		else{
			printf("\n\nThe First Class Section is full. Would you like to be placed in Economy Section?\n Type 1 for Yes\nType 2 for No: ");
			scanf("%d",&opt);
			return (opt==1) ? assignEconomy(st,size) :-1;
		}
	}
	else{
			avail = assignEconomy(st,size);	
			if(avail!=-1)
				return avail;
			else{
				printf("\n\nThe Economy Section is full. Would you like to be placed in First Class Section?\n Type 1 for Yes\nType 2 for No: ");
				scanf("%d",&opt);
				return (opt==1) ? assignFirstClass(st,size): -1;
		}
	}
}

//return seat number in first class section
int assignFirstClass(int seats[], int size){
	int i;
	for(i=0;i<size/2;i++)
		if(seats[i]==0){
			seats[i] = 1;
			return i;
		}			
	return -1;
}

//return seat number in economy section
int assignEconomy(int seats[], int size){
	int i;
	for(i=size/2;i<size;i++)
		if(seats[i]==0){
			seats[i] = 1;
			return i;
		}			
	return -1;
}

//prints the board pass with the seat number
void boardPass(int seat){
	
	printf("-----------------------");
	(seat+1<=5) ? printf("\n| Boarding Pass       |\n| First Class Section |\n| Seat #%d             |",seat+1) : printf("\n| Boarding Pass       |\n| Economy Section     |\n| Seat #%d             |",seat+1);
	printf("\n-----------------------\n\n");
	system("pause");
}

//check if there's available seats
int isAvailable(int seats[],int size){
	int i;
	for(i=0;i<size;i++)
		if(seats[i] == 0)
			return 1;
	return 0;
}
