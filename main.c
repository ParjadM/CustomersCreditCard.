//Name:Parjad Minooei
//Student Number: 117047217
//Teacher: Yilmaz Cam
//Class: IPC 144
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//predefine variables
#define NAME_SIZE 50
#define TRUE 1
#define FALSE 0
// password length
#define LENGTH 8
#define CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

//typedef structure
typedef struct customer {
    char SfirstName[30];
    char SlastName[30];
    int Sage;
    char Semail[50];
    int Spersonalincome;
    unsigned long long int Scardnumber;
    char ESocialinsurance[9];
    struct phone {
        char PhoneNumber[10];
        int phonetype;
    } phone;
    struct address {
        char address[50];
        char address2[50];
        char city[30];
        char province[3];
        char postalcode[6];
    } address;
    struct job {
        int jobCategory;
        char jobdescription[30];
    } job;
} customer;

//initializing the struct and making a pointer
struct customer s;
struct customer *ptr;

//i made these for existing customers
char answer;
char CardN[20];
char PassW[20];


//existing card info
char EfirstName[] = "Joe";
char ElastName [] = "Black";
int Eage= 35;
char Eaddress[] = "Finch Ave E";
char Ecity[] = "Toronto";
char Eprovince[] = "ON";
char Epostalcode[] = "M2J2X5";
char Epassword[] = "SenecaC#55";
char Ecardnumber[] = "8457743262120459";
int Emonth = 12;
int Eday = 05;
int Eyear = 07;
char ECustomerID[]="JGBNREFC";
int jobCategory;
char jobdescription[30];



char password[50];
int month;
int day;
int year;
int livingsituation=0;
int Lmonth;
int Lyear;
int yearlyincome;
int otherincome;
int payhousing;
char ID[LENGTH+1];
long long cardnumber;

//extra
int upper=0;
int lower=0;
int special= 0;
int number =0;
char anything[50];
int i = 0;



//get information
void getFirstNameFromApplicant();
void getLastNameFromApplicant();
void getAgeFromApplicant();
void getCustomerPhoneNumber();
void getaddress();
void getaddress2();
void getcity();
void getprovince();
void getpostalcode();
void getPassword();
void getCardNumber();
void getYear();
void getMonth();
void getDay();
void getEmail();
void getphonetype();
void getlivingsituation();
void getLYear();
void getLMonth();
void getyearlyincome();
void getpersonalincome();
void getotherincome();
void getpayhousing();
void getcustomerID();
void getjobCategory();
void getjobdescription();

//special get information
void getinformation();
void generatecardnumber();
void generateID();
void structs();

//display information
void displaynew();
void displayexisting();

//check information
int checkName (char name[]);
int checkAge ();
int leapYearFeb(int yea, int mon);
int checkPhoneNumber(char PN[]);
int checkaddress(char addressinfo[]);
int checkaddress2(char addressinfo[]);
int checkcity (char city[]);
int checkprovince (char province[]);
int checkpostalcode (char postalcode[]);
int checkpassword (char password[]);
int checkyear(int year);
int checkmonth(int month);
int checkday(int day);
int checkemail(char email[]);
int checkPhoneType(int phonetype);
int checklivingsituation (int situation);
int checkLyear(int Lyear);
int checkLmonth(int Lmonth);
int checkyearlyincome(int yearlyincome);
int checkpersonalincome (int personalincome);
int checkotherincome (int otherincome);
int checkpayhousing (int payhousing);
int checkjobcategory (int jobCategory);
int checkjobdescription (char jobdescription[]);
int checkcustomerID ();
//main function
int main()
{
    //introduction of application
    printf("Hello, Welcome To The Bank!\n");
    printf("Are you an Existing client? (y/n)");
    scanf ("%c",&answer);
    if (answer == 'Y' || answer == 'y'){
        while (1){
        //must enter the exact card number and password or else it won't work (check variable EcardNumber and Epassword)
        printf ("Please enter your card number and password. \n");
        printf ("For demonstration purposes the card number is (8457743262120459)\n");
        printf ("Card Number: ");
        scanf ("%s", CardN);
        printf ("Enter Your Password: ");
        printf ("For demonstration purposes the password is (SenecaC#55)\n");
        scanf ("%s", PassW);
        if (strcmp(CardN,Ecardnumber) == 0 && strcmp(PassW,Epassword)==0)
        {
            //display applicant information according to the user name and password
            getEmail();
            getphonetype();
            getCustomerPhoneNumber();
            getlivingsituation();
            getLYear();
            getLMonth();
            getyearlyincome();
            getpersonalincome();
            getotherincome();
            getpayhousing();
            getjobCategory();
            getjobdescription();

            strcpy(s.ESocialinsurance,"857432456");
            ptr = &s;
            displayexisting();
            break;
        }
        //if they enter wrong password
        printf("you entered the wrong user name and password please try again \n");
        i = i +1;
        printf("you have three attempts this is attempt: %d\n", i);
        //after 3 fail attempts stop the loop and end the program
        if (i == 3){
            break;
            }
        }
    }
    else if (answer == 'N' || answer == 'n'){
        printf ("Please enter the following information to create a new credit card account \n");
        //get information
        getinformation();
        ptr = &s;
        //display the new information collected
        displaynew();
    }
    //if they didn't press the right answer
    else {
        printf("You've Enter wrong answer, please restart and try agian!");
    }
    return 0;
}



//void get information function
void getinformation()
{
        //call all the specific function to get information
        getFirstNameFromApplicant();
        getLastNameFromApplicant();
        getYear();
        getMonth();
        getDay();
        getAgeFromApplicant();
        getEmail();
        getphonetype();
        getCustomerPhoneNumber();
        getaddress();
        getaddress2();
        getcity();
        getprovince();
        getpostalcode();
        getlivingsituation();
        getLYear();
        getLMonth();
        getyearlyincome();
        getpersonalincome();
        getotherincome();
        getpayhousing();
        getcustomerID();
        getCardNumber();
        getPassword();
}

//display new customer information
void displaynew(){
        printf("\n\n\n\n\n\n----Applicant Information----\n");
        printf("Applicant First Name : %s\n",ptr->SfirstName);
        printf("Applicant Last Name : %s\n",ptr->SlastName);
        printf("Applicant date of birth Year: %d\n", year);
        printf("Applicant date of birth month: %d\n", month);
        printf("Applicant date of birth day: %d\n", day);
        printf("Applicant Age: %d\n",ptr->Sage);
        printf("Applicant Email %s\n", ptr->Semail);
        printf("Applicant Phone Type: 1:home, 2:work, 3:mobile: %d\n", ptr->phone.phonetype);
        printf("Applicant Phone Number: %s\n", ptr->phone.PhoneNumber);
        printf("Applicant Address1: %s\n", ptr->address.address);
        printf("Applicant Address2: %s\n", ptr->address.address2);
        printf("Applicant City: %s\n", ptr->address.city);
        printf("Applicant Province: %s\n", ptr->address.province);
        printf("Applicant Postal Code: %s\n", ptr->address.postalcode);
        printf("Applicant Living situation: 1.rent, 2.own/buying, 3.live with parents, 4.room/board, 5.others: %d\n", livingsituation);
        printf("Applicant number of year living in this place: %d\n", Lyear);
        printf("Applicant number of month living in this place: %d\n", Lmonth);
        printf("Applicant yearly income is: %d\n", yearlyincome);
        printf("Applicant personal income is: %d\n", ptr->Spersonalincome);
        printf("Applicant other income is: %d\n", otherincome);
        printf("Applicant pay for housing is: %d\n", payhousing);
        printf("Applicant customer ID is: %s\n", ID);
        printf("Applicant Card Number: %llu\n", ptr->Scardnumber);
        printf("Applicant Password: %s\n", password);
        printf("Application processed, new account has been made!\n");
        printf("Hope you have enjoyed and have a nice day!\n");
}
//existing customer information
void displayexisting(){
            printf("You have entered the correct user name and password. \n");
            printf("Welcome %s \n", EfirstName);
            printf("here are your current information! \n");
            printf("\n\n\n----Applicant Information----\n");
            printf("Applicant First Name : %s\n",EfirstName);
            printf("Applicant Last Name : %s\n",ElastName);
            printf("Applicant date of birth Year: %d\n", Eyear);
            printf("Applicant date of birth month: %d\n", Emonth);
            printf("Applicant date of birth day: %d\n", Eday);
            printf("Applicant Age: %d\n",Eage);
            printf("Applicant Email %s\n", ptr->Semail);
            printf("Applicant Phone Type: 1:home, 2:work, 3:mobile: %d\n", ptr->phone.phonetype);
            printf("Applicant Phone Number: %s\n", ptr->phone.PhoneNumber);
            printf("Applicant Address: %s\n", Eaddress);
            printf("Applicant City: %s\n", Ecity);
            printf("Applicant Province: %s\n", Eprovince);
            printf("Applicant Postal Code: %s\n", Epostalcode);
            printf("Applicant Living situation: 1.rent, 2.own/buying, 3.live with parents, 4.room/board, 5.others: %d\n", livingsituation);
            printf("Applicant number of year living in this place: %d\n", Lyear);
            printf("Applicant number of month living in this place: %d\n", Lmonth);
            printf("Applicant Social Insurance: %s\n", ptr->ESocialinsurance);
            printf("Applicant job Category: Category #: %d\n", ptr->job.jobCategory);
            printf("Applicant job description: %s\n", ptr->job.jobdescription);
            printf("Applicant yearly income is: %d\n", yearlyincome);
            printf("Applicant personal income is: %d\n", ptr->Spersonalincome);
            printf("Applicant other income is: %d\n", otherincome);
            printf("Applicant pay for housing is: %d\n", payhousing);
            printf("Applicant CustomerID: %s\n", ECustomerID);
            printf("Applicant Password: %s\n", Epassword);
            printf("Applicant Card Number: %s\n", Ecardnumber);
            printf("Thank you for using our program!\n");
}



//get first name from applicant
void getFirstNameFromApplicant()
{
	int validName=FALSE;
	printf("Please enter your first name: ");
	do
	{
		scanf("%s", s.SfirstName);
		validName = checkName(s.SfirstName);
	}while(!validName);
}

//get last name from applicant
void getLastNameFromApplicant ()
{
	int validName=FALSE;
	printf("Please enter your last name: ");

	do
	{
		scanf("%s", s.SlastName);
		validName = checkName(s.SlastName);
	}while(!validName);
}

//get age from applicant
void getAgeFromApplicant ()
{
    checkAge();

}

//get customer phone number from applicant
void getCustomerPhoneNumber()
{
    int validNumber=FALSE;
    printf("Please enter 10 digits phone number: ");
    do
    {
        scanf("%s", s.phone.PhoneNumber);
        validNumber = checkPhoneNumber(s.phone.PhoneNumber);
    }while(!validNumber);

}
//get address2 from applicant
void getaddress()
{
    int validNumber=FALSE;
    printf("Please enter your address1: ");
    do
    {
        scanf("%s", s.address.address);
        validNumber = checkaddress(s.address.address);
    }while(!validNumber);

}
//get address2 from applicant
void getaddress2()
{
    int validNumber=FALSE;
    printf("Please enter your address2: ");
    do
    {
        scanf("%s", s.address.address2);
        validNumber = checkaddress2(s.address.address2);
    }while(!validNumber);

}
//get city from applicant
void getcity()
{
    int validNumber=FALSE;
    printf("Please enter your city: ");
    do
    {
        scanf("%s", s.address.city);
        validNumber = checkcity(s.address.city);
    }while(!validNumber);

}
//get province information from applicant
void getprovince()
{
    int validNumber=FALSE;
    printf("Please enter your province (Example: ON): ");
    do
    {
        scanf("%s", s.address.province);
        validNumber = checkprovince(s.address.province);
    }while(!validNumber);

}
//get postal code from applicant
void getpostalcode()
{
    int validNumber=FALSE;
    printf("Please enter your Postal Code: ");
    do
    {
        scanf("%s", s.address.postalcode);
        validNumber = checkpostalcode(s.address.postalcode);
    }while(!validNumber);
}
//get password from applicant
void getPassword()
{
    int validNumber=FALSE;
    printf("Please enter your new Password: ");
    do
    {
        scanf("%s", password);
        validNumber = checkpassword(password);
    }while(!validNumber);

}
//get card number from applicant
void getCardNumber()
{
    generatecardnumber();

}
//get year of birth from applicant
void getYear()
{
    int validNumber=FALSE;
    printf("Please enter your Date of Birth (Year): ");
    do
    {
        scanf("%d", &year);
        validNumber = checkyear(year);
    }while(!validNumber);

}
//get month of birth from applicant
void getMonth()
{
    int validNumber=FALSE;
    printf("Please enter your Date of Birth (Month): ");
    do
    {
        scanf("%d", &month);
        validNumber = checkmonth(month);
    }while(!validNumber);

}
//get the day of birth from applicant
void getDay()
{
    int validNumber=FALSE;
    printf("Please enter your Date of Birth (Day): ");
    do
    {
        scanf("%d", &day);
        validNumber = checkday(day);
    }while(!validNumber);

}
//get email
void getEmail()
{
    int validNumber=FALSE;
    printf("Please enter your Email (Example@email.ca): ");
    do
    {
        scanf("%s", s.Semail);
        validNumber = checkemail(s.Semail);
    }while(!validNumber);

}
//get phone type
void getphonetype()
{
    int validNumber=FALSE;
    printf("Please enter your Phonetype 1.home, 2.work, 3.mobile: ");
    do
    {
        scanf("%d", &s.phone.phonetype);
        validNumber = checkPhoneType(s.phone.phonetype);
    }while(!validNumber);

}
//get living situation
void getlivingsituation()
{
    int validNumber=FALSE;
    printf("Please enter your living situation 1.rent, 2.own/buying, 3.live with parents, 4.room/board, 5.others: ");
    do
    {
        scanf("%d", &livingsituation);
        validNumber = checklivingsituation(livingsituation);
    }while(!validNumber);

}
//get years living in the address
void getLYear()
{
    int validNumber=FALSE;
    printf("Please enter number of Years living in this address: ");
    do
    {
        scanf("%d", &Lyear);
        validNumber = checkLyear(Lyear);
    }while(!validNumber);

}
//get month living in the address
void getLMonth()
{
    int validNumber=FALSE;
    printf("Please enter number of month living in this address: ");
    do
    {
        scanf("%d", &Lmonth);
        validNumber = checkLmonth(Lmonth);
    }while(!validNumber);

}
//get yearly income
void getyearlyincome()
{
    int validNumber=FALSE;
    printf("Please enter your yearly income: ");
    do
    {
        scanf("%d", &yearlyincome);
        validNumber = checkyearlyincome(yearlyincome);
    }while(!validNumber);

}
//get personal income
void getpersonalincome()
{
    int validNumber=FALSE;
    printf("Please enter your personal income: ");
    do
    {
        scanf("%d", &s.Spersonalincome);
        validNumber = checkpersonalincome(s.Spersonalincome);
    }while(!validNumber);

}
//get other income
void getotherincome()
{
    int validNumber=FALSE;
    printf("Please enter your other income: ");
    do
    {
        scanf("%d", &otherincome);
        validNumber = checkotherincome(otherincome);
    }while(!validNumber);

}
//get pay housing
void getpayhousing()
{
    int validNumber=FALSE;
    printf("Please enter how much you pay for housing: ");
    do
    {
        scanf("%d", &payhousing);
        validNumber = checkpayhousing(payhousing);
    }while(!validNumber);

}
//get customer ID
void getcustomerID()
{
    generateID();
}
//get job category
void getjobCategory()
{
    int validNumber=FALSE;
    printf("Please enter your job category 1.category 1, 2.category 2, 3.category 3, 4.category 4, 5.category 5: ");
    do
    {
        scanf("%d", &s.job.jobCategory);
        validNumber = checkjobcategory(s.job.jobCategory);
    }while(!validNumber);

}
//get job description
void getjobdescription()
{
    int validNumber=FALSE;
    printf("Please enter your job description: ");
    do
    {
        scanf("%s", s.job.jobdescription);
        validNumber = checkjobdescription(s.job.jobdescription);
    }while(!validNumber);

}




//check user name
int checkName (char name[])
{
    //Name should be more than 1 character
    if (strlen(name) < 2)
    {
        fprintf(stderr, "Please enter a valid name: %s is too short!\n", name);
        return FALSE;
    }
    else
    {
        //loop through each character in the name and make sure it is an alphabetical (A-Z or a-z) character.
        for (unsigned int index = 0; index < strlen(name); index++)
        {
            if (!isalpha(name[index]))
            {
                fprintf(stderr, "Please enter a valid name: %s should contain only alphabetical A-Z or a-z chars!\n", name);

                return  FALSE;
            }
        }
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check age specification
int checkAge ()
{
    //Days in month
	int daysInMonth[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
	time_t ts;
	struct tm *cti;

    //Find the current month
	ts = time(NULL);
    cti = localtime(&ts);
    day = daysInMonth[month - 1] - day + 1;

    //Checking the given year Leap or not
    if (leapYearFeb(year, month))
    {
        day = day + 1;
    }

    day = day + cti->tm_mday;
    month = (12 - month) + (cti->tm_mon);
    int years = (cti->tm_year + 1900) - year - 1;
    //check for leap year
	if (leapYearFeb((cti->tm_year + 1900), (cti->tm_mon + 1)))
    {
        if (day >= (daysInMonth[cti->tm_mon] + 1))
        {
            day = day - (daysInMonth[cti->tm_mon] + 1);
            month = month + 1;
        }
    }
    else if (day >= daysInMonth[cti->tm_mon])
    {
        day = day - (daysInMonth[cti->tm_mon]);
        month += + 1;
    }
    if (month >= 12)
    {
        years += + 1;
        month = month - 12;
    }

    //check if applicant is old enough
	if(years<18)
	{
		printf("Age must be 18 or older. Please enter valid age: \n");
		return FALSE;
	}
	else {
        s.Sage = years;
        return TRUE;
	}

}
// check phone number must be 10 digits long
int checkPhoneNumber(char PN[])
{
    if (strlen(PN) != 10)
    {
        fprintf(stderr, "Please enter a 10 digit Phone Number: \n");
        return FALSE;
    }
    else
    {

        for (unsigned int index = 0; index < strlen(PN); index++)
        {
            if (!isdigit(PN[index]))
            {
                fprintf(stderr, "Please enter a valid name: %s should contain only digits containing 0-9! \n", PN);

                return  FALSE;
            }
        }
    }
    return TRUE;
}
//get the address from applicant
int checkaddress (char addressinfo[])
{
    //Name should be more than 1 character
    if (strlen(addressinfo) > 50)
    {
        fprintf(stderr,"Please enter a valid address: %s is too long!\n", addressinfo);
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
int checkaddress2 (char address2info[])
{
    //Name should be more than 1 character
    if (strlen(address2info) > 50)
    {
        fprintf(stderr,"Please enter a valid address: %s is too long!\n", address2info);
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}

//check city information
int checkcity (char city1[])
{
    //less than 30 character city name should be
    if (strlen(city1) > 30)
    {
        fprintf(stderr,"Please enter a valid city: %s is too long!\n", city1);
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check province information
int checkprovince (char province1[])
{
    //province is 2 character code
    if (strlen(province1) != 2)
    {
        fprintf(stderr, "Please enter a valid province: %s must be two characters!\n", province1);
        return FALSE;
    }

    if (strcmp(province1,"ab")==0 || strcmp(province1,"bc")==0 || strcmp(province1,"mb") ==0 || strcmp(province1,"nb")==0 || strcmp(province1,"nl")==0 || strcmp(province1,"nt")==0  || strcmp(province1,"ns")==0  || strcmp(province1,"nu") ==0 || strcmp(province1,"on")==0 || strcmp(province1, "pe") ==0 || strcmp(province1, "qc") ==0 || strcmp(province1,"sk") ==0 || strcmp(province1,"yt") ==0 || strcmp(province1,"AB")==0 || strcmp(province1,"BC")==0 || strcmp(province1,"MB") ==0 || strcmp(province1,"NB")==0 || strcmp(province1,"NL")==0 || strcmp(province1,"NT")==0  || strcmp(province1,"NS")==0  || strcmp(province1,"NU") ==0 || strcmp(province1,"ON")==0 || strcmp(province1, "PE") ==0 || strcmp(province1, "QC") ==0 || strcmp(province1,"SK") ==0 || strcmp(province1,"YT") ==0)
    {
        return TRUE;

    }
    else
    {
        fprintf(stderr, "Please enter a valid province: %s doesn't match!\n", province1);
         return FALSE;
    }
}
//check postal code
int checkpostalcode (char postalcode[])
{
    //postal code should be 6 character long
    if (strlen(postalcode) != 6)
    {
        fprintf(stderr, "Please enter a valid city: %s Must be six characters\n", postalcode);
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check year of birth
int checkyear (int year1)
{
    //years should be between 1900-2023
    if (1899 >= year1 || year1 >= 2024)
    {
        printf("Please enter a valid year. between 1900-2023\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check month
int checkmonth (int month1)
{
    //month should be from 0-12
    if (0 >= month1 || month1>= 13)
    {
        printf("Please enter a valid month: between 1-12\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check the day of birth
int checkday (int day1)
{
    //day should be from 1-31
    if (0 >= day1 || day1>= 32)
    {
        printf("Please enter a valid day: between 1-31\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check the password is created correctly
int checkpassword (char password1[])
{
    //should be more than 8 character long
    if (strlen(password1) < 7)
    {
        fprintf(stderr,"Please enter a valid password: %s it's too short must be at least 8 character long\n", password1);
        return FALSE;
    }
    char test[4];
    //insert year which is int into test which is char array
    sprintf(test, "%d", year);

    //should not contain common characters
    if (strstr(password1, "12345678") || strstr(password1, "1234567890") || strstr(password1, "1234567890") ||strstr(password1, "qwerty12") ||strstr(password1, "password") ||strstr(password1, "1q2w3e4r") ||strstr(password1, "11111111") ||strstr(password1, "abcd1234") ||strstr(password1, "AAAAAAAA")||strstr(password1, test)){
        fprintf(stderr,"Please enter a valid password: %s it should not be common password\n", password);
        return FALSE;
    }
    //loop through to check for special requirement for password
    for(int v=0; password1[v] != '\0'; v++)
    {
        //check for upper case
        if(password1[v]>='A' && password1[v]<='Z')
        {
            upper++;
        }
        //check for lower case
        else if(password1[v]>='a' && password1[v]<='z')
        {
            lower++;
        }
        //check for special character
        else
        {
            special++;
        }
        //check for number
        if(isdigit(password1[v]))
        {
            number++;
        }
    }
    //check if it contains 1 character each
    if (upper < 1 || lower < 1 || special < 1 || number < 1)
    {
        fprintf(stderr,"Please enter a valid password: %s it needs to contain 1 upper case, 1 lowercase, 1 digit and 1 special\n", password);
        return FALSE;
    }

    //seems everything went well and is valid.
    return TRUE;
}
//check for correct email
int checkemail (char email1[])
{
    //if email contain . or @
    if (!strstr(email1, ".") && !strstr(email1, "@")){
        fprintf(stderr,"Please enter a valid password: %s it should contain . and @ \n", email1);
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check phone type
int checkPhoneType (int phonetype1)
{
    //user should enter 1-3
    if (0 >= phonetype1 || phonetype1 >= 4)
    {
        printf("Please enter a valid phone type: between 1-3\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check living situation
int checklivingsituation (int livingsituation1)
{
    //living situation should be 1-5
    if (0 >= livingsituation1 || livingsituation1 >= 6)
    {
        printf("Please enter correct living situation: between 1-5\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check living year
int checkLyear (int Lyear1)
{
    //years should be between 0-99
    if (-1 >= Lyear1 || Lyear1 >= 100)
    {
        printf("Please enter a valid year. between 0-99\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check living month
int checkLmonth (int Lmonth1)
{
    //month should be from 0-12
    if (0 >= Lmonth1 || Lmonth1>= 13)
    {
        printf("Please enter a valid month: between 1-12\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}



//check yearly income
int checkyearlyincome (int yearlyincome1)
{
    //check if it's digits
    if (isdigit(yearlyincome1))
    {
        printf("Please enter a digit\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check personalincome
int checkpersonalincome (int personalincome1)
{
    //checks if it's more than 15000
    if (15000 > personalincome1)
    {
        printf("Please enter valid number: must be greater than $15,000\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check other income
int checkotherincome (int otherincome1)
{
    //check if it's digits
    if (isdigit(otherincome1))
    {
        printf("Please enter a integer only\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check pay for housing
int checkpayhousing (int payhousingv)
{
    //check if it's digits
    if (isdigit(payhousingv))
    {
        printf("Please enter a integer only\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
//check customerID
int checkcustomerID (char customerID1[])
{
    //should be 8 character long
    if (strlen(customerID1) != 8)
    {
        fprintf(stderr, "Please enter a 8 character long customer ID: \n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}


//special function
void generatecardnumber()
{
    unsigned b;
    cardnumber = rand() % 9 + 1;

    // Add 15 more digits
    for (b = 0; b < 15; b++)
    {
        cardnumber *= 10;
        cardnumber += rand() % 10;
    }
    s.Scardnumber = cardnumber;
    //prints out the card number
    printf("The CardNumber is: %llu \n", s.Scardnumber);
}
void generateID()
{
    srand(time(NULL)); // seed the random number generator

    // loop to generate the id
    for (int v = 0; v < LENGTH; v++) {
        ID[v] = CHARS[rand() % (sizeof(CHARS) - 1)]; // select a random character from the character set
    }

    ID[LENGTH] = '\0'; // null-terminate the string

    printf("Customer ID is : %s\n", ID); // print the id

}

//Leap year
int leapYearFeb(int yea, int mon)
{
    int test = 0;
    if (yea % 100 == 0)
    {
        if (yea % 400 == 0)
        {
            if (mon == 2)
            {
                test= 1;
            }
        }
    }
    else if (yea % 4 == 0)
    {
        if (mon == 2)
        {
            test = 1;
        }
    }
    return (test);
}

//check job category
int checkjobcategory (int jobCategory1)
{
    //living situation should be 1-5
    if (0 >= jobCategory1 || jobCategory1 >= 6)
    {
        printf("Please enter correct living situation: between 1-5\n");
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}


//get job description
int checkjobdescription (char jobdescription1[])
{
    //Name should be more than 1 character
    if (strlen(jobdescription1) > 30)
    {
        fprintf(stderr,"Please enter a valid job description: %s is too long! 30 character only\n", jobdescription);
        return FALSE;
    }
    //seems everything went well and is valid.
    return TRUE;
}
