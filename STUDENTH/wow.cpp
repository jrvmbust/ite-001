#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                                                  
#include<time.h>

#define max 10

//buffet 101 reservation system project rev4
//fixed stuff
//credits to codewithc for some codes.

int checkID();
void addreservation();
void editreservation();
void delreservation();
void exitroutine();
void viewre();
void mainmenu();
void gettext();
void get_time(int * month, int * day, int * year, int * hour, int *mins);
int b=1,m,d,y,h,mi,sec;
char find;

const int price = 499;


FILE *fp,*ft;

COORD coord = {0, 0};

void gotocrd (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct main 
{
	char FName[30];
	char LName[30];
	int Rmonth,Rday,Ryear,guest;
	char Ftime[10];
	int id;
	int totalprice;
	int money;
	
};
struct main ReserveMain;

int checkID(int id) 
{
rewind(fp);
while(fread(&ReserveMain,sizeof(ReserveMain),1,fp)==1)
if(ReserveMain.id==id)
return 0;  
return 1; 
	

}
void removenline(char* str)
{
  int length;
  if( (length =strlen(str) ) >0)
  {
       if(str[length-1] == '\n')
                str[length-1] ='\0';
  }
}

void get_time (int * month, int * day, int * year, int * hour, int *mins,int *sec)
{
	struct tm *current;
	time_t currTime;
	time(&currTime);
   current = localtime(&currTime);
     *month = current->tm_mon+1;
     *day = current->tm_mday;
     *year = current->tm_year+1900;
     *hour = current->tm_hour;
     *mins = current->tm_min;
     *sec = current->tm_sec;
	
	}

void addreservation()    //main add reserve.
{

	system("cls"); 	
	gotocrd(19,4);
	printf("Enter the required informations below.\n \t\t      Type quit to return to the menu.");
	gotocrd(1,25);
	get_time( &m, &d, &y,&h,&mi,&sec);
	printf("The date and time today is %d/%d/%d %d:%.2d",m,d,y,h,mi);
	gotocrd(16,7);
	ReserveMain.money=0;
	printf("First Name: "); scanf("%29[0-9a-zA-Z ]",ReserveMain.FName);
	if (strcmp(ReserveMain.FName,"quit")==0)
	{
		mainmenu();
		
	}
	gotocrd(17,8);
	printf("Last Name: "); scanf("%s",ReserveMain.LName);
	gotocrd(1,9);
	printf("Month of Reservation (MM): "); scanf("%d",&ReserveMain.Rmonth); gotocrd(3,10);printf("Day of Reservation (DD): "); scanf("%d",&ReserveMain.Rday); gotocrd(1,11);printf("Year of Reservation (YYYY): "); scanf("%d",&ReserveMain.Ryear); //mdy
	gotocrd(22,12);
	getchar();
	printf("Time: "); fgets(ReserveMain.Ftime,max,stdin);
	removenline(ReserveMain.Ftime);
	gotocrd(14,13);
	printf("No. of Guests: "); scanf("%d", &ReserveMain.guest);
	gotocrd(20,15);
	ReserveMain.totalprice=ReserveMain.guest*price;
	printf("Total Price: PHP %d",ReserveMain.totalprice);
	gotocrd(5,16);
				while (ReserveMain.money<price)
				{
					printf("\t\tChange for how much?: ");scanf("%d",&ReserveMain.money);
					if(ReserveMain.money<price)
					printf("\t\tnot enough money.\n");
				}
	
	ReserveMain.id = m+d+y+h+mi+sec;
	
	//begin saving
	fp=fopen("Reservations.dat","ab+");
	fseek(fp,0,SEEK_END);
	fwrite(&ReserveMain,sizeof(ReserveMain),1,fp);
	fclose(fp);
	//close file
	system("cls");
	gotocrd(17,5);
	printf("The reservation record was sucessfully saved\n");
	getch();
	mainmenu();
	
}
void editreservation(void)	//edits
{	

	system("cls");
	int c=0;
	int d,e;
	char wew='y';
	while(wew=='y')
	{
		system("cls");
		gotocrd(1,25);
		ReserveMain.money=0;
		get_time( &m, &d, &y,&h,&mi,&sec);
		printf("The date and time today is %d/%d/%d %d:%.2d",m,d,y,h,mi);	
		gotocrd(15,5);
		printf("Enter Reservation ID to be edited: ");
		scanf("%d",&d);
		fp=fopen("Reservations.dat","rb+");
		while(fread(&ReserveMain,sizeof(ReserveMain),1,fp)==1)
		{
			if(checkID(d)==0)
			{
				c=1;
				gotocrd(10,7);
				printf("Matched a record with the ID!");
				gotocrd(10,10);
				printf("The Reservation ID: %d",ReserveMain.id);
				gotocrd(10,11);
				getchar();
				printf("Current First Name: %s | Enter new First Name: ",ReserveMain.FName);scanf("%29[0-9a-zA-Z ]",ReserveMain.FName);
				getchar();
				gotocrd(10,12);
				printf("Current Last Name: %s | Enter new Last Name: ",ReserveMain.LName);scanf("%s",ReserveMain.LName);
				gotocrd(10,13);
				printf("Current Month of Reservation: %d | Enter new Month: ",ReserveMain.Rmonth);scanf("%d",&ReserveMain.Rmonth);
				gotocrd(10,14);
				printf("Current Day of Reservation: %d | Enter new Day: ",ReserveMain.Rday);scanf("%d",&ReserveMain.Rday);
				gotocrd(10,15);
				printf("Current Year of Reservation: %d | Enter new Year: ",ReserveMain.Ryear);scanf("%d",&ReserveMain.Ryear);
				gotocrd(10,16);
				getchar();
				printf("Current Time: %s | Enter new Time: ",ReserveMain.Ftime);fgets(ReserveMain.Ftime,max,stdin);
				removenline(ReserveMain.Ftime);
				gotocrd(10,17);
				printf("Current No. of Guests: %d | Enter new No. of Guests: ",ReserveMain.guest);scanf("%d",&ReserveMain.guest);
				gotocrd(10,19);
				ReserveMain.totalprice=price*ReserveMain.guest;
				printf("New Total Price: PHP %d",ReserveMain.totalprice);
				gotocrd(10,20);
				
				while (ReserveMain.money<price)
				{
					printf("\t\tChange for how much?: ");scanf("%d",&ReserveMain.money);
					if(ReserveMain.money<price)
					printf("\t\tnot enough money.\n");
				}
				
				
				gotocrd(10,22);
				printf("The reservation record has been modified");
				fseek(fp,ftell(fp)-sizeof(ReserveMain),0);
				fwrite(&ReserveMain,sizeof(ReserveMain),1,fp);
				fclose(fp);
				
				}
			if(c==0)
			{
				gotocrd(15,9);
				printf("No record found.");
			}
		}
		fclose(fp);
	fflush(stdin);
	wew=getch() ;
	mainmenu();
	}
}

void delreservation() //deletes
{
	system("cls");
	int d;

	char da[5];
	char wew='y';
	while(wew=='y')  
	{
		system("cls");
		gotocrd(1,24);
		get_time( &m, &d, &y,&h,&mi,&sec);
		printf("The date and time today is %d/%d/%d %d:%.2d",m,d,y,h,mi);
		gotocrd(10,5);
		printf("Enter the ID of the reservation to delete: ");
		scanf("%s",&da);
		d=atoi(da);
		fp=fopen("Reservations.dat","rb+");
		rewind(fp);
		while(fread(&ReserveMain,sizeof(ReserveMain),1,fp)==1)
		{
			if(ReserveMain.id==d)
			{
				gotocrd(10,7);
				printf("A record was matched with your ID. \n\n");
				gotocrd(10,9);
				printf("The Reserver's name is %s, %s",ReserveMain.LName, ReserveMain.FName);
				gotocrd(10,10);
				printf("The Date and Time of the reservation is %d/%d/%d %s",ReserveMain.Rmonth,ReserveMain.Rday,ReserveMain.Ryear,ReserveMain.Ftime);
				find='t';
			}
		}
		if(find!='t')
		{
			gotocrd(10,10);
			printf("No record was found.");
			if(getch())
			mainmenu();
		}
		if(find=='t')
		{
			gotocrd(10,12);
			printf("Do you want to delete it?(Y/N):");
			if(getch()=='y')
			{
				ft=fopen("temp.dat","wb+");  
				rewind(fp);
				while(fread(&ReserveMain,sizeof(ReserveMain),1,fp)==1)
				{	
					if(ReserveMain.id!=d)
					{
						fseek(ft,0,SEEK_CUR);
						fwrite(&ReserveMain,sizeof(ReserveMain),1,ft); 
					}                             
				}
				fclose(ft);	
				fclose(fp);
				remove("Reservations.dat");
				rename("temp.dat","Reservations.dat"); 
				fp=fopen("Reservations.dat","rb+");    
				if(find=='t')
				{		
					gotocrd(10,15);
					printf("The reservation record was sucessfully deleted");
					getch();
					mainmenu();

				}
			}
		else
			fflush(stdin);
			getch();
		}
}
	mainmenu();
}

void viewre() //views
{
	int i=0,j=5;
	
	system("cls");

	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Guests List\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotocrd(0,2);
	printf("ID    LNAME, FNAME       DATE      TIME      NO. OF G   TOTAL PRICE  CHANGE FOR\n\n");
	
	fp=fopen("Reservations.dat","rb");
	while(fread(&ReserveMain,sizeof(ReserveMain),1,fp)==1)
		{
			gotocrd(0,j);
			printf("%d",ReserveMain.id);
			gotocrd(6,j);
			printf("%s, ",ReserveMain.LName);
			printf("%s",ReserveMain.FName);		
			gotocrd(25,j);
			printf("%d/%d/%d",ReserveMain.Rmonth,ReserveMain.Rday,ReserveMain.Ryear);
			gotocrd(36,j);
			printf("%s",ReserveMain.Ftime);
			gotocrd(48,j);
			printf("%d",ReserveMain.guest);
			gotocrd(58,j);
			printf("PHP %d",ReserveMain.totalprice);
			gotocrd(69,j);
			printf("PHP %d",ReserveMain.money);
			printf("\n\n");
			j++;
		}
	fclose(fp);
		gotocrd(1,24);
		get_time( &m, &d, &y,&h,&mi,&sec);
		printf("The date and time today is %d/%d/%d %d:%.2d",m,d,y,h,mi);
	getch();
	system("cls");
	mainmenu();
}

void exitroutine() //goodbye msg
{
	system("cls");
	system("color 07");
	gotocrd(35,11);
	printf("Goodbye.");
	getch();
	exit(0);
	
}

void mainmenu() //menu
{
	char a[15];
	fclose(fp);
	system("cls");
	system("color 17");
	gotocrd(1,25);
	get_time( &m, &d, &y,&h,&mi,&sec);
	printf("The date and time today is %d/%d/%d %d:%.2d",m,d,y,h,mi);
	gotocrd(1,1);
	printf("\n\n\t       BUFFET 101 RESERVATION SYSTEM\n");
	printf("\n\t-----------------------------------------");
	printf("\n\t   1. Add a reservation");
	printf("\n\t   2. Edit a reservation");
	printf("\n\t   3. Delete a reservation");
	printf("\n\t   4. View reservations");
	printf("\n\t   5. Exit the program");
	printf("\n\t-----------------------------------------");
	printf("\n\n Enter your choice: "); scanf("%s",&a);

			switch(atoi(a))
		{
		case 1:
			getchar();
			addreservation();
			break;
		case 2:
			editreservation();
			break;
		case 3:
			delreservation();
			break;
		case 4:
			viewre();
			break;
		case 5:
			exitroutine();
			break;
		default:
			system("cls");
			printf("\n\n\n\t\t\t Invalid Input. Returning to menu.");
			Sleep(1000);
			mainmenu();
			break;
		}	
		}

	


int main()
{
	mainmenu();
	return 0;
	}




