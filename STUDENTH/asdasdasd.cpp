#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//restructured

void oor();
void ssmith();
int main();
int c1, c2, c3, c4, c5, c6;
int rnumber=1;

struct reserve
{
	float tp, vs, vat, change, m;
	int  d, g, f;
	char a[50], b[50], c[50], e[50], date[30], time[20], edate[30];	
}; struct reserve r[40];

void oor()
{
	r[rnumber].m=0;
	printf("%d",rnumber);
	printf("\n\t\t\t    ONE OK ROCK LIVE IN MANILA");
    printf("\n\n\t\t==================================================\n\t\t\t\t||\t\t||\n");
    printf("\t\tTYPE OF TICKET\t||     PRICE    || AVAILABLE SEATS\n");
    printf("\t\t\t\t||\t\t||");
    printf("\n\t\t1. VIP Seated\t||   Php 4500\t||\t250");
    printf("\n\t\t\t\t||\t\t||\n\t\t2. VIP Standing\t||   Php 4500\t||\t250");
    printf("\n\t\t\t\t||\t\t||\n\t\t3. Lower Box A\t||   Php 3500\t||\t3000");
    printf("\n\t\t\t\t||\t\t||\n\t\t4. Lower Box B\t||   Php 2500\t||\t5000");
    printf("\n\t\t\t\t||\t\t||\n\t\t5. Lower Box C\t||   Php 1500\t||\t6500");
    printf("\n\t\t\t\t||\t\t||\n\t\t==================================================");
    printf("\n\t\tEnter your choice:");
    scanf("%d", &c2);
    printf("\n\t\tHow many tickets do you want to reserve?");
    scanf("%d", &c3);
    if(c2==1)
    {
 		r[rnumber].tp=c3*4500;
 		printf("\n\t\tThe total price is Php %.2f", r[rnumber].tp);
    }
    else if(c2==2)
    {
         r[rnumber].tp=c3*4500;
         printf("\n\t\tThe total price is Php %.2f", r[rnumber].tp);
    }
    else if(c2==3)
    {
         r[rnumber].tp=c3*3500;
         printf("\n\t\tThe total price is Php %.2f", r[rnumber].tp);
    }
    else if(c2==4)
    {
         r[rnumber].tp=c3*2500;
         printf("\n\t\tThe total price is Php %.2f", r[rnumber].tp);
    }
    else if(c2==5)
    {
         r[rnumber].tp=c3*1500;
         printf("\n\t\tThe total price is Php %.2f", r[rnumber].tp);
    }
    else
    {
         printf("Invalid input");
    }
    printf("\n\n\t\tProceed to payment?");
    printf("\n\t\t\t1. Yes");printf("\n\t\t\t2. No\n\t\t");
    printf("Enter your choice:");
    scanf("%d", &c4);	
	system("cls");
    if(c4==1)
    {
 		printf("\n\t\tChoose mode of payment:");
 		printf("\n\n\t\t\t1. Cash");printf("\n\t\t\t2. Credit Card");
 		printf("\n\n\t\tEnter your choice:");
 		scanf("%d", &c5);}
 		printf("\n\n\t\t==================================================");
 		if(c5==1)
 		{
          while (r[rnumber].m<r[rnumber].tp)
          {
     		printf("\n\n\t\tEnter your amount of money: Php ");
      		scanf("%f", &r[rnumber].m);
   		    if(r[rnumber].m<r[rnumber].tp){
  	 			printf("\n\t\tNot enough money");
  			}
          }
          system("cls");
          printf("\n\n\t\tBreakdown of Payment:");
          if(c2==1)
          {
      		 printf("\n\n\t\tType of ticket: \t  VIP Seated (Php 4500)");
          }
          else if(c2==2)
          {
   				printf("\n\n\t\tType of ticket: \t  VIP Standing (Php 4500)");
          }
          else if(c2==3)
          {
   			printf("\n\n\t\tType of ticket: \t  Lower Box A (Php 3500)");
          }
          else if(c2==4)
          {
  			 printf("\n\n\t\tType of ticket: \t  Lower Box B (Php 2500)");
          }
          else if(c2==5)
          {
  			 printf("\n\n\t\tType of ticket: \t  Lower Box C (Php 1500)");
          }
          else
          {
  			 printf("Invalid");
          }
          printf("\n\t\tNumber of tickets bought: %d", c3);
          r[rnumber].vs=r[rnumber].tp*.88;
          printf("\n\t\tVAT Sales: \t\t  Php %.2f", r[rnumber].vs);
          r[rnumber].vat=r[rnumber].tp*.12;
          printf("\n\t\t12%% VAT: \t\t  Php %.2f", r[rnumber].vat);
          printf("\n\n\t\t==================================================");
          printf("\n\n\t\tAmount Due: \t\t  Php %.2f", r[rnumber].tp);
          printf("\n\n\t\tCash: \t\t\t  Php %.2f", r[rnumber].m);
          r[rnumber].change=r[rnumber].m-r[rnumber].tp;
          printf("\n\n\t\tChange: \t\t  Php %.2f", r[rnumber].change);
          printf("\n\n\t\t==================================================");
          printf("\n\n\t\tIs this okay?\n\t\t1. Yes\t\t2. No\n\t\t");
          scanf("%d", &c6);
          system("cls");
          if(c6==1)
          {
          printf("\n\n\t\tPlease fill in these fields regarding your profile\n\t\tto complete your reservation:");
          printf("\n\n\t\t==================================================");
          printf("\n\n\t\tFirst Name:"); scanf("%s", &r[rnumber].a);
          printf("\n\t\tMiddle Initial:"); scanf("%s", &r[rnumber].b);
          printf("\n\t\tLast Name:"); scanf("%s", &r[rnumber].c);
          printf("\n\t\tContact Number:"); scanf("%d", &r[rnumber].d);
          printf("\n\t\tAddress:"); scanf("%s", &r[rnumber].e);
          printf("\n\t\tDate(MM/DD/YY):"); scanf("%s", &r[rnumber].date);
          printf("\n\t\tTime(HH:MM AM/PM):"); scanf("%s", &r[rnumber].time);
			}//c6==1
        else if(c6==2)
		{
     		printf("\n\n\t\tProceed to menu?");
     		main();
		}//c6==2
 		 system("cls");
  		printf("\n\n\t\tSuccessfully Reserved.");
 		 printf("\n\n\t\tIMPORTANT NOTE:\n\n\t\tIf payment is not done within 72 hours (3 days)\n\t\tyour reservation will be cancelled.");
 		 rnumber++;
 		 printf("\n\nPress any key to continue..");getch();
		  system("cls");
 		 main();
  }//c5==1
  else if(c5==2)
  {
       printf("\n\t\tPlease fill in these required information:");
       printf("\n\n\t\t==================================================");
       printf("\n\t\t1.Visa    2.Master card    3.Paypal");
       printf("\n\n\t\tChoose the type of Credit Card:");
       scanf("%d", &r[rnumber].f);
       printf("\n\t\tCredit Card number:"); scanf("%s", &r[rnumber].g);
       printf("\n\t\tExpiry Date(MM/DD/YY):"); scanf("%s", &r[rnumber].edate);
       system("cls");
       printf("\n\n\t\tBreakdown of Payment:");
            if(c2==1)
{
         printf("\n\n\t\tType of ticket: \t  VIP Seated (Php 4500)");
}
            else if(c2==2)
{
     printf("\n\n\t\tType of ticket: \t  VIP Standing (Php 4500)");
}
            else if(c2==3)
{
     printf("\n\n\t\tType of ticket: \t  Lower Box A (Php 3500)");
}
            else if(c2==4)
{
     printf("\n\n\t\tType of ticket: \t  Lower Box B (Php 2500)");
}
            else if(c2==5)
{
     printf("\n\n\t\tType of ticket: \t  Lower Box C (Php 1500)");
}
            else
{
     printf("Invalid");
}
            printf("\n\t\tNumber of tickets bought: %d", c3);
            r[rnumber].vs=r[rnumber].tp*.88;
            printf("\n\t\tVAT Sales: \t\t  Php %.2f", r[rnumber].vs);
            r[rnumber].vat=r[rnumber].tp*.12;
            printf("\n\t\t12%% VAT: \t\t  Php %.2f", r[rnumber].vat);
            printf("\n\n\t\t==================================================");
            printf("\n\n\t\tAmount Due: \t\t  Php %.2f", r[rnumber].tp);
            printf("\n\n\t\t==================================================");
            printf("\n\n\t\tIs this okay?\n\t\t1. Yes\t\t2. No\n\t\t");
            scanf("%d", &c6);
            system("cls");
            if(c6==1)
{
         printf("\n\t\tCard Holder's Profile:");
         printf("\n\n\t\t==================================================");
         printf("\n\n\t\tFirst Name:"); scanf("%s", &r[rnumber].a);
         printf("\n\t\tMiddle Initial:"); scanf("%s", &r[rnumber].b);
         printf("\n\t\tLast Name:"); scanf("%s", &r[rnumber].c);
         printf("\n\t\tContact Number:"); scanf("%d", &r[rnumber].d);
         printf("\n\t\tAddress:"); scanf("%s", &r[rnumber].e);
         printf("\n\t\tDate(MM/DD/YY):"); scanf("%s", &r[rnumber].date);
         printf("\n\t\tTime(HH:MM AM/PM):"); scanf("%s", &r[rnumber].time);
         system("cls");
         printf("\n\n\t\tSuccessfully Reserved.");
         rnumber++;
}//c6==1//
            if(c6==2)
{
         printf("\n\t\tReturn to menu?");
}//c6==2//
       }//c5==2//
  //c4==1
    else if(c4==2)
    {
         printf("\n\t\tProceed to menu?");
    }//c4==2
}

void rlist()
{
/*sa reservation list eto ung ilagay mo: reservation no., start date, end date, name, concert, ticket type, tickets bought*/	
system("cls");
	for (int i =1;i<=40;i++)
	{
		
			printf("%.2f\n",r[i-1].tp);

	}
}

/*void ssmith()
{
	           printf("\n\t\tSam Smith in the Lonely Hour Tour Live in Manila");
               printf("\n\n\t\t==================================================\n\t\t\t\t||\t\t||\n");
               printf("\t\tTYPE OF TICKET\t||     PRICE    || AVAILABLE SEATS\n");
               printf("\t\t\t\t||\t\t||");
               printf("\n\t\t1. Patron\t||   Php 6830\t||\t500");
               printf("\n\t\t\t\t||\t\t||\n\t\t2. Lower Box\t||   Php 4730\t||\t2500");
               printf("\n\t\t\t\t||\t\t||\n\t\t3. Upper Box\t||   Php 2100\t||\t3500");
               printf("\n\t\t\t\t||\t\t||\n\t\t4. Gen.Admission||   Php 1050\t||\t5500");
               printf("\n\t\t\t\t||\t\t||\n\t\t==================================================");
               printf("\n\t\tEnter your choice:");
               scanf("%d", &c2);
               printf("\n\t\tHow many tickets do you want to reserve?");
               scanf("%d", &c3);
               if(c2==1)
               {
                        tp=c3*6830;
                        printf("\n\t\tThe total price is Php %.2f", tp);
               }
               else if(c2==2)
               {
                    tp=c3*4730;
                    printf("\n\t\tThe total price is Php %.2f", tp);
               }
               else if(c2==3)
               {
                    tp=c3*2100;
                    printf("\n\t\tThe total price is Php %.2f", tp);
               }
               else if(c2==4)
               {
                    tp=c3*1050;
                    printf("\n\t\tThe total price is Php %.2f", tp);
               }
               else
               {
                     printf("Invalid input");
               }
                printf("\n\n\t\tProceed to payment?");
                printf("\n\t\t\t1. Yes");printf("\n\t\t\t2. No\n\t\t");
                printf("Enter your choice:");
                scanf("%d", &c4);
                system("cls");
                if(c4==1)
                {
                         printf("\n\t\tChoose mode of payment:");
                         printf("\n\n\t\t\t1. Cash");printf("\n\t\t\t2. Credit Card");
                         printf("\n\n\t\tEnter your choice:");
                         scanf("%d", &c5);}
                         printf("\n\n\t\t==================================================");
                         if(c5==1)
                         {
                                  while (m<tp)
                                  {
                                          printf("\n\n\t\tEnter your amount of money: Php ");
                                          scanf("%f", &m);
                                          if(m<tp){
                                                   printf("\n\t\tNot enough money");
                                                   }
                                  }
                                  system("cls");
                                  printf("\n\n\t\tBreakdown of Payment:");
                                  if(c2==1)
                                  {
                                           printf("\n\n\t\tType of ticket: \t  Patron (Php 6830)");
                                  }
                                  else if(c2==2)
                                  {
                                       printf("\n\n\t\tType of ticket: \t  Lower Box (Php 4730)");
                                  }
                                  else if(c2==3)
                                  {
                                       printf("\n\n\t\tType of ticket: \t  Upper Box (Php 2100)");
                                  }
                                  else if(c2==4)
                                  {
                                       printf("\n\n\t\tType of ticket: \t  Gen.Admission (Php 1050)");
                                  }
                                  else
                                  {
                                       printf("Invalid");
                                  }
                                  printf("\n\t\tNumber of tickets bought: %d", c3);
                                  vs=tp*.88;
                                  printf("\n\t\tVAT Sales: \t\t  Php %.2f", vs);
                                  vat=tp*.12;
                                  printf("\n\t\t12%% VAT: \t\t  Php %.2f", vat);
                                  printf("\n\n\t\t==================================================");
                                  printf("\n\n\t\tAmount Due: \t\t  Php %.2f", tp);
                                  printf("\n\n\t\tCash: \t\t\t  Php %.2f", m);
                                  change=m-tp;
                                  printf("\n\n\t\tChange: \t\t  Php %.2f", change);
                                  printf("\n\n\t\t==================================================");
                                  printf("\n\n\t\tIs this okay?\n\t\t1. Yes\t\t2. No\n\t\t");
                                  scanf("%d", &c6);
                                  system("cls");
                                  if(c6==1)
                                  {
                                              printf("\n\n\t\tPlease fill in these fields regarding your profile\n\t\tto complete your reservation:");
                                              printf("\n\n\t\t==================================================");
                                              printf("\n\n\t\tFirst Name:"); scanf("%s", &a);
                                              printf("\n\t\tMiddle Initial:"); scanf("%s", &b);
                                              printf("\n\t\tLast Name:"); scanf("%s", &c);
                                              printf("\n\t\tContact Number:"); scanf("%d", &d);
                                              printf("\n\t\tAddress:"); scanf("%s", &e);
                                              printf("\n\t\tDate(MM/DD/YY):"); scanf("%s", &date);
                                              printf("\n\t\tTime(HH:MM AM/PM):"); scanf("%s", &time);
                                    }//c6==1
                                    else if(c6==2)
                                    {
                                         printf("\n\n\t\tProceed to menu?");
                                    }//c6==2
                          system("cls");
                          printf("\n\n\t\tSuccessfully Reserved.");
                          printf("\n\n\t\tIMPORTANT NOTE:\n\n\t\tIf payment is not done within 72 hours (3 days)\n\t\tyour reservation will be cancelled.");
                          }//c5==1
                          else if(c5==2)
                          {
                               printf("\n\t\tPlease fill in these required information:");
                               printf("\n\n\t\t==================================================");
                               printf("\n\t\t1.Visa    2.Master card    3.Paypal");
                               printf("\n\n\t\tChoose the type of Credit Card:");
                               scanf("%d", &f);
                               printf("\n\t\tCredit Card number:"); scanf("%s", &g);
                               printf("\n\t\tExpiry Date(MM/DD/YY):"); scanf("%s", &edate);
                               system("cls");
                               printf("\n\n\t\tBreakdown of Payment:");
                                    if(c2==1)
                                    {
                                             printf("\n\n\t\tType of ticket: \t  Patron (Php 6830)");
                                    }
                                    else if(c2==2)
                                    {
                                         printf("\n\n\t\tType of ticket: \t  Lower Box (Php 4730)");
                                    }
                                    else if(c2==3)
                                    {
                                         printf("\n\n\t\tType of ticket: \t  Upper Box (Php 2100)");
                                    }
                                    else if(c2==4)
                                    {
                                         printf("\n\n\t\tType of ticket: \t  Gen.Admission (Php 1050)");
                                    }
                                    else
                                    {
                                         printf("Invalid");
                                    }
                                    printf("\n\t\tNumber of tickets bought: %d", c3);
                                    vs=tp*.88;
                                    printf("\n\t\tVAT Sales: \t\t  Php %.2f", vs);
                                    vat=tp*.12;
                                    printf("\n\t\t12%% VAT: \t\t  Php %.2f", vat);
                                    printf("\n\n\t\t==================================================");
                                    printf("\n\n\t\tAmount Due: \t\t  Php %.2f", tp);
                                    printf("\n\n\t\t==================================================");
                                    printf("\n\n\t\tIs this okay?\n\t\t1. Yes\t\t2. No\n\t\t");
                                    scanf("%d", &c6);
                                    system("cls");
                                    if(c6==1)
                                    {
                                             printf("\n\t\tCard Holder's Profile:");
                                             printf("\n\n\t\t==================================================");
                                             printf("\n\n\t\tFirst Name:"); scanf("%s", &a);
                                             printf("\n\t\tMiddle Initial:"); scanf("%s", &b);
                                             printf("\n\t\tLast Name:"); scanf("%s", &c);
                                             printf("\n\t\tContact Number:"); scanf("%d", &d);
                                             printf("\n\t\tAddress:"); scanf("%s", &e);
                                             printf("\n\t\tDate(MM/DD/YY):"); scanf("%s", &date);
                                             printf("\n\t\tTime(HH:MM AM/PM):"); scanf("%s", &time);
                                             system("cls");
                                             printf("\n\n\t\tSuccessfully Reserved.");
                                    }//c6==1//
                                    if(c6==2)
                                    {
                                             printf("\n\t\tReturn to menu?");
                                    }//c6==2//
                               }//c5==2//
                          }//c4==1
                else if(c4==2)
                {
                     printf("\n\t\tProceed to menu?");
                }//c4==2//c1==2//
      getch();
}*/



main()
{
	  printf("%.2f",r[rnumber-1].tp);
	  printf("\t\t==========RPG's Ticket Distribution Inc.==========\n\n");
      printf("\t\t\tUPCOMING CONCERTS IN THE PHILIPPINES:\n"); 
      printf("\n\n\t\t1. ONE OK ROCK Live in Manila\n\t\t(January 19, 2016 at Mall of Asia Arena)");
      printf("\n\n\t\t2. Sam Smith in the Lonely Hour Tour Live in Manila\n\t\t(November 12, 2015 at Mall of Asia Arena)");
      printf("\n\n\t\t==================================================");
      printf("\n\n\t\tEnter your choice: ");
      scanf("%d", &c1);
      system("cls"); 
      if(c1==1)
      {   
            oor();
	}
      else if(c1==2)
      {
              // ssmith();
           }
       else if(c1==3)
       {
       	rlist();
	   }
      getch();

}


