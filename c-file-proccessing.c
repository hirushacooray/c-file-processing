#include <stdio.h>
#include <stdlib.h>

/* Function declaration */
void add_new_dvd();
void search_dvd();
void show_all();

/* Struct declaration */
struct movie {
	char title[55];
	char category[55];
	int price;
	int stock;
	int year;
} m;

int main(){
	int choice;
	do {
		system("cls");
		printf(" Welcome to DVD Rental Application!\n");
		printf("\n <1> Add new DVD\n <2> Seach for a DVD\n <3> Show All DVDs\n <0> Exit the Application\n\n");
		printf(" Please enter your choice ");
		scanf("%d", &choice);
		
		//Check the user's desired choice.
		switch(choice){
			case 1: add_new_dvd();
			break;
			
			case 2: search_dvd();
			break;
			
			case 3: show_all();
			break;
			
			case 0: exit(0);
			break;
			
			default: printf(" Invalid choice");
		}
		getch();
	}while (choice!=0); //run the loop when the choice is not equal to 0.
}

void add_new_dvd(){
	
	/* File Pointer */
	/* Open the file in Append mode */
	FILE* fptr = fopen("records.txt", "a");
	
	//Check the file pointer is equal to null or not
	if (fptr==NULL){
		printf("Sorry. File Could Not be Opened");
	}else{
		printf(" Please Enter the Movie Title ");
		scanf(" %[^\n]s", m.title);
		printf(" Please Enter the Movie Category ");
		scanf(" %[^\n]s", m.category);
		printf(" Please Enter the Price (Rs.) ");
		scanf("%d", &m.price);
		printf(" Please Enter the Stock Quantity ");
		scanf("%d", &m.stock);
		printf(" Please Enter the Year of the Movie ");
		scanf("%d", &m.year);
		
		fprintf(fptr, "%15s %15s %15d %15d %15d \n", m.title, m.category, m.price, m.stock, m.year);
		printf("\n Record Added Successfully! Press Enter Any Key to Continue.");
		fclose(fptr);
	}
	
}
void search_dvd(){
	
	//Open the file in read mode.
	FILE* fptr = fopen("records.txt", "r");
	char keyword[55]; //To store the keyword given by the user.
	int result;
	int quantity;
	int total;
	int found = 0;
	
	printf(" Please enter the movie title ");
	scanf(" %[^\n]s", keyword);
	
	while(! feof(fptr)) {
		
		fscanf(fptr, "%15s %15s %15d %15d %15d \n", m.title, m.category, &m.price, &m.stock, &m.year);
	
		result = strcmp(m.title, keyword);
		
		if(result==0){
			found = 1;
			printf("\n Record Found! \n");
			printf("\n Movie Title: %s ", m.title);
			printf("\n Movie Category: %s ", m.category);
			printf("\n Movie Relased Year: %d ", m.year);
			printf("\n Price: Rs.%d", m.price);
			printf("\n Stock Quantiry: %d ", m.stock);
			
			printf("\n\n Please enter the number of DVDs you need to purchase ");
			scanf("%d", &quantity);
			
			if (m.stock >= quantity){
				total = m.price * quantity;
				printf(" Total amount is Rs. %d", total);
				printf("\n Press Enter Any Key to Continue.");
			}else{
				printf(" Sorry. Requested No. of DVDs are not in stock. \n Press Enter Any Key to Continue.");
			}
		}
	}
	if (found == 0){
		printf(" Sorry. No Record(s) Found. \n Press Enter Any Key to Continue.");
	}

}
void show_all(){
	FILE* fptr = fopen("records.txt", "r");
	/* Heading */
	printf("\n%15s %15s %15s %15s %17s \n" ,"Title","Category","Price(Rs.)","Stock"," Year \n");
		
	while(!feof(fptr)){
		fscanf(fptr, "%15s %15s %15d %15d %15d \n", m.title, m.category, &m.price, &m.stock, &m.year);
		printf("%15s %15s %15d %15d %15d \n", m.title, m.category, m.price, m.stock, m.year);
	}
	printf(" \n Press Enter Any Key to Continue.");
}
