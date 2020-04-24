#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void admin_menu();
void menu();
void menu2();
void new_acc1();
void edit1();
void details_vehicle();
void erase();
void view_list1();
void close();

struct date
    {
    int day,month,year;
    };
struct registration
   {
    char name[60];
    int vehicle_no,age;
    char color[60];
    char owner[30];
    double phone;
    char vehicle_type[10];
    struct date deposit;

    }add,upd,check,rem;

int main()
{
    int choice;

        printf("\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  WELCOME  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        printf("\n\n\t\t\t\t\t1.ACCOUNT LOGIN\n\n\t\t\t\t\t2.EXIT PROGRAM\n\n\t\t\tPLEASE ENTER YOUR CHOICE(Press 1 or 2) TO PROCEED: \t");
        scanf("%d",&choice);

            if (choice==1)
                    {
                    system("cls");
                    admin_menu();
                    }

            else if (choice==2)
                    {
                    system("cls");
                   close();
                    }

return 0;


}


void admin_menu()
{


 char pass[11],password[11]="ishrak";
    int i=0;
    printf("\n\n\t\t\t\t\xdb\xdb\xdb ENTER YOUR ACCOUNT PASSWORD TO CONTINUE \xdb\xdb\xdb");
    printf("\n\n\t\t\t\t\tPASSWORD: \t");
    scanf("%s",pass);



    if (strcmp(pass,password)==0)
        {printf("\n\n\t\t\xdb\xdb PASSWORD MATCH \xdb\xdb\n\n");

                system("cls");
            menu();
        }
    else
        {
            printf("\n\n\t\t\t\t\t\t\xdb\xdb WRONG PASSWORD \xdb\xdb\a\a\a");
            login_try:
            printf("\n\n\t\t\t\tENTER 1 TO TRY AGAIN\n\t\t\t\tENTER 0 TO EXIT PROGRAM\n\t\t\t\tENTER YOUR CHOICE:\t");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        admin_menu();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nINVALID!");

                    system("cls");
                    goto login_try;}

        }


}



void menu()
{
    int choice;
    system("cls");
    printf("\n\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  PARKING LOT MANAGEMENT SYSTEM  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\n\n\t\t\t\t  \xdb\xdb\xdb\xdb\xdb WELCOME TO THE MAIN MENU \xdb\xdb\xdb\xdb\xdb ");
    printf("\n\n\n\t\t\t\t\t1.VEHICLE INFORMATION\n\n\n\t\t\t\t\t2.EXIT PROGRAM\n\n\n\n\t\t\t\tENTER CHOICE( 1 or 2 ): \t");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:menu2();
        break;
        case 2:close();
        break;

    }


}



void menu2()
{
     int choice;
    system("cls");
    printf("\n\n\t\t\t\t\xdb\xdb\xdbPARKING LOT MANAGEMENT SYSTEM\xdb\xdb\xdb");
    printf("\n\n\n\t\t\t\t\xdb\xdb\xdb THE MENU OF PARKED VEHICLES \xdb\xdb\xdb");
    printf("\n\n\n\n\n\t\t\t\t1.NEW ENTRY\n\n\t\t\t\t2.EDIT INFORMATION OF PREVIOUSLY ENTERED VEHICLE INFORMATION\n\n\t\t\t\t3.CHECK DETAILS OF ANY PARKED VEHICLE\n\n\t\t\t\t4.VEHICLE DEPARTURE\n\n\t\t\t\t5.LIST OF VEHICLES\n\n\t\t\t\t6.EXIT PROGRAM\n\n\n\t\t\t\tENTER YPUR CHOICE:\t");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc1();
        break;
        case 2:edit1();
        break;
        case 3:details_vehicle();
        break;
        case 4:erase();
        break;
        case 5:view_list1();
        break;
        case 6:close();
        break;

    }
}

void new_acc1()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.txt","a+");
    car_no:
    system("cls");
    printf("\n\n\n\t\t\t\xdb\xdb\xdb ADD RECORD \xdb\xdb\xdb ");
    printf("\n\n\n\t\tENTER TODAY'S DATE(DD/MM/YYYY):\t ");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\n\n\t\tENTER VEHICLE NUMBER:\t");
    scanf("%d",&check.vehicle_no);
    add.vehicle_no=check.vehicle_no;
    printf("\n\t\tENTER DRIVER NAME:\t");
    fflush(stdin);
    scanf("%[^\n]s",add.name);
    printf("\n\t\tENTER OWNER NAME( For Vehicles Driven By Owner Repeat Driver Name ):\t");
    fflush(stdin);
    scanf("%s",add.owner);
    printf("\n\t\tENTER PHONE NUMBER:\t ");
    fflush(stdin);
    scanf("%lf",&add.phone);
    fflush(stdin);
    printf("\n\t\tTYPE OF VEHICLE(SEDAN/COUPE/CONVERTIBLE/SUV/BIKE):\t");
    scanf("%s",add.vehicle_type);
    printf("\n\t\tENTER VEHICLE COLOR:\t");
    fflush(stdin);
    scanf("%[^\n]s",add.color);
    printf("\n\t\tENTER THE NUMBER OF PASSENGER IN THE CAR:\t");
    scanf("%d",&add.age);

        fprintf(ptr,"\n%d %s %s %lf %s %s %d \n",add.vehicle_no,add.name,add.owner,add.phone,add.vehicle_type,add.color,add.age);


    fclose(ptr);
    printf("\n\t\t\t\xdb VEHICLE REGISTRATION SUCCESSFUL! \xdb");
    add_invalid:
    printf("\n\n\n\t\t\t\t ENTER 1 TO GO TO MAIN MENU AND 0 TO EXIT PROGRAM:\t");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\n\n\t\tINVALID!\a");
            goto add_invalid;
        }
}



void edit1()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("\n\n\n\n\t\t\tTO EDIT VEHICLE INFORMATION GIVE VEHICLE NUMBER:\t");
    scanf("%d",&upd.vehicle_no);
    while(fscanf(old,"\n%d %s %s %lf %s %s %d \n",&add.vehicle_no,add.name,add.owner,&add.phone,add.vehicle_type,add.color,&add.age)!=EOF)
    {
        if (add.vehicle_no==upd.vehicle_no)
        {   test=1;
            printf("\n\n\n\t\t\tWHICH INFORMATION DO YOU WANT TO CHANGE?\n\n\t\t1.NUMBER OF PASSENGER.\n\n\t\t2.PHONE NUMBER.\n\n\t\t\tENTER YOUR CHOICE(Press 1 or 2 ):\t");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("RE-ENTER PASSENGER AMOUNT:\t");
                scanf("%s",upd.age);
                fprintf(newrec,"\n%d %s %s %lf %s %s %d \n",add.vehicle_no,add.name,add.owner,add.phone,add.vehicle_type,add.color,add.age);
                system("cls");
                printf("\n\n\t\t\tCHANGES SAVED");
                }
            else if(choice==2)
                {
                    printf("RE-ENTER PHONE NUMBER:\t");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"\n%d %s %s %lf %s %s %d \n",add.vehicle_no,add.name,add.owner,add.phone,add.vehicle_type,add.color,add.age);
                system("cls");
                printf("\n\n\t\t\tCHANGES SAVED");
                }

        }
        else
            fprintf(newrec,"\n%d %s %s %lf %s %s %d \n",add.vehicle_no,add.name,add.owner,add.phone,add.vehicle_type,add.color,add.age);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");

if(test!=1)
        {   system("cls");
            printf("\n\n\n\t\t\xdb\xdb COULDN'T FIND RECORD \xdb\xdb\a\a\a");
            edit_invalid:
              printf("\n\n\t\t\tENTER 0 TO TRY AGAIN\n\t\t\tENTER 1 TO GO BACK TO MAIN MENU\n\t\t\tENTER 2 TO EXIT PROGRAM\n\n\t\t\tCHOICE >\t");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit1();
                else
                    {printf("\nINVALID\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nPRESS 1 TO GO BACK TO MAIN MENU AND 0 TO EXIT PROGRAM:\t");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}



void details_vehicle()
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.txt","r");
    printf("\n\n\t\t\tHOW DO YOU WANT TO CHECK THE VEHICLE INFORMATION?\n\n\t\t\t1.BY VEHICLE NUMBER\n\n\t\t\t2.BY NAME\n\n\n\t\t\tENTER YOUR CHOICE:\t");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\t\t\tENTER VEHICLE NUMBER:\t");
        scanf("%d",&check.vehicle_no);

        while (fscanf(ptr,"\n%d %s %s %lf %s %s %d \n",&add.vehicle_no,add.name,add.owner,&add.phone,add.vehicle_type,add.color,&add.age)!=EOF)
        {
            if(add.vehicle_no==check.vehicle_no)
            {   system("cls");
                test=1;

                printf("\n\n\t\t\t1.VEHICLE NUMBER:\t%d\n\n\t\t\t2.NAME:\t%s\n\n\t\t\t3.DATE OF ENTRY:\t%d/%d/%d\n\n\t\t\t4.OWNER:\t%s\n\n\t\t\t5.VEHICLE TYPE:\t%s\n\n\t\t\t6.VEHICLE COLOR:\t%s\n\n\t\t\t7.AMOUNT OF PASSENGER IN THE VEHICLE:\t%d\n",add.vehicle_no,add.name,add.deposit.day,add.deposit.month,add.deposit.year,add.owner,add.vehicle_type,add.color,add.age);

            }

            }
        }

    else if (choice==2)
    {   printf("\n\t\t\tENTER THE NAME:\t");
        scanf("%s",check.name);
        while (fscanf(ptr,"\n%d %s %s %lf %s %s %d \n",&add.vehicle_no,add.name,add.owner,&add.phone,add.vehicle_type,add.color,&add.age)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\n\n\t\t\t1.VEHICLE NUMBER:\t%d\n\n\t\t\t2.NAME:\t%s \n\n\t\t\t3.DATE OF ENTRY:\t%d/%d/%d\n\n\t\t\t4.OWNER:\t%s \n\n\t\t\t5.VEHICLE TYPE:\t%s \n\n\t\t\t6.VEHICLE COLOR:\t%s \n\n\t\t\t7.AMOUNT OF PASSENGER IN THE VEHICLE:\t%d \n",add.vehicle_no,add.name,add.deposit.day,add.deposit.month,add.deposit.year,add.owner,add.vehicle_type,add.color,add.age);

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\n\n\t\t\tRECORD NOT FOUND!!\a\a\a");
            see_invalid:
              printf("\n\t\tENTER 0 TO TRY AGAIN\n\t\tENTER 1 TO RETURN TO MAIN MENU\n\t\tENTER 2 TO EXIT\n\t\tENTER YOUR CHOICE:\t");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    details_vehicle();
                else
                    {
                        system("cls");
                        printf("\nINVALID!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nENTER 1 TO GO TO MAIN MENU AND 0 TO EXIT:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}




void erase()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("\n\n\tENTER VEHICLE NUMBER THAT DEPARTED:\t");
    scanf("%d",&rem.vehicle_no);
    while (fscanf(old,"\n%d %s %s %lf %s %s %d \n",&add.vehicle_no,add.name,add.owner,&add.phone,add.vehicle_type,add.color,&add.age)!=EOF)
   {
        if(add.vehicle_no!=rem.vehicle_no)
            fprintf(newrec,"\n%d %s %s %lf %s %s %d \n",add.vehicle_no,add.name,add.owner,add.phone,add.vehicle_type,add.color,add.age);

        else
            {test++;
            printf("\n\n\t\tENTRY OF VEHICLE NUMBER: %d HAS BEEN DELETED\n",rem.vehicle_no);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test==0)
        {
            printf("\n\t\tRECORD NOT FOUND\a\a\a");
            erase_invalid:
              printf("\n\n\n\t\tENTER 0 TO TRY AGAIN\n\t\tENTER 1 TO RETURN TO MAIN MENU\n\t\tENTER 2 TO EXIT PROGRAM\n\n\t\tGIVE YOUR CHOICE:\t");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nINVALID\a");
                    goto erase_invalid;}
        }
    else
        {printf("\n\n\t\tENTER 1 TO GO TO MAIN MENU\n\t\tENTER 0 TO EXIT PROGRAM\n\n\t\tGIVE YOUR CHOICE:\t");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}




void view_list1()
{
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    printf("\nVEHICLE. NO.\tNAME\t\t\tVEHICLE TYPE\t\tPHONE\n");

    while(fscanf(view,"\n%d %s %s %lf %s %s %d \n",&add.vehicle_no,add.name,add.owner,&add.phone,add.vehicle_type,add.color,&add.age)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.vehicle_no,add.name,add.vehicle_type,add.phone);
           test++;

       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nENTER 1 TO GO TO MAIN MENU AND 0 TO EXIT:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nINVALID!\a");
            goto view_list_invalid;
        }
}

void close()
{
    printf("\n\n\t\t\xdb\xdb THIS PROJECT IS CREATED BY \xdb\xdb \n\n\t\t\xdb\xdb T.M.ISHRAK HUSSAIN \xdb\xdb\n\n\t\t\xdb\xdb ID NUMBER: 1811820642\xdb\xdb\n\n");
}




