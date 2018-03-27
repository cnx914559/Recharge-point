#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int f=0;
struct Login
{
    char user_name[50];
    char password[50];
};

struct sign_up
{
    char name[50];
    char user_name[50];
    char password[50];
    char phoneno[100];
};

struct admin
{
    char service_provider[50];
    char add_topup[50];
    char delete_topup[50];

};


struct Topup
{
   char topup_id[200];
   int amount;
   int value;
   int validity;

};

struct recharge
{
    char serviceprovidername[25];
    char topupid[25];
    char  phoneNo[50];
    char date[50];
    int amount;
};

 void torecharge(char rt2[50])
 {
     if(f==0)
     {
         strcat(rt2,".txt");
         printf("%s",rt2);
         f=1;
     }
     printf("%d",f);
     char r[200];

     printf(" the file name is  %s: \n",rt2);
     struct recharge rt;
     printf("Enter the service provider name : ");
     scanf("%s",rt.serviceprovidername);
     printf("\n");
     printf("Enter the Top id ");
     scanf("%s",rt.topupid);
     printf("\n");
     printf("Enter the mobile no  : ");
     scanf("%s",&rt.phoneNo);
     printf("\n");
     printf("Enter the date : ");
     scanf("%s",&rt.date);
     printf("Enter the amount: ");
     scanf("%d",&rt.amount);
    // strcat(rt2,".txt");
     printf(" the value after appending txt is %s\n",rt2);


     FILE *fpt1;
     fpt1 = fopen(rt2,"a");
     printf("the file opened successfully :\n");
     fwrite(&rt,sizeof (rt),1,fpt1);
     fclose(fpt1);
     printf("successfully entered into the file \n");


      FILE *fp;

      fp=fopen(rt2,"r");
      printf("===============================================================================\n");
      printf(" service provider name\t\t Topupid \t\t Amount \t\t phoneNo \t\t date \t\t \n");
      printf("================================================================================\n");
      while(1)
      {
         fread(&rt,sizeof(rt),1,fp);
         if(feof(fp))
         {
             break;
         }
         printf("%s\t",rt.serviceprovidername);
         printf("%s\t",rt.topupid);
         printf("%d\t",rt.amount);
         printf("%s\t",rt.phoneNo);
         printf("%s\t",rt.date);
         printf("\n");

     }
     fclose(fp);



 }

int main()
{

    struct Login st;
    struct sign_up st1;
    int count1=0;


    printf("                             WELCOME TO RECHARGE POINT                     \n");

    printf("\t");
    printf("\t");
    printf("\n");
    int n;
    printf("                  1. TO LOGIN                             \n");
    printf("                  2. TO SIGN_UP                           \n");
    printf("                  3. Enter your choice : ");
    scanf("%d",&n);
    printf("\n");
    char user[30];
    switch(n)
    {
        case 1:printf("      Enter Your user Name : ");
               char a[100];
               fflush(stdin);
               gets(a);
               fflush(stdin);
               printf("\n");
               printf("      Enter your Password : ");
               char b[100];
               scanf("%s",b);
               fflush(stdin);
               printf("\n");

               if(strcmp(a,"admin")==0&&strcmp(b,"admin")==0)
               {
                   admin();
               }
               else
               {
               //  strcat(a,".txt");
                 FILE *fp5;
                 fp5=fopen("user_log.txt","r");
                 printf(" username\t\t password  \t\t \n ");

                 while(1)
                 {
                     fread(&st,sizeof(st),1,fp5);
                     if(feof(fp5))
                     {
                         break;
                     }
                   //  printf("%s\t\t*",st.name);
                     printf("%s\t\t*",st.password);
                     printf("%s\t\t*",st.user_name);
                    // printf("%s\t\t*",st1.phoneno);
                     printf("\n");
                 }
                 fclose(fp5);




                 printf(" The above details are stored in the file \n");


                   FILE *ft;
                   struct Login st;
                   int count=0;
                   int flag=0;

                   ft=fopen("user_log.txt","r");
                   printf(" the file is opened \n");
                   while(1)
                   {
                       printf("Entered in the condition ");
                       fread(&st,sizeof(st),1,ft);
                       if(feof(ft))
                       {
                           break;
                       }
                       printf("Comparing the username with entered user name and password");
                       if(strcmp(a,st.user_name)==0 && strcmp(b,st.password)==0)
                       {
                           printf("successfully loged in \n");
                           userservice(a);
                       }
                       else
                       {
                          flag=1;
                       }
                   }
                   if(flag==1)
                   {
                       printf("You have entered incorrect user name or Password \n ");
                   }



                /* FILE *fp5;
                 fp5=fopen("username.txt","r");
                 printf("Name:\t\t Password\t\t username\t\t phoneno\t\t \n");

                 while(1)
                 {
                     fread(&st1,sizeof(st1),1,fp5);
                     if(feof(fp5))
                     {
                         break;
                     }
                     printf("%s\t\t",st1.name);
                     printf("%s\t\t",st1.password);
                     printf("%s\t\t",st1.user_name);
                     printf("%s\t\t",st1.phoneno);
                     printf("\n");
                 }
                 fclose(fp5);*/



               }
               break;


        case 2:

                 printf("Enter the Name: ");
                 char name[20];
                 char store[200]="D:\\CPROJECT\\Users\\";

                 fflush(stdin);
                 gets(name);


                 printf("Enter your User_name : ");
                 fflush(stdin);
                 gets(user);

                 char password[30];
                 printf("Enter Password : ");
                 fflush(stdin);
                 gets(password);

                 printf("Enter the mobile number : ");

                // long int mobile;
                 scanf("%s",st1.phoneno);

                 strcpy(st.user_name,user);
                 strcpy(st.password,password);



                 strcpy(st1.name,name);
                 strcpy(st1.user_name,user);
                 strcpy(st1.password,password);
                 strcat(store,user);
                 strcat(store,".txt");


                 FILE *fp;
                 char fname[100];
                 fp=fopen(store,"w"/*"a"*/);
                 if(fp==NULL)
                 {
                      printf("no file exist ");
                 }
                 else
                 {
                      printf("successfully the file is created in the folder  \n");
                 }

                 FILE *fp1;
                 fp1 = fopen("user_log.txt","w");
                 fwrite(&st,sizeof (st),1,fp1);
                 fclose(fp1);

                 FILE *fp2;
                 fp2=fopen(user,"w");
                 fwrite(&st1,sizeof(st1),1,fp2);
                 fclose(fp2);
                 printf("name file is created \n");



                 FILE *fp3;
                 fp3=fopen(user,"r");
                 printf("Name:\t\t Password\t\t username\t\t phoneno\t\t \n");

                 while(1)
                 {
                     fread(&st1,sizeof(st1),1,fp3);
                     if(feof(fp3))
                     {
                         break;
                     }
                     printf("%s\t\t",st1.name);
                     printf("%s\t\t",st1.password);
                     printf("%s\t\t",st1.user_name);
                     printf("%s\t\t\n",st1.phoneno);
                 }
                 fclose(fp3);

                 signup(name,password);
                 break;



    }




}




void service()
{
        char service[50];
        char a[50];
        printf("Enter the name of the service provider : ");
        fflush(stdin);
        gets(service);
        fflush(stdin);

        char s5[100]="D:\\CPROJECT\\servieprovider\\";//,service);
        strcat(s5,service );
        strcat(s5,".txt");

        FILE *fp;
        char fname[100];
        fp=fopen(s5,"w");
        if(fp==NULL)
        {
            printf("no file exist ");
        }
        else
        {
            printf("successfully the file is created in the folder  \n");
        }
}

void admin()
{

    while(1)
    {

        printf(" 1.Add service provider \n 2.Add top ups \n 3.Delete top ups \n 4.Details of user \n 5.Day wise report \n 6.Service provider report \n 7.Exit \n ");
        int n1;
        printf("Enter your choice : ");
        scanf("%d",&n1);
        int j=0;
        switch(n1)
        {

            case 1:  service();
                     break;
            case 2:  Addservice();
                     break;
            case 3:  delete();
                     break;
            case 4:  User_info();
                     break;
            case 5:  User_date();
                     break;
            case 6:  service_report();
                     break;
            case 7:  j=1;
                     break;
        }
        if(j==1)
        {
            break;
        }

    }
}

void signup(char c[50],char d[50])
{

               printf("      Enter Your Name : ");
               char a1[100];
               fflush(stdin);

               gets(a1);
               fflush(stdin);
               printf("\n");
               printf("      Enter your Password : ");
               char b1[100];

               scanf("%s",b1);
               fflush(stdin);
               printf("\n");

               printf(" the value of name sended to function : %s\n",c);
               printf(" the value of password received form funcion :%s\n",d);
               printf("%s\n",a1);
               printf("%s\n",b1);

               if(strcmp(c,a1)==0&&strcmp(d,b1)==0)
               {
                   userservice(a1);
               }
               else
               {
                    printf("the password is not matching ");
               }



}

void userservice(char rt1[50])
{
    printf(" the user name is : %s\n",rt1);

     while(1)
     {

         printf(" 1.view Topups \n 2.Recharge \n 3.view logs by phoneNo \n 4.view logs by date \n 5.exit\n");
         int n2;
         printf("Enter Your choice ");
         scanf("%d",&n2);
         char c[200];
         char mobile[200];
         char name10[200];
         char date[100];
         int k=0;
        //
         switch(n2)
         {
            case 1:
                      printf("Enter the service provider name to view offers :");
                      fflush(stdin);
                      gets(c);
                      //strcat(c,".txt");
                      FILE *fp1;
                      struct Topup t;
                      fp1 = fopen(c,"r");
                      printf("============================================================================================\n");
                      printf("\t Id\t\t amount\t\t value\t\t validity \t\n");
                      printf("============================================================================================\n");
                      while(1)
                      {
                         fread(&t,sizeof(t),1,fp1);
                         if(feof(fp1))
                         {
                             break;
                         }
                         printf("%s\t\t",t.topup_id);
                         printf("%d\t\t",t.amount);
                         printf("%d\t\t",t.value);
                         printf("%d\t\t",t.validity);
                         printf("\n");
                         printf("==================================================================================\n");
                      }
                      fclose(fp1);
                      break;


            case 2:   torecharge(rt1);
                      break;


            case 3:

                     printf("Enter the mobile number : ");
                     scanf("%s",&mobile);

                     char open[200]="D:\\CPROJECT\\Users\\";
                     struct recharge rt;
                     //
                     //strcat(rt1,".txt");
                     //
                     printf(" the file name of the mobile is : %s\n",rt1);
                    // strcat(open,rt1);
                     //strcat(open,".txt");

                     FILE *fpt2;
                     fpt2=fopen(rt1,"r");
                     printf("==================================================================================================\n");
                     printf(" ID \t\t  service provider name \t\t moible\t\t amount\t\t  Date  \t\t");
                     printf("\n");
                     printf("===================================================================================================\n");
                     while(1)
                    {

                        fread(&rt,sizeof(rt),1,fpt2);

                        if(feof(fpt2))
                        {
                            break;
                        }
                        if(strcmp(mobile,rt.phoneNo)==0)
                        {
                              //printf("Entered into file \n");
                              printf("%s\t\t",rt.topupid);
                              printf("%s\t\t\t\t",rt.serviceprovidername);
                              printf("%s\t\t\t\t",rt.phoneNo);
                              printf("%d\t\t\t",rt.amount);
                              printf("%s\t\t\t",rt.date);
                              printf("\n");
                        }

                    }
                       printf("======================================================================================\n");

                    printf("Completely entered into the file \n");
                    fclose(fpt2);
                    break;


            case 4:
                     printf("Enter the Date : ");
                     scanf("%s",date);
                     printf("the file name is : %s\n",rt1);
                     printf(" the value of f is %d",f);
                     if(f==0)
                     {
                     // strcat(rt1,".txt");
                     }

                     printf(" the file name of the mobile is : %s\n",rt1);
                   //  struct recharge rt;

                     FILE *fpt4;
                     fpt4=fopen(rt1,"r");
                     printf("==================================================================================================\n");
                     printf(" ID \t\t  service provider name \t\t moible\t\t amount\t\t  Date  \t\t");
                     printf("\n");
                     printf("===================================================================================================\n");
                     while(1)
                    {

                        fread(&rt,sizeof(rt),1,fpt4);

                        if(feof(fpt4))
                        {
                            break;
                        }
                        if(strcmp(date,rt.date)==0)
                       {
                              //printf("Entered into file \n");
                              printf("%s\t\t",rt.topupid);
                              printf("%s\t\t\t\t",rt.serviceprovidername);
                              printf("%s\t\t\t\t",rt.phoneNo);
                              printf("%d\t\t\t",rt.amount);
                              printf("%s\t\t\t",rt.date);
                              printf("\n");
                        }

                    }
                       printf("======================================================================================\n");

                    printf("Completely entered into the file \n");
                    fclose(fpt4);
                    break;
            case 5:
                    k=1;
                    break;

         }
         if(k==1)
         {
             break;
         }
     }

}
void Addservice()
{
    struct Topup t;
    char name[50];
    int a1;
    FILE *fp;
    fflush(stdin);
    printf("Enter the Service provider name : ");
    gets(name);
    printf("Enter How many records you want to store : ");
    scanf("%d",&a1);
    fp = fopen(name,"a");
    for(int i=0;i<a1;i++){
        fflush(stdin);
        printf("Enter the top_id :");
        gets(t.topup_id);
        printf("Enter the amount : ");
        scanf("%d",&t.amount);
        printf("Enter the value of amount will be credited  : ");
        scanf("%d",&t.value);
        printf("Enter the validity of the amount : ");
        scanf("%d",&t.validity);
        fwrite(&t,sizeof (t),1,fp);
    }
    fclose(fp);
    fp=fopen(name,"r");
    printf("======================================================================================\n");

    printf(" ID \t\t  amount\t\t  validity\t\t");

    printf("\n");
    printf("======================================================================================\n");

    printf("\n");

    while(1)
    {
        fread(&t,sizeof(t),1,fp);
        if(feof(fp))
        {
            break;
        }

        printf("%s\t\t",t.topup_id);
        printf("%d\t\t",t.amount);
        printf("%d\t\t",t.validity);
        printf("\n");
        printf("==================================================================================\n");
    }
    fclose(fp);
}

 void User_info()
{
    struct recharge rt5;
    char a3[50];
    printf("Enter the user name : ");
    scanf("%s",a3);
    printf("====================================================================================================================================\n");
    printf("service provider name \t\t topup id \t\t phone no \t\t date \t\t amount \n");
    printf("=====================================================================================================================================\n");
    FILE *fp;

    //strcat("D:\\CPROJECT\\Users\\",a3);
    char a10[200]="D:\\CPROJECT\\Users\\";
    strcat(a10,a3);
    fp=fopen(a10,"r");
    while(1)
    {

        fread(&rt5,sizeof(rt5),1,fp);

        if(feof(fp))
        {
            break;
        }
        printf("%s\t\t\t",rt5.serviceprovidername);
        printf("%s\t\t\t",rt5.topupid);
        printf("%s\t\t\t",rt5.phoneNo);
        printf("%s\t\t\t",rt5.date);
        printf("%d\t\t\t",rt5.amount);
        printf("\n");
        printf("==================================================================================================================\n");
    }
    fclose(fp);


}

 void User_date()
{
    char a5[50];

    struct recharge rt6;
    char a4[50];
    printf("Enter the user name ");
    scanf("%s",a5);

    char a12[200]="D:\\CPROJECT\\Users\\";
    printf("Enter the user date : ");
    scanf("%s",a4);

    strcat(a12,a5);

    printf("====================================================================================================================================\n");
    printf("service provider name \t\t topup id \t\t phone no \t\t date \t\t amount \n");
    printf("=====================================================================================================================================\n");

    FILE *fp;
    fp=fopen(a12,"r");
    while(1)
    {

        fread(&rt6,sizeof(rt6),1,fp);

        if(feof(fp))
        {
            break;
        }
        if(strcmp(a4,rt6.date)==0)
        {

          printf("%s\t\t\t",rt6.serviceprovidername);
          printf("%s\t\t\t",rt6.topupid);
          printf("%s\t\t\t",rt6.phoneNo);
          printf("%s\t\t\t",rt6.date);
          printf("%d\t\t\t",rt6.amount);
          printf("\n");
          printf("==================================================================================================================\n");

        }
    }
    fclose(fp);


}

void allfiles()
{

  /*  DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return(0);*/

}

void service_report()
{
    char ser[200];
    struct Topup t;
    printf("Enter the service provider name : ");
    scanf("%s",ser);
    FILE *fp;
    fp=fopen(ser,"r");
    printf("======================================================================================\n");

    printf(" ID \t\t  amount\t\t  \t\t value \t\t validity\t\t");

    printf("\n");
    printf("======================================================================================\n");

    printf("\n");

    while(1)
    {
        fread(&t,sizeof(t),1,fp);
        if(feof(fp))
        {
            break;
        }

        printf("%s\t\t",t.topup_id);
        printf("%d\t\t",t.amount);
        printf("%d\t\t",t.value);
        printf("%d\t\t",t.validity);
        printf("\n");
        printf("==================================================================================\n");
    }
    fclose(fp);


}

void delete()
{
    FILE *fp,*fp1;
    struct Topup t1,t2;
    int found=0,count=0;
    char ser[100];
    char top[100];


    printf("Enter the service provider name : ");
    scanf("%s",ser);

    printf("Enter the top up id ");
    scanf("%s",top);

    strcat(ser,".txt");
    printf(" the company name is : %s",ser);
    fp=fopen(ser,"r");

    fp1=fopen("temp.txt","w");



    while(1)
    {
        fread(&t1,sizeof(t1),1,fp);
        if(feof(fp))
        {

            break;
        }
        if(strcmp(t1.topup_id,top)==0)
        {
            found=1;
        }
        else
        {
           fwrite(&t1,sizeof(t1),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    int ret;
   // char oldname[] = ser;
    char newname[] = "temp.txt";
    ret = rename(newname,ser);
    if(ret==0)
    {
      printf("File renamed successfully");
    }
    else
      {
         printf("Error: unable to rename the file");
      }



}



