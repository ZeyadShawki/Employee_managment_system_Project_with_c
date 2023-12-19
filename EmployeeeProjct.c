#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    int id;
    char firstname[50];
    char lastname[50];
    float salary;
    date dob;
    char address[35];
    int number[11];
    char email[25];
} employee;


int Numcheck(char *check)
{
    int c=1,n=0,i;
    for(n=0; check[n]!=NULL;)
        n++;
    for(i=0; i<n; i++)
    {
        c=1;
        if(check[i]!='0'&&check[i]!='1'&&check[i]!='2'&&check[i]!='3'&&check[i]!='4'&&check[i]!='5'&&check[i]!='6'&&check[i]!='7'&&check[i]!='8'&&check[i]!='9'&&check[i]!='.')
        {
            c=0;
            return c;
        }

    }
    return c;
}

int charcheck(char *check)
{
    int c=1,n=0,i;
    for(n=0; check[n]!=NULL;)
        n++;
    for(i=0; i<n; i++)
    {
        c=1;
        if(!(check[i]>='a' && check[i]<='z') && !(check[i]>='A' && check[i]<='Z'))
        {
            c=0;
            return c;
        }

    }
    return c;
}
int emailcheck1(char *checkE)
{
    int c=0,n,i;
    for(n=0; checkE[n]!=NULL;)
        n++;
    for(i=0; i<n; i++)
    {
        c=0;
        if(checkE[i]=='@')
        {
            c=1;
            return c;
        }

    }
    return c;
}
int emailcheck2(char *checkE)
{
    int c=0,n,i;
    for(n=0; checkE[n]!=NULL;)
        n++;
    for(i=0; i<n; i++)
    {
        c=0;
        if(checkE[i]=='.')
        {
            c=1;
            return c;
        }

    }
    return c;
}


int load(employee e[100])
{

    FILE *f;
    int i;
    int n=0;
    f=fopen("Company.txt","r");
    if(f != NULL)
    {
        while(!feof(f))
        {



            fscanf (f, "%d,%[^,],%[^,],%f,%d-%d-%d,%[^,],%[^,],%99[^\n]", &e[n].id,e[n].firstname, e[n].lastname, &e[n].salary,&e[n].dob.day,&e[n].dob.month,&e[n].dob.year, e[n].address, e[n].number,e[n].email);

            if(e[n].id==0)
            {

                break;

            }

            ++n;






        }




        fclose(f);
        return n;

    }
    else
    {
        printf("error opening the file!\n");
        return 0;
    }
}
void query(employee e[],int n)
{
    char namesearch[20];
    int i,flagsearch=0;
    printf("please enter the employee last name:");
    scanf("%s",namesearch);
    for(i=0; i<n; i++)
    {
        if(strcasecmp(namesearch,e[i].lastname)==0)
        {


            printf("The employee's ID is: %d\n",e[i].id);
            printf("The employee's first name is: %s\n",e[i].firstname);
            printf("The employee's last name is: %s\n",e[i].lastname);
            printf("The employee's salary is: %.2f\n",e[i].salary);
            printf("The employee's day of birth is: %d\n",e[i].dob.day);
            printf("The employee's month of birth is: %d\n",e[i].dob.month);
            printf("The employee's year of birth is: %d\n",e[i].dob.year);
            printf("The employee's address is: %s\n",e[i].address);
            printf("The employee's number is: %s\n",e[i].number);
            printf("The employee's email is: %s\n",e[i].email);
    printf("-----------------------------------------------------------------\n\n");
        }

        else
            flagsearch=flagsearch+1;

    }

    if(flagsearch==(n))
        printf("No such employee with this last name\n");
}




int Add(employee e[],int n)
{
    int i=0,c,z;

    char check[20];


    while(i==0)
    {
        printf("Enter a valid ID: ");
        scanf("%s",check);
        i=Numcheck(check);

    }
    e[n].id=atoi(check);
    i=0;
    getchar();
    while(i==0)
    {
        printf("Enter a valid firstname: ");
        scanf("%s",e[n].firstname);
        getchar();
        i=charcheck(e[n].firstname);
    }
    i=0;

    while(i==0)
    {
        printf("Enter a valid last name: ");
        scanf("%s",e[n].lastname);
        getchar();
        i=charcheck(e[n].lastname);
    }
    printf("Enter a valid address: ");
    gets(e[n].address);
    i=0;
    while(i==0)
    {
        printf("Please Enter a valid Salary of the employee: ");
        scanf("%s",check);
        getchar();
        i=Numcheck(check);
    }
    e[n].salary=atof(check);

    i=0;
    while(i==0)
    {
        printf("Please Enter a valid Day of birth of the employee: ");
        scanf("%s",check);
        getchar();
        i=Numcheck(check);
    }
    e[n].dob.day=atoi(check);
    while(e[n].dob.day>31)
    {
        printf("Please Enter a valid Day of birth of the employee: ");
        scanf("%d",&e[n].dob.day);
        getchar();
    }
    while(e[n].dob.day<1)
    {
        printf("Please Enter a valid Day of birth of the employee: ");
        scanf("%d",&e[n].dob.day);
        getchar();
    }
    i=0;
    while(i==0)
    {
        printf("Please Enter a valid Month of Birth of the employee: ");
        scanf("%s",check);
        getchar();
        i=Numcheck(check);
    }
    e[n].dob.month=atoi(check);
    while(e[n].dob.month>12)
    {
        printf("Please Enter a valid Month of Birth of the employee: ");
        scanf("%d",&e[n].dob.month);

    }
    while(e[n].dob.month<1)
    {
        printf("Please Enter a valid Month of Birth of the employee: ");
        scanf("%d",&e[n].dob.month);

    }
    i=0;
    while(i==0)
    {
        printf("Please Enter a valid Year of birth of the employee: ");
        scanf("%s",check);
        getchar();
        i=Numcheck(check);
    }
    e[n].dob.year=atoi(check);
    while(e[n].dob.year>2022)
    {
        printf("Please Enter a valid Year of birth of the employee: ");
        scanf("%d",&e[n].dob.year);
    }
    while(e[n].dob.year<1955)
    {
        printf("Please Enter a valid Year of birth of the employee: ");
        scanf("%d",&e[n].dob.year);
    }



    i=0;
    while(i==0)
    {
        printf("Enter a valid Phone number: ");
        scanf("%s",e[n].number);
        i=Numcheck(e[n].number);
    }
    while(strlen(e[n].number)!=11)
    {
        printf("Enter a valid Phone number: ");
        scanf("%s",e[n].number);
    }
    z=0;
    while(z==0)
    {
        char checkE[20];
        printf("Please Enter the E-mail of the employee: ");
        scanf("%s",checkE);
        z=emailcheck1(checkE);
        z=emailcheck2(checkE);
        strcpy(e[n].email,checkE);
    }






    printf("-----------------------------------------------------------------\n\n");


    printf("-------------------- The new employee information---------------------------------------\n\n");

    printf("the new employee ID is: %d\n",e[n].id);
    printf("the new employee first name is: %s\n",e[n].firstname);
    printf("the new employee last name is: %s\n",e[n].lastname);
    printf("the new employee salary is: %.2f\n",e[n].salary);
    printf("the new employee day of birth is: %d\n",e[n].dob.day);
    printf("the new employee month of birth is: %d\n",e[n].dob.month);
    printf("the new employee year of birth is: %d\n",e[n].dob.year);
    printf("the new employee address is: %s\n",e[n].address);
    printf("the new employee number is: %s\n",e[n].number);
    printf("the new employee email is: %s\n",e[n].email);

    printf("-----------------------------------------------------------------\n\n");


    return n+1;



}
void Modify(employee e[],int c)
{
    int Id,n,i=0;
    char check[10];
    printf("Please Enter the Id of the employee you want to modify his data: ");
    scanf("%d",&Id);
    for(n=0; e[n].id!=Id&&n<c;)
        n++;
    while (e[n].id!=Id)
    {
        printf("The Entered Id does not  exist please Enter a valid one: ");
        scanf("%d",&Id);
        for(n=0; e[n].id!=Id&&n<c;)
            n++;
    }
    i=0;
    getchar();
    while(i==0)
    {
        printf("Enter a valid firstname: ");
        scanf("%s",e[n].firstname);
        getchar();
        i=charcheck(e[n].firstname);
    }
    i=0;

    while(i==0)
    {
        printf("Enter a valid last name: ");
        scanf("%s",e[n].lastname);
        getchar();
        i=charcheck(e[n].lastname);
    }
    printf("Enter a valid address: ");
    gets(e[n].address);
    i=0;
    while(i==0)
    {
        printf("Please Enter a valid Salary of the employee: ");
        scanf("%s",check);
        getchar();
        i=Numcheck(check);
    }
    e[n].salary=atof(check);

    i=0;
    while(i==0)
    {
        printf("Please Enter a valid Day of birth of the employee: ");
        scanf("%s",check);
        getchar();
        i=Numcheck(check);
    }
    e[n].dob.day=atoi(check);
    while(e[n].dob.day>31)
    {
        printf("Please Enter a valid Day of birth of the employee: ");
        scanf("%d",&e[n].dob.day);
        getchar();
    }
    while(e[n].dob.day<1)
    {
        printf("Please Enter a valid Day of birth of the employee: ");
        scanf("%d",&e[n].dob.day);
        getchar();
    }
    i=0;
    while(i==0)
    {
        printf("Please Enter a valid Month of Birth of the employee: ");
        scanf("%s",check);
        getchar();
        i=Numcheck(check);
    }
    e[n].dob.month=atoi(check);
    while(e[n].dob.month>12)
    {
        printf("Please Enter a valid Month of Birth of the employee: ");
        scanf("%d",&e[n].dob.month);

    }
    while(e[n].dob.month<1)
    {
        printf("Please Enter a valid Month of Birth of the employee: ");
        scanf("%d",&e[n].dob.month);

    }
    i=0;
    while(i==0)
    {
        printf("Please Enter a valid Year of birth of the employee: ");
        scanf("%s",check);
        getchar();
        i=Numcheck(check);
    }
    e[n].dob.year=atoi(check);
    while(e[n].dob.year>2022)
    {
        printf("Please Enter a valid Year of birth of the employee: ");
        scanf("%d",&e[n].dob.year);
    }
    while(e[n].dob.year<1955)
    {
        printf("Please Enter a valid Year of birth of the employee: ");
        scanf("%d",&e[n].dob.year);
    }



    i=0;
    while(i==0)
    {
        printf("Enter a valid Phone number: ");
        scanf("%s",e[n].number);
        i=Numcheck(e[n].number);
    }
    while(strlen(e[n].number)!=11)
    {
        printf("Enter a valid Phone number: ");
        scanf("%s",e[n].number);
    }
    int z;
    z=0;
    while(z==0)
    {
        char checkE[20];
        printf("Please Enter the E-mail of the employee: ");
        scanf("%s",checkE);
        z=emailcheck1(checkE);
        z=emailcheck2(checkE);
        strcpy(e[n].email,checkE);
    }




    printf("-----------------------------------------------------------------\n\n");

    printf("-------------------- The modified employee information---------------------------------------\n\n");

    printf("The new employee ID is: %d\n",e[n].id);
    printf("The new employee first name is: %s\n",e[n].firstname);
    printf("The new employee last name is: %s\n",e[n].lastname);
    printf("The new employee salary is: %.2f\n",e[n].salary);
    printf("The new employee day of birth is: %d\n",e[n].dob.day);
    printf("The new employee month of birth is: %d\n",e[n].dob.month);
    printf("The new employee year of birth is: %d\n",e[n].dob.year);
    printf("The new employee address is: %s\n",e[n].address);
    printf("The new employee number is: %s\n",e[n].number);
    printf("The new employee email is: %s\n",e[n].email);

    printf("-----------------------------------------------------------------\n\n");

 }

int delete(employee e[100],int n)
{
    int i,k,z;
    char s1[15];
    char s2[15];
    printf("enter the first name of employee: \n");
    scanf("%s",s1);
    printf("enter the last name of employee: \n");
    scanf("%s",s2);
    for(i=0; i<n; i++)
    {
        if(strcasecmp(s1,e[i].firstname)==0&&strcasecmp(s2,e[i].lastname)==0)
            break;
        else if(strcasecmp(s1,e[i].firstname)!=0&&strcasecmp(s2,e[i].lastname)!=0&&i==(n-1))
        {
            printf("theres no employee with this first name and last name\n");
            return 0;
        }


    }
    for(k=i; k<n; k++)
    {
        e[k]=e[k+1];

    }

    printf("The Employees after deleting:\n");
    printf("-----------------------------\n");
    for(i=0; i<n-1; i++)
    {
        if(e[i].id==0)
            {
            break;
            }

        printf("The employee %d ID is: %d\n",i+1,e[i].id);
        printf("The employee %d first name is: %s\n",i+1,e[i].firstname);
        printf("The employee %d last name is: %s\n",i+1,e[i].lastname);
        printf("The employee %d salary is: %.2f\n",i+1,e[i].salary);
        printf("The employee %d day of birth is: %d\n",i+1,e[i].dob.day);
        printf("The employee %d month of birth is: %d\n",i+1,e[i].dob.month);
        printf("The employee %d year of birth is: %d\n",i+1,e[i].dob.year);
        printf("The employee %d address is: %s\n",i+1,e[i].address);
        printf("The employee %d number is: %s\n",i+1,e[i].number);
        printf("The employee %d email is: %s\n",i+1,e[i].email);
        printf("-----------------------------------------------------------------\n");


    }


    return z=1;


}



void swap_int (int *x, int *y) 
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
} 

void swap_char (char *x, char *y) 
{
    char temp[100];  
    strcpy (temp, x);
    strcpy (x, y);
    strcpy (y, temp);
} 
 sort(employee *e, int j) {
    swap_int (&e[j].id, &e[j + 1].id);
    swap_char (e[j].firstname, e[j + 1].firstname);
    swap_char (e[j].lastname, e[j + 1].lastname);
    swap_int (&e[j].salary, &e[j + 1].salary);
    swap_int (&e[j].dob.day, &e[j + 1].dob.day);
    swap_int (&e[j].dob.month, &e[j + 1].dob.month);
    swap_int (&e[j].dob.year, &e[j + 1].dob.year);
    swap_char (e[j].address, e[j + 1].address);
    swap_char (e[j].number, e[j + 1].number);
    swap_char (e[j].email, e[j + 1].email);
}

void sortbylname (employee *e, int n)
{

    int i,j,ti;
    char tfn[30],tln[30],ta[30],tn[11],te[20];
    float ts;
    date td;

    for(i=0; i<n; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if(strcasecmp(e[j].lastname,e[j+1].lastname)>0)
            {
                sort(e,j);
            }
        }
    }

    for(i=0; i<n; i++)

    {
        if(e[i].id==0)
        {
            i=i+1;
        }


        printf("the employee %d ID is: %d\n",i+1,e[i].id);
        printf("the employee %d first name is: %s\n",i+1,e[i].firstname);
        printf("the employee %d last name is: %s\n",i+1,e[i].lastname);
        printf("the employee %d salary is: %.2f\n",i+1,e[i].salary);
        printf("the employee %d day of birth is: %d\n",i+1,e[i].dob.day);
        printf("the employee %d month of birth is: %d\n",i+1,e[i].dob.month);
        printf("the employee %d year of birth is: %d\n",i+1,e[i].dob.year);
        printf("the employee %d address is: %s\n",i+1,e[i].address);
        printf("the employee %d number is: %s\n",i+1,e[i].number);
        printf("the employee %d email is: %s\n",i+1,e[i].email);
        printf("-----------------------------------------------------------------\n");
    }



}
void sortbysalary (employee *e, int n)
{

    int i,j,ti;
    char tfn[30],tln[30],ta[30],tn[11],te[20];
    float ts;
    date td;

    for(i=0; i<n; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if(e[j].salary>e[j+1].salary)
            {
               sort(e,j);
            }


        }


    }


    for(i=0; i<n; i++)
    {
        if(e[i].id==0)
        {
            i=i+1;
        }


        printf("the employee %d ID is: %d\n",i+1,e[i].id);
        printf("the employee %d first name is: %s\n",i+1,e[i].firstname);
        printf("the employee %d last name is: %s\n",i+1,e[i].lastname);
        printf("the employee %d salary is: %.2f\n",i+1,e[i].salary);
        printf("the employee %d day of birth is: %d\n",i+1,e[i].dob.day);
        printf("the employee %d month of birth is: %d\n",i+1,e[i].dob.month);
        printf("the employee %d year of birth is: %d\n",i+1,e[i].dob.year);
        printf("the employee %d address is: %s\n",i+1,e[i].address);
        printf("the employee %d number is: %s\n",i+1,e[i].number);
        printf("the employee %d email is: %s\n",i+1,e[i].email);
        printf("-----------------------------------------------------------------\n");
    }


}


void sortbyDOB (employee *e, int n)
{

    int i,j,ti;
    char tfn[30],tln[30],ta[30],tn[11],te[20];
    float ts;
    date td;

    for(i=0; i<n; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if((e[j].dob.year) < (e[j+1].dob.year))
            {
                sort(e,j);

            }
            if((e[j].dob.month) < (e[j+1].dob.month) && (e[j].dob.year) == (e[j+1].dob.year))
            {
                sort(e,j);
            }
            if((e[j].dob.day) < (e[j+1].dob.day) && (e[j].dob.year) == (e[j+1].dob.year) && (e[j].dob.month) == (e[j+1].dob.month))
            {

                sort(e,j);
            }

        }


    }

    for(i=0; i<n; i++)
    {
           if(e[i].id==0)
        {
            i=i+1;
        }



        printf("the employee %d ID is: %d\n",i+1,e[i].id);
        printf("the employee %d first name is: %s\n",i+1,e[i].firstname);
        printf("the employee %d last name is: %s\n",i+1,e[i].lastname);
        printf("the employee %d salary is: %.2f\n",i+1,e[i].salary);
        printf("the employee %d day of birth is: %d\n",i+1,e[i].dob.day);
        printf("the employee %d month of birth is: %d\n",i+1,e[i].dob.month);
        printf("the employee %d year of birth is: %d\n",i+1,e[i].dob.year);
        printf("the employee %d address is: %s\n",i+1,e[i].address);
        printf("the employee %d number is: %s\n",i+1,e[i].number);
        printf("the employee %d email is: %s\n",i+1,e[i].email);
        printf("-----------------------------------------------------------------\n");
    }


}

void save(employee e[],int n,int flagsave)
{
    FILE *f;
    int i;

    if(flagsave==1)
    {



        f=fopen("Company.txt","w");
        if(f!=NULL)
        {

            for(i=0; i<n-1; i++)

            {

                fprintf(f,"%d,%s,%s,%.f,%d-%d-%d,%s,%s,%s\n",e[i].id,e[i].firstname,e[i].lastname,e[i].salary,e[i].dob.day,e[i].dob.month,e[i].dob.year, e[i].address, e[i].number,e[i].email);


            }
            fclose(f);

            printf("File Modifications have been saved successfully!\n");
           printf("------------------------------------------------\n");
        }
        else
        {
            printf("error opening the file");
        }




    }

    else
    {


        printf("File Modifications have been saved successfully!\n");
        printf("------------------------------------------------\n");
        f=fopen("Company.txt","w+");
        if(f!=NULL)
        {

            for(i=0; i<n; i++)

            {
                if(e[i].id==0)
                    {
                    break;

                    }

                fprintf(f,"%d,%s,%s,%.f,%d-%d-%d,%s,%s,%s\n",e[i].id,e[i].firstname,e[i].lastname,e[i].salary,e[i].dob.day,e[i].dob.month,e[i].dob.year, e[i].address, e[i].number,e[i].email);


            }
            fclose(f);
        }
        else
        {
            printf("error opening the file");
        }
    }


}





int main()
{
    employee e[100];
    int n,x,i=0,s,flagsave;
    char a;
    n=load(e);
    FILE *f;

    printf("Company Management System\n");
    printf("-------------------------\n");
    printf("%The number of employees are %d\n",n);
functions:
    printf("Please choose an option from the following:\n");
    printf("1-Query\n2-Add\n3-Delete\n4-Modify\n5-Sort\n6-Save\n7-Exit\n");
    printf("Enter your choice: ");
choice:
    scanf("%d",&x);
    printf("-----------------------------------------------------------------\n");

    switch (x)
    {
    case 1:
        query(e,n);
        x=0;
        goto functions;
        break;
    case 2:

        n=Add(e,n);


        x=0;
        goto functions;
        break;
    case 3:
        flagsave=delete(e,n);
        x=0;
        goto functions;
        break;
    case 4:
        Modify(e,n);
        x=0;
        goto functions;
        break;
    case 5:
        printf("Please choose the type of sort: \nEnter 1 for sorting by last name \nEnter 2 for sorting by date of birth \nEnter 3 for sorting by salary \n sort type->");
sorting:
        scanf("%d",&s);
        if(s==1)
            sortbylname(e,n);

        else if (s==2)
            sortbyDOB(e,n);

        else if(s==3)
            sortbysalary(e,n);
        else
        {
        printf("Invalid choice!!\n");
      printf("choose if you want to exit \n");

            goto again;
        }



        x=0;
        goto functions;
        break;
    case 6:
        save(e,n,flagsave);
        x=0;
        goto functions;
        break;

    case 7:
    {
        printf("Warning: Exiting without saving will not save any modifications to the system file!\n");
        printf("Are you sure you want to exit <Y/N>? : ");
again:
        scanf(" %c",&a);
        if (a=='Y'||a=='y')
        {
            printf("Thank you for using the program!");
            exit(0);
        }
        else if (a=='N'||a=='n')
            goto functions;
        else
        {
            printf("Please enter a valid value <Y/N>: ");
            goto again;
        }
    }

    break;
    default:
    {
        printf("Invalid choice!!\n");
      printf("choose if you want to exit \n");

        goto again;
    }
    }
    return 0;
}
