/*CARLS SUPERDUPERMARKET v1 POS SYSTEM LEGGO*/


/*




DI PA TAPOS TO KINGINA MO.
TATANGGALIN KO TO KAPAG TAPOS NA.
PINOST KO LANG TO PARA MAKITA NYO




*/
/*CARLS SUPERDUPERMARKET v1 POS SYSTEM LEGGO*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>                                                  
#include <time.h>
#include <windows.h>



//started 12:20 AM SEPT 21 2015 lets see when this'll be finished. \m/


//buglist
//WAIT FOR THE ANIMATIONS TO FINISH PLS.
//FIXED ^ 9/23/2015
//SALES NALANG 

void menuInventory();
void credits();
void addInventory();
void sales();
void delInventory();
void editInventory();
void menu();
void exitR();
void greeting();
void returN();
void additem(),voiditem(),checkout();
void printBorders(int x,int y);
void windowSize(int a, int b);
int main();


FILE *fi1,*fdel,*fsal,*fsaldel;

COORD xy = {0, 0};


void gtc (int a, int b) //pang lagay ng cursor to. iispecify mo ung coordinates (x,y) kung san mo gusto ilagay ung printf
{
	xy.X = a; 
	xy.Y = b; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void returN()
{
	system("cls");
	system("color 1f");
	gtc(37,15);
	printf("Returning to Menu.");
	for(int a=37;a<=50;a++)
	{
		gtc(a,16);
		printf("\xB1");
		Sleep(10);
	}
	
}

void nlfix(char* a)
{
  int len;
  if( (len =strlen(a) ) >0)
  {
       if(a[len-1] == '\n')
                a[len-1] ='\0';
  }
}

struct inventory
{
	int itemID;
	char pName[80];
	float price;
};
struct sales
{
	int quan;
	int id;
	char name[6];
	float price;
	float total;
	int totalquan;
};

struct sales sal1;
struct inventory inv1;

void windowSize(int a, int b) 
{
    struct _SMALL_RECT test; 

    HANDLE hStdout;
    COORD coord;
    BOOL ok;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = a;
    coord.Y = b;
    ok = SetConsoleScreenBufferSize(hStdout, coord);

    test.Left = 0;
    test.Top = 0;
    test.Right = coord.X-1;
    test.Bottom = coord.Y-1;

    SetConsoleWindowInfo(hStdout, ok, &test);

} 

void printBorders(int x, int y) //my own dear printborder function. static
{
	for(int a=1;a<x;a++)
	{
		gtc(a,0);
		printf("\xb2");
	}
	for(int b=1;b<y;b++)
	{
		gtc(0,b);
		printf("\xb2");
	}
	for(int c=1;c<y;c++)
	{
		gtc(x,c);
		printf("\xB2");
	}
	for(int d=1;d<x;d++)
	{
		gtc(d,y);
		printf("\xB2");
	}

}

void printBorders1(int x, int y) //my own dear printborder function. intro animation
{
	for(int a=1;a<x;a++)
	{
		gtc(a,0);
		Sleep(5);
		printf("\xB2");
	}
	for(int b=1;b<y;b++)
	{
		gtc(0,b);
		Sleep(5);
		printf("\xB2");
	}
	for(int c=1;c<y;c++)
	{
		gtc(x,c);
		Sleep(5);
		printf("\xB2");
	}
	for(int d=1;d<x;d++)
	{
		gtc(d,y);
		Sleep(5);
		printf("\xB2");
	}
}

void printBorders2(int x, int y) //my own dear printborder function. exit animation
{
	for(int a=1;a<x;a++)
	{
		gtc(a,0);
		Sleep(5);
		printf(" ");
	}
	for(int b=1;b<y;b++)
	{
		gtc(0,b);
		Sleep(5);
		printf(" ");
	}
	for(int c=1;c<y;c++)
	{
		gtc(x,c);
		Sleep(5);
		printf(" ");
	}
	for(int d=1;d<x;d++)
	{
		gtc(d,y);
		Sleep(5);
		printf(" ");
	}
}

void printBox(int s,int sy,int w,int h)
{
	int fw=s+w;
	int fh=sy+h;
	for (int a=s;a<=fw;a++)
	
	{
		gtc(a,sy); printf("\xB1");
	}
	for (int b=sy;b<=fh;b++)
	{
		gtc(s,b); printf("\xB1");
	}
	for (int c=sy;c<=fh;c++)
	{
		gtc(fw,c);printf("\xB1");
	}
	for (int d=s;d<=fw;d++)
	{
		gtc(d,fh); printf("\xB1");
	}

}
void printline(int width,int ystart)
{

	for (int a = 0;a<=width;a++)
	{
		gtc(a,ystart);
		printf("\xB2");
	}

}
void printlinev(int height,int xstart,int ystart)
{

	for (int a = 1;a<=height;a++)
	{
		gtc(xstart,a+ystart);
		printf("\xB2\n");
	}

}


void addInventory()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	srand(time(NULL));
	int b = rand()%1000+1;
	inv1.itemID=0;
	inv1.price=0;
	system("cls");
	printBorders(95,31);
	printBox(5,4,85,23);
	gtc(36,6); printf("\xB2 ADD INVENTORY ITEMS \xB2");
	gtc(19,10);printf("\xb10");
	gtc(21,10);printf("Item Name: ");fgets(inv1.pName,sizeof(inv1.pName),stdin);nlfix(inv1.pName);
	gtc(19,10);printf(" ");
	gtc(19,12);printf("\xb10");
	gtc(21,12);printf("Item Price: ");scanf("%f",&inv1.price);
	gtc(19,12);printf(" ");
	
	inv1.itemID=b;	
	//save
	fi1=fopen("mainInv","ab+");
	fseek(fi1,0,SEEK_END);
	fwrite(&inv1,sizeof(inv1),1,fi1);
	fclose(fi1);
	gtc(29,16);printf("Successfully added item into inventory.");
	getch(); returN();
	menuInventory();
}

void greeting()
{
	system("cls");
	system("color a");
	printBorders1(95,31);
	gtc(41,14);printf("WELCOME TO");
	gtc(27,15); printf("CARL'S  S U P E R D U P E R  MARKET'S");
	gtc(40,16); printf("P-O-S SYSTEM");
	Sleep(500);	
}

void exitR()
{
	system("cls");
	printBorders(95,31);
	gtc(42,15);printf("exiting.");
	printBorders2(95,31);
	Sleep(500);exit(0);
}

void credits()
{
	char hi[]="CARL'S  S U P E R D U P E R  MARKET POS SYSTEM";
	char ma[]="MADE BY:";
	char rv[]="\xB02 John Rovic Vargas ";
	char ca[]="Carl Allones";
	char mc[]="Melle Christian Somera";
	char ky[]="Kyler Kanapi";
	char aa[]="Aaron Kent Alcala";
	char it[]="IT11KA3";
	system("cls");
	system("color a");
	printBorders(95,31);
	printBox(19,6,55,18);
	gtc(24,8);
	for(int a=0;a<=sizeof(hi)-1;a++)
	{
		printf("%c",hi[a]);
		Sleep(50);
	}
	Sleep(100);
	gtc(42,10);
	for(int b=0;b<=sizeof(ma)-1;b++)
	{
		printf("%c",ma[b]);
		Sleep(80);
	}
	Sleep(100);
	gtc(36,12);
	for(int c=0;c<=sizeof(rv)-1;c++)
	{
		printf("%c",rv[c]);
		Sleep(80);
	}
	Sleep(100);
	gtc(38,14);
	for(int d=0;d<=sizeof(aa)-1;d++)
	{
		printf("%c",aa[d]);
		Sleep(80);
	}
	Sleep(100);
	gtc(38,16);
	for(int e=0;e<=sizeof(mc)-1;e++)
	{
		printf("%c",mc[e]);
		Sleep(80);
	}
	Sleep(100);
	gtc(38,18);
	for(int f=0;f<=sizeof(ca)-1;f++)
	{
		printf("%c",ca[f]);
		Sleep(80);
	}
	Sleep(100);
	gtc(38,20);
	for(int g=0;g<=sizeof(ky)-1;g++)
	{
		printf("%c",ky[g]);
		Sleep(80);
	}
	gtc(38,22);
	for(int h=0;h<=sizeof(it)-1;h++)
	{
		printf("%c",it[h]);
		Sleep(80);
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	gtc(30,26); printf("Press any key to return to menu.");
	getch();
	returN();
	menu();
}

void menu()
{	
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	windowSize(96,32);
	int b=10;
	unsigned char a;
	system("cls");
	system("color 1f");
	printBorders(95,31);
	printBox(26,7,40,15);
	gtc(34,10);printf(" 1. Do Sales");
	gtc(34,12);printf(" 2. View Sales Report");
	gtc(34,14);printf(" 3. Manage Inventory");
	gtc(34,16);printf(" 4. Credits");
	gtc(34,18);printf(" 5. Exit Program");
	gtc(32,10); printf("\xb10");

	while(getch()!=13) //THIS PART OMG.
	{		
		a=getch();

		if (a==0 || a==0xE0) a=getch();
		
		if (a==27) 
			{
			break;
			}
		else if (a==72)
		{
			if(b!=10)
			{
				gtc(32,b);
				printf(" ");
				b-=2;
				gtc(32,b);
				printf("\xb10");
			}
			else
			{
				gtc(32,b);
				printf(" ");
				b+=8;
				gtc(32,b);
				printf("\xb10");
			}
		}
		else if (a==80)
			{
				if(b!=18)
				{
					gtc(32,b);
					printf(" ");
					b+=2;	
					gtc(32,b);
					printf("\xb10");
				}

			}		
	}
	switch(b)
	{
		case 10:
			sales();
			break;
		case 12:
			//viewsales();
			break;
		case 14:
			menuInventory();
			break;
		case 16:
			credits();
			break;
		case 18:
			exitR();
			break;
	}
}


void menuInventory()
{
	fclose(fdel);	
	fclose(fi1);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); fflush(stdin);
	system("cls");
	fclose(fi1);
	system("color 3f");
	printBorders(95,31);
	printline(95,4);
	gtc(30,2); printf("INVENTORY MANAGEMENT SYSTEM FOR POS");
	gtc(5,6); printf ("ID                       ITEM NAME                                     PRICE");
	fi1=fopen("mainInv","rb");
	int start=8;
	int twopage=0;
	while(fread(&inv1,sizeof(inv1),1,fi1)==1)
	{
		gtc(5,start);
		printf("%d",inv1.itemID);
		gtc(30,start);
		printf("%s",inv1.pName);
		gtc(76,start);
		printf("PHP %.2f",inv1.price);
		start++;
		if(start==29)
		{
			twopage=1;
			break;
		}
	}
	gtc(4,29); printf("\xb10"); gtc(6,29);printf("Add an Item.");
	gtc(26,29);printf("Delete an Item."); ; gtc(46,29);printf("Edit an Item.") ; gtc(66,29);printf("Go back to menu.");
	if (twopage==1)
	{


		gtc(30,3);printf("2nd Page available [PRESS DOWN ARROW]");
	}
	else
	{
	}
	int a,curs=4;
	while(getch()!=13) //THIS PART OMG.
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); fflush(stdin);			
		a=getch();

		if (a==0 || a==0xE0) a=getch();
		
		if (a==27) 
			{
			break;
			}
			
		else if (a==75)
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); fflush(stdin);			
			if(curs!=4)
			{
				gtc(curs,29);
				printf(" ");
				curs-=20;
				gtc(curs,29);
				printf("\xb10");
			}	
		}
		else if (a==77)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); fflush(stdin);				
				if (curs!=64)
				{
					gtc(curs,29);
					printf(" ");
					curs+=20;	
					gtc(curs,29);
					printf("\xb10");
				}
			}
		else if(a==80)
		{
			if(twopage==1)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); fflush(stdin);
				system("cls");
				system("color 3f");
				printBorders(95,31);
				printline(95,4);
				gtc(30,2); printf("INVENTORY MANAGEMENT SYSTEM FOR POS");
				gtc(5,6); printf ("ID                       ITEM NAME                                     PRICE");
				int start1=8;
				while(fread(&inv1,sizeof(inv1),1,fi1)==1)
				{
					gtc(5,start1);
					printf("%d",inv1.itemID);
					gtc(30,start1);
					printf("%s",inv1.pName);
					gtc(76,start1);
					printf("PHP %.2f",inv1.price);
					start1++;
				}
				int a1,curs1=4;
				while(getch()!=13) //THIS PART OMG.
				{		
					a1=getch();
			
					if (a1==0 || a1==0xE0) a1=getch();
		
					if (a1==27) 
						{
						break;
						}
					
					else if (a1==72)
					{
						menuInventory();
					}
				}
				}
		}
	}
	switch(curs)
	{
		case 4:
			addInventory();
			break;
		case 24:
			delInventory();
			break;
		case 44:
			editInventory();
			break;
		case 64:
			menu();
			exit(0);
			break;
	}
	getch();
}

int cID(int id) 
{
rewind(fi1);
while(fread(&inv1,sizeof(inv1),1,fi1)==1)
if(inv1.itemID==id)
return 0;  
return 1; 
}


int cIDs(int id) 
{
rewind(fsal);
while(fread(&sal1,sizeof(sal1),1,fsal)==1)
if(sal1.id==id)
return 0;  
return 1; 
}

void editInventory()	
{	
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); fflush(stdin);
	system("cls");
	printBorders(95,31);
	printBox(10,5,75,21);
	int fderp,found,id,loopZ=1;
	while(loopZ==1)
	{
		gtc(28,7);
		printf("Enter Item ID to be edited: ");
		scanf("%d",&id);
		fi1=fopen("mainInv","rb+");

		while(fread(&inv1,sizeof(inv1),1,fi1)==1)
		{
			if(cID(id)==0)
			{
				found=1;			
				gtc(14,10);printf("ITEM NAME: %s",inv1.pName);
				getchar();
				gtc(53,10);printf("Enter New Name: ");fgets(inv1.pName,sizeof(inv1.pName),stdin);
				gtc(14,11);printf("ITEM PRICE: PHP %.2f",inv1.price);
				gtc(53,11);printf("Enter New Price: ");scanf("%f",&inv1.price);
				nlfix(inv1.pName);

				fseek(fi1,ftell(fi1)-sizeof(inv1),0);
				fwrite(&inv1,sizeof(inv1),1,fi1);
				fclose(fi1);
				break;
				}
			if(found==0){
				gtc(37,15);
				printf("  NO ITEM FOUND.");
				if(getch())
				
				break;
			}
		}
	fclose(fi1);
	fflush(stdin);
	loopZ=0;
	menuInventory();
	}
}

void delInventory() 
{
	fclose(fdel);	
	fclose(fi1);
	system("cls");
	system("color 4f");
	printBorders(95,31);
	int fderp,found,id,loopZ=1;
	while(loopZ==1)
	{
		gtc(25,7);
		printf("Enter Item ID to be deleted: ");
		scanf("%d",&id);
		fi1=fopen("mainInv","rb+");
		rewind(fi1);
		while(fread(&inv1,sizeof(inv1),1,fi1)==1)
		{
			if(cID(id)==0)
			{
				found=1;
				gtc(25,10);
				printf("An item was matched with your ID. \n\n");
				gtc(25,12);
				printf("The Item's name is %s",inv1.pName);
			}
			if(found!=1)
			{
				gtc(25,10);
				printf("No record was found.");
				if(getch())
				menuInventory();
			}
			if(found==1)
			{
				gtc(25,15);
				printf("Do you want to delete it?(Y/N):");
			if(getch()=='y')
			{
				fdel=fopen("temp","wb+");  
				rewind(fi1);
				while(fread(&inv1,sizeof(inv1),1,fi1)==1)
				{	
					if(inv1.itemID!=id)
					{
						fseek(fdel,0,SEEK_CUR);
						fwrite(&inv1,sizeof(inv1),1,fdel); 
					}                             
				}
				fclose(fdel);	
				fclose(fi1);
				remove("mainInv");
				rename("temp","mainInv"); 
				fi1=fopen("mainInv","rb+");    
				if(found==1)
				{		
					gtc(25,18);
					printf("The item was sucessfully deleted");
					getch();
					menuInventory();

				}
			}
		else
			fflush(stdin);
			getch();
			fclose(fdel);	
			fclose(fi1);			
		}
	}
	fclose(fdel);	
	fclose(fi1);
}

}

void printsales()
{
	fclose(fsal);
	fsal=fopen("tempsales","rb+");
	gtc(5,5);printf("sID     NAME          PRICE");
	int start=7;
	while(fread(&sal1,sizeof(sal1),1,fsal)==1)
	{
		gtc(5,start);printf("%d",sal1.id);
		gtc(13,start);printf("%dx %s",sal1.quan,sal1.name);
		gtc(27,start);printf("%.2f",sal1.price);
		start++;
	}
	gtc(46,24);printf("Total Quantity: %d",sal1.totalquan);
	gtc(46,26);printf("Total Price: PHP %.2f",sal1.total);
	fclose(fsal);
}

void sales()
{	
	system("cls");
	fclose(fsal);
	fclose(fi1);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	printBorders(95,31);
	system("color 8f");
	gtc(40,2); printf("S  A  L  E  S");
	printBox(3,4,35,25);
	printsales();
	printBox(42,11,50,8);
	printBox(42,22,50,7);
	printBox(42,4,50,4); gtc(47,6); printf("Add Items"); gtc(60,6); printf("Void Items"); gtc(73,6); printf("Checkout"); gtc(86,6); printf("Exit");
	gtc(53,14);printf("Choose from the options above.");
	gtc(45,6); printf("\xb10");
	int a,b=45;
	while(getch()!=13) //THIS PART OMG.
	{		
		a=getch();

		if (a==0 || a==0xE0) a=getch();
		
		if (a==27) 
			{
			break;
			}
		else if (a==75)
		{
			if(b!=45)
			{
				gtc(b,6);
				printf(" ");
				b-=13;
				gtc(b,6);
				printf("\xb10");
			}
		}
		else if (a==77)
			{
				if(b!=84)
				{
					gtc(b,6);
					printf(" ");
					b+=13;
					gtc(b,6);
					printf("\xb10");
				}

			}		
	}
	switch(b)
	{
		case 45:
			gtc(53,14);printf("                                  ");
			additem();
			break;
		case 58:
			gtc(53,14);printf("                                  ");
			voiditem();
			break;
		case 71:
			gtc(53,14);printf("                                  ");
		//	checkout();
			break;
		case 84:
			menu();
			exit(0);
			break;
	}
	getch();
	
	
}

void additem()
{
	sal1.id=0;
	sal1.price=0;
	sal1.quan=0;
	int id;
	gtc(45,13);printf("Input Item ID: ");scanf("%d",&id);
	fi1=fopen("mainInv","rb+");
	while(fread(&inv1,sizeof(inv1),1,fi1)==1)
	{
	if (cID(id)==0)
	{
		gtc(45,14);printf("Item Matched! \(%s)",inv1.pName);
		gtc(45,15);printf("Input Quantity: ");scanf("%d",&sal1.quan);
		for(int a=0;a<=6;a++)
		{
			sal1.name[a]=inv1.pName[a];
		}
		sal1.id=inv1.itemID+1;
		sal1.totalquan+=sal1.quan;	
		sal1.price=inv1.price*sal1.quan;
		sal1.total+=sal1.price;
		fsal=fopen("tempsales","ab+");
		fseek(fsal,0,SEEK_END);
		fwrite(&sal1,sizeof(sal1),1,fsal);
		fclose(fsal);
		gtc(45,16);printf("Added %d of %s",sal1.quan,inv1.pName);	getch();			
		sales();exit(0);
	}
	else
	{
		gtc(45,15);printf("No such item was found");
		getch();
		sales();exit(0);
	}
}
}

void voiditem()
{
	int id,f=0,loopZ=1;
	while(loopZ==1)
	{
	gtc(45,13);printf("Input Item sID: ");scanf("%d",&id);
	fsal=fopen("tempsales","rb+"); rewind(fsal);
	while(fread(&sal1,sizeof(sal1),1,fsal)==1)
	{
		if(cIDs(id)==0)
		{
			f=1;
		}
		if(f!=1)
		{
			gtc(45,5);printf("No item was found with the sID.");		getch();
			sales(); exit(0);	
		}
		if(f==1)
		{
			gtc(45,14);printf("Are you sure you want to delete %s",sal1.name);gtc(45,15);printf("from the invoice? (Y/N): ");
			if (getch()=='y')
			{
				fsaldel=fopen("saltemp","wb+");
				rewind(fsal);
				while(fread(&sal1,sizeof(sal1),1,fsal)==1)
				{	
					if(sal1.id!=id)
					{
						fseek(fsaldel,0,SEEK_CUR);
						fwrite(&sal1,sizeof(sal1),1,fsaldel); 
					}                             
				}
				fclose(fsaldel);	
				fclose(fsal);
				remove("tempsales"); 
				rename("saltemp","tempsales");
				fsal=fopen("tempsales","rb+");    
				if(f==1)
				{		
					gtc(45,16);
					printf("The item was sucessfully deleted");
					getch();
					sales(); exit(0);

				}
			}
		}
		else
		fflush(stdin);
		getch();
		fclose(fsaldel);	
		fclose(fsal);
	}
}
}
	




int main()
{
	windowSize(96,32);
	//delInventory();
	sales();
	//greeting();
	//menu();
	return 0;
}
