#include<stdlib.h>
#include <stdio.h>
#include<conio.h>
#include<time.h>
#include <windows.h>

void timeOut(int sec) //function for add timeout to the execute time
{
    int misec;

    misec=1000*sec;//converting the time into milliseconds
    clock_t x = clock(); //for store start time

    while (clock()<x+misec);
}



int main ()
{

int input; //Declare a variable for assign input choice

printf("\n\n");

//Design a simple Menu
printf("                        \t\t\t   __WELCOME__\n");
	printf("\t\t\t ==================================================================\n");
	printf("\t\t\t||                                                                ||\n");
	printf("\t\t\t||             1- To calculate the square value:                  ||\n");
	printf("\t\t\t||             2- To Retrieve previous data:                      ||\n");
	printf("\t\t\t||             3- Exit system:                                    ||\n");
	printf("\t\t\t||                                                                ||\n");
	printf("\t\t\t||================================================================||\n");



printf("\n\nEnter Your choice:\n");
scanf("%d",&input); //Assign the input value


//Declare a switch
switch (input)
{ case 1 : { //if input is 1, then execute this code section


  FILE *mac; //File pointer to to hold reference to our file

    system ("getmac>CA_Log.txt"); //Redirect Output to Text File
    mac=fopen("CA_Log.txt","a+"); //Create a text file & open it from both reading and writing mode

    char mac_info;

    mac_info = system("getmac"); // windows cmd code(getmac) used for find physical address in particular machine

    printf("%s\n",mac_info); //for print mac address in the console

    fclose(mac); //Close the file


  FILE *cname;  //File pointer to to hold reference to our file

    cname = fopen("CA_Log.txt", "a+"); //Open the text file in both reading and writing mode

    char pcName[MAX_COMPUTERNAME_LENGTH + 1];

    DWORD Size = MAX_COMPUTERNAME_LENGTH + 1 ;

    GetComputerName( pcName, &Size ); // for retrieves name of the local computer.

    printf( "\nComputer name : %s\n\n", pcName ); //for print computer name in the console

    fprintf(cname, "\nComputer name   : %s\n",pcName); // To write computer name into the file

    fclose(cname); //Close the file



  FILE *stInfo; //File pointer to to hold reference to our file

    stInfo = fopen("CA_Log.txt","a+"); //Open the text file in both reading and writing mode

    int index = 20792;  //Declare variables for assign Student information
    char uname[] = "De Silva WDDK";

    printf("------------------------------------------------------------------------------\n");
    fprintf(stInfo,"------------------------------------------------------------------------------\n");

    printf("***** Student Name : %s",uname); // Print Student information
    printf("\t\t    Student ID   : %d *****\n",index);

    fprintf(stInfo,"***** Student Name : %s\t\t    Student ID   : %d *****\n",uname,index);   // To write Student information into the file

    printf("------------------------------------------------------------------------------\n\n");
    fprintf(stInfo,"------------------------------------------------------------------------------\n\n");
    fclose(stInfo); //Close the file



  FILE *sLoop; //File pointer to to hold reference to our file

    float num[20] , square[20] ;  //Declare arrays for assign values
    int i;

    sLoop = fopen("CA_Log.txt","a+"); //Open the text file in both reading and writing mode

    for(i=0 ; i<20 ; i++){ //Declare a for loop for assign input values to the array
    printf("Please Enter No. %d Value : ",i+1);
    scanf("%f", &num[i]); }

     for(i=0 ; i<20 ; i++){ //Declare a for loop for print square values

     time_t c_time; //this data type store the calender time
            time(&c_time); // change the existing time format to the local time format
            timeOut(2); //set time out for 2 seconds

    square[i] = num[i] * num[i] ; //Process for getting the square value

    printf("\n%d : Square of %.2f   = %.2f     --> %s \n", i+1,num[i],square[i],ctime(&c_time)); // Print Square values and execute time in console

    fprintf(sLoop, "\n%d : Square of %.2f   = %.2f     --> %s \n", i+1,num[i],square[i],ctime(&c_time));// Print Square values and execute time in file
     }

    printf("\n");
    fclose(sLoop); //Close the file

   };break; //for not to execute the rest of lines



 case 2 : {//if input is 2, then execute this data retrieving code section

     FILE * dataRet;

    char x;

    dataRet = fopen("CA_Log.txt", "r"); //Open the text file in reading mode


    if(dataRet == NULL) // fopen() return NULL if last operation was unsuccessful
    {
        printf("Can't open the file.\nPlease check whether the file exists"); }


    printf("\n\n\t\t** File opened successfully ** \n\n");
    do
    {
        x = fgetc(dataRet); // Read single character from file

        putchar(x);  //Print character read on console

    } while(x != EOF); //loop iterate  till end of the file


    time_t t;
    time(&t);

    printf("\n Current system date and time: %s ", ctime(&t));

    fclose(dataRet); //Close the file

 };break; //for not to execute the rest of lines



 case 3 :  { exit(1);  } //exit function for terminate the program

 default : { printf("\nInvalid Choice !!! Please try again... \n "); } //check the input valid or not

 }



}


