#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <unistd.h>


typedef struct  catogry catogry;
typedef struct product product;


struct product
{
    char Name[20];
    int id ;
    float price ;
    int quntity;
    int catId;

};

struct catogry
{
    int id;
    char Name[20];

};




COORD coord= {0,0};                  // this is global variable
//center of axis is set to the top left cornor of the screen
int selectedOption=0;
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}



void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int AddProductCounter=0;
product AddProduct()
{

    printf("--------ADD PRODUCT-------\n");
    product p;
    p.id=AddProductCounter;
    printf("Name : ");
    scanf("%s",p.Name);
    printf("quantity : ");
    scanf("%d",&p.quntity);
    printf("price : ");
    scanf("%f",&p.price);
    printf("category id : ");
    scanf("%d",&p.catId);
    AddProductCounter++;
    return p;

}
int AddCatogryCounter=0;
catogry AddCatogry()
{
     printf("--------ADD CATOGRY-------\n");
    catogry cat;
    printf("catogry id : ");
    scanf("%d",&cat.id);
    printf("catogry Name : ");
    scanf("%s",cat.Name);
    AddCatogryCounter++;
    return cat;

}
void showCatogry(catogry*cat)
{
    printf("--------OUR CATOGRIES-------\n");
    printf("\n------------------------------------------------------------------\n");
    for(int i=0; i<AddCatogryCounter; i++)
    {
        printf("id: %d \t\t",cat[i].id);
        printf("name: %s \t\t \n",cat[i].Name);

    }


}

void showProduct(product*product)
{  printf("--------OUR PRODUCTS-------\n");
    for(int i=0; i<AddProductCounter; i++)
    {
        printf("\n-------------------------------------------------------------------------\n");
        printf("id : %d \t",product[i].id);
        printf("name : %s \t",product[i].Name);
        printf("price : %f \t",product[i].price);
        printf("quantity : %d \t",product[i].quntity);
        printf("catid %d \t\t",product[i].catId);


    }
}


void showAllProdduct(product*product,catogry*cat)
{
  printf("-------------------------------OUR PRODUCT WITH CATOGRIES------------------------\n");
    printf("\n-----------------------------------------------------------------------------\n");
    for(int i=0; i<AddProductCounter; i++)
    {
        printf("id : %d \t",product[i].id);
        printf("name : %s \t",product[i].Name);
        printf("price : %f \t",product[i].price);
        printf("quantity : %d \t",product[i].quntity);
        printf("catid %d \t",product[i].catId);
        for(int j=0; j<AddCatogryCounter; j++)
        {
            if(cat[j].id==product[i].catId)
            {
                printf("catId  : %d \t",cat[j].id);
                printf("catName :%s \t \n",cat[j].Name);
            }
        }
    }
}
void moveProduct(product*product,catogry*cat)
{
    int prodID;
    showAllProdduct(product,cat);
    printf("\n enter product id to move ");
    scanf("%d",&prodID);
    for(int i=0; i<AddProductCounter; i++)
    {
        if(product[i].id==prodID)
        {
            printf("\n enter the id of catogry you  want to move to  ");
            scanf("%d",&product[i].catId);
        }
    }

}

void sellProduct(product*product,catogry*cat)
{
    showAllProdduct(product,cat);
    printf("\n enter product id you  want to sell ");
    int prodID;
    int quntity;
    scanf("%d",&prodID);
    for(int i=0; i<AddProductCounter; i++)
    {
        if(product[i].id==prodID)
        {

            printf("\n enter the quntity you want to sell ");
            scanf("%d",&quntity);
            if(product[i].quntity>=quntity)
            {
                product[i].quntity-=quntity;
                system("cls");

        printf("                  \n      ----------------------------------reciet------------------------------\n\n\n\n\n");
        printf("name : %s \t",product[i].Name);
        printf("price : %f \t",product[i].price);
        printf("quantity : %d \t",product[i].quntity);
        printf(" total price : %f \t",product[i].price*quntity);

        printf("               \n\n\n\n\n\n---------------thank you for use our products----------");

            }
            else
            {
                printf("there are only %d",product[i].quntity);
            }


        }
    }


}

int main()
{

    const char* message =("electronic Product Management Store");

    int i;
    gotoxy(45,10);
    for (i = 0; message[i] != '\0'; ++i)
    {
        SetColor(10);
        putchar(message[i]);
        fflush(stdout);
        usleep(50000);
    }

    printf("\n");

    //system("cls");





    char menu[6][20]= {"1. Add Catogry","2. Show Catogry","3. AddProduct ","4. show Product ","5. move Product ","6.sell products "};

    product product[200];
    catogry catogry[20];




    while(1)
    {
        system("cls");
        gotoxy(20,1);
        SetColor(10);
        printf("*********************product management store************************\n");

        for(int i=0; i<6; i++)
        {
            if(selectedOption==i)
            {

                gotoxy(50,5+i);
                SetColor(10);
                printf("%d-> %s\n",i+1,menu[i]);
            }
            else
            {
                gotoxy(50,5+i);
                SetColor(11);
                printf("%d-> %s\n",i+1,menu[i]);
            }
        }


        char ch=getch();
        if(ch==-32)
        {
            ch=getch();
            switch(ch)
            {

            case 80:
            {
                if(selectedOption==5)
                {
                    selectedOption=0;
                    gotoxy(50,5+selectedOption);
                }
                else
                {
                    selectedOption++;
                    gotoxy(50,5+selectedOption);
                }


                break;
            }


            case 72:
            {
                if(selectedOption==0)
                {
                    selectedOption==1;
                    gotoxy(50,5+selectedOption);

                }
                else
                {
                    selectedOption--;
                    gotoxy(50,5+selectedOption);
                }


                break;
            }


            }


        }
        else if(ch==13)
        {
            system("cls");
            switch(selectedOption)
            {
            case 0:
                system("cls");
                catogry[AddCatogryCounter]=AddCatogry();
                getch();
                break;


            case 1:
                showCatogry(catogry);
                getch();
                break;

            case 2:
                product[AddProductCounter]=AddProduct();

                getch();
                break;

            case 3:

                showProduct(product);


                getch();
                break;

            case 4:
                moveProduct(product,catogry);
                getch();
                break;
            case 5:
                printf("you press sell product ");
                sellProduct(product,catogry);
                getch();
                break;
            }

        }


        else
        {
            printf("normal key");
        }

    }

    return 0;
}
