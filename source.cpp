#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
										  /*

					          |
						 /-\
					        //-\\
					       //---\\
					      //-----\\
					     //-------\\
					    //---------\\
					   //-----------\\
					  //-------------\\
					 //---------------\\
					//                 \\
				       //                   \\
				      //                     \\                    */
class player                         //                       \\
{                                   //                         \\
    private:                       //                           \\
	    int age;              //--------player's age---------\\
	    char fName[20];      //---------first name------------\\
	    char lName[20];     //----------last name--------------\\
	    char team[60];     //-----------current team------------\\
	    char league[40]   //----------player's league------------\\
	    char pos[5];     //-------------position------------------\\
	    float wSal;     //--------------weekly salary--------------\\
	    int gps;       //---------------goals per season------------\\
	    int match;    //------no of match the player has played------\\
	    int rating;  //-----------------player rating-----------------\\
	    int bPrice; //-------------base price of a player--------------\\
	    void price( int gps, int wSal, int mat, int age, int rating)
	    {
		bPrice= ((gps/mat)*100) + wSal + salPerage(age) + salPerrat(rating);
	    }

    public:
	   int salPerage(int age);
	   int salPerrat(int rating);
		   void getData()
	   {
	       int age;
	       cout << "Enter player's first name- \n";
	       gets(fName);
	       cout << "Enter player's last name- \n";
	       gets(lName);
	       cout << "Enter the league in which the players is playing";
	       gets(league);
	       cout << "Enter player's team name- \n";
	       gets(team);
	       cout << "Enter player's position- \n";
	       gets(pos);
	       cout << "Enter player's age- \n";
	       cin >>age;
	       cout << "Enter player's weekly salary- \n";
	       cin >>wSal;
	       cout << "Enter player's goals per season- \n";
	       cin >>gps;
	       cout << "Enter player's matches- \n";
	       cin >>match;
	       cout << "Enter player's rating- \n";
	       cin >> rating;
	   }

	   void showData()
	   {
	       cout << "Player's first name- \n";
	       cout << fName << endl;
	       cout << "Player's last name- \n";
	       cout << lName << endl;
	       cout << "Legaue in which the player is playing -";
	       cout << league << endl;
	       cout << "Player's team name- \n";
	       cout << team << endl;
	       cout << "Player's position- \n";
	       cout << pos << endl;
	       cout << "Player's age- \n";
	       cout << age << endl;
	       cout << "Player's weekly salary- \n";
	       cout << wSal << endl;
	       cout << "Player's goals per season- \n";
	       cout << gps << endl;
	       cout << "Player's matches- \n";
	       cout << match << endl;
	       cout << "Player's rating- \n";
	       cout << rating << endl;
	   }

	   char *retfName()
	   {
	       return(fName);
	   }

	   char *retlName()
	   {
	       return(lName);
	   }

	   char *retLeague()
	   {
	       return(pLeague);
	   }

	   char *retTeam()
	   {
	       return(team);
	   }

	   int retwSal()
	   {
	       return wSal;
	   }

	   int retpRate()
	   {
	       return rating;
	   }

	   int retbPrice()
	   {
	       return bPrice;
	   }
};

player p1, p2;

int player::salPerage(int age) // salary based on the player's age
{
    if(age < 19)
       return 10000;
    else if((age < 22)&&(age >= 19))
       return 14500;
    else if((age < 24)&&(age >= 22))
       return 19000;
    else if((age < 26)&&(age >= 24))
       return 23500;
    else if((age < 28)&&(age >= 26))
       return 22000;
    else if((age < 31)&&(age >= 28))
       return 20500;
    else if((age < 34)&&(age >= 31))
       return 18500;
    else if((age < 38)&&(age >= 34))
       return 16500;
    else if((age < 55)&&(age >= 38))
       return 11000;
}

int player:: salPerrat(int rating) //salary based on rating
{
    if(rating > 95)
       return 50000;
    else if((rating > 90)&&(rating <= 95))
       return 48000;
    else if((rating > 85)&&(rating <= 90))
       return 43000;
    else if((rating > 78)&&(rating <= 85))
       return 37000;
    else if((rating > 70)&&(rating <= 78))
       return 31000;
    else if((rating > 60)&&(rating <= 70))
       return 24000;
    else if((rating > 50)&&(rating <= 60))
       return 18500;
    else if((rating > 40)&&(rating <= 50))
       return 12000;
    else if((rating >  0)&&(rating <=40))
       return 4500;
    else
       cout << " :( sorry buddy, wrong input";
}

// /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\ /\/\

int  choice;
char ans;
fstream infile, temp;

void create()
{
    ans = 'y';
    infile.open("transfer.dat", ios::out | ios::binary);
    while(ans == 'y' || ans == 'Y')
    {
	p1.getdata();
	infile.write((char*)&p1, sizeof(p1));
	cout << "record entered \n";
	cout << "do u want to enter another info y/n- ";
	cin >> ans;
    }
    infile.close();
}

void search()
{
    int i, n, choice1;
    cout << "Welcome to player search window \n";
    cout << "1. Browse full player list \n";
    cout << "2. Search player details \n";
    cout << "Enter choice - \n";
    cin >> choice;
    switch(choice)
    {
	case 1: infile.open("transfer.dat", ios::in | ios::binary);
		while(infile.read((char*)&p1, sizeof(p1)))
		{
		    do{
			for(i = 0 ; i < 2 ; i++)
			{
			    p1.showData();
			}
			cout << "do u want to go next page-";
			cin >> ans;
			clrscr();
		    }while(ans == 'Y' || ans == 'y');
		    if(ans != 'Y' || ans != 'y')
			break;
		}
		infile.close();
		break;

	case 2: cout << "Search details according to - \n";
		cout << "1. Player's first name \n";
		cout << "2. Player's last name \n";
		cout << "3. league(s)";
		cout << "4. Team \n";
		cout << "5. Weekly salary \n";
		cout << "6. Rating between a certain range \n";
		cout << "7. Range of base price \n";
		cin  >> choice1;
		switch(choice1)
		{
		    case 1: infile.open("transfer.dat", ios::in | ios::binary);
			    char pfName[20];
			    cout<< "Enter first name \n";
			    gets(pfName);
			    while(infile.read((char*)&p1, sizeof(p1)))
			    {
				if(strcmpi(pfName, p1.retfName())==0)
				    p1.showData();
			    }
			    infile.close();
			    break;
		    case 2: infile.open("transfer.dat", ios::in | ios::binary);
			    char plName[20];
			    cout << "Enter last name \n";
			    gets(plName);
			    while(infile.read((char*)&p1, sizeof(p1)))
			    {
				if(strcmpi(plName, p1.retlName())==0)
				    p1.showData();
			    }
			    infile.close();
			    break;
		    case 3: infile.open("transfer.dat", ios::in | ios::binary);
			    char pLeague[40][30];
			    int lNo, i;
			    cout << "Enter the no of league you want to search";
			    cin >> lNo;
			    while(lNo == 0)
			    {
				cout << "wrong input";
				cin >> lno;
			    }
			    for(i=0 ; i<lNo ; i++)
			    {
				gets(pLeague[i]);
			    }
			    for(i=0 ; i<lNo ; i++)
			    {
				while(infile.read((char*)&p1, sizeof(p1)))
				{
				    if(strcmpi(pLeague[i], p1.retLeague())==0)
					p1.showData();
				}
				infile.seekg(0);
			    }
			    infile.close();
			    break;
		    case 4: infile.open("transfer.dat", ios::in | ios::binary);
			    char pTeam[60];
			    cout << "Enter Team name \n";
			    gets(pTeam);
			    while(infile.read((char*)&p1, sizeof(p1)))
			    {
				if(strcmpi(pTeam, p1.retTeam())==0)
				    p1.showData();
			    }
			    infile.close();
			    break;
		    case 5: infile.open("transfer.dat", ios::in | ios::binary);
			    int lwSal, uwSal;
			    cout << "Enter lower limit of weekly salary \n";
			    cin >> lwSal;
			    cout << "Enter upper limit of weekly salary \n";
			    cin >> uwSal;
			    while(infile.read((char*)&p1, sizeof(p1)))
			    {
				if(lwSal >= p1.retwSal() &&  uwSal <= p1.retwSal())
				    p1.showData();
			    }
			    infile.close();
			    break;
		    case 6: infile.open("transfer.dat", ios::in | ios::binary);
			    int pRate1, pRate2;
			    cout << "Enter lower limit of player rating \n";
			    cin >> pRate1;
			    cout << "Enter upper limit of weekly salary \n";
			    cin >> pRate2;
			    while(infile.read((char*)&p1, sizeof(p1)))
			    {
				if(pRate1 >= p1.retpRate() && pRate2 <= p1.retpRate())
				    p1.showData();
			    }
			    infile.close();
			    break;
		    case 7: infile.open("transfer.dat", ios::in | ios::binary);
			    int ubPrice, lbPrice;
			    cout << "Enter lower limit of base salary \n";
			    cin >> lbPrice;
			    cout << "Enter upper limit of base salary \n";
			    cin >> ubPrice;
			    while(infile.read((char*)&p1, sizeof(p1)))
			    {
				if(lbPrice >= p1.retbPrice() &&  ubPrice <= p1.retbPrice())
				    p1.showData();
			    }
			    infile.close();
			    break;
		    default: cout << "BUDDY, SORRY WRONG CALL :(:(:(:( \n";
		}
	default: cout << "BUDDY, SORRY WRONG CALL :(:(:(:( \n";
    }
}
void edit()
{
    cout << "WELCOME TO DATA EDIT WINDOW \n";
    cout << "1. Enter new data \n";
    cout << "2. Delete data \n";
    cout << "3. Edit a player record \n";
    cin >> choice;
    switch(choice)
    {
	case 1: infile.open("transfer.dat", ios::in | ios::binary);
		temp.open("new.dat", ios::out | ios::binary);
		do{
		    p1.getData();
		    infile.write((char*)&p1, sizeof(p1));
		    cout << "do u want to enter another record - \n";
		    cin >> ans;
		}while(ans == 'Y' || ans == 'y');
		infile.close();
		temp.close();
		remove("transfer.dat");
		rename("new.dat","transfer.dat");
		break;
	case 2:infile.open("transfer.dat", ios::in | ios::binary);
	       temp.open("new.dat", ios::out | ios::binary);
	       int rec = 1;
	       int delRec;
	       cout << "Enter record no to be deleted /n";
	       cin>>delRec;
	       infile.seekg(0);
	       while(infile.read((char*)&p1, sizeof(p1))
	       {
		   if (rec!=delRec)
		       temp.write((char*)&p1,sizeof(p1));
		   rec++;
	       }
	       temp.close();
	       infile.close();
	       remove("transfer.dat");
	       rename("new.dat","transfer.dat");
	       break;
	case 3:infile.open("transfer.dat", ios::in | ios::binary);
	       temp.open("new.dat", ios::out | ios::binary);
	       int rec=0;
	       int edtRec;
	       cout<<"Enter record no to edit /n";
	       cin>>edtRec;
	       while(infile.read((char*)&p1, sizeof(p1)))
	       {
		   r++;
		   if(rec==edtRec)
		   {
		       cout<<"Enter new details /n";
		       p2.getdata();
		    }
		    temp.write((char*)&p2, sizeof(p1));
	       }
	       temp.close();
	       infile.close();
	       remove("transfer.dat");
	       rename("new.dat","transfer.dat");
	       break;
	default: cout << "BUDDY, SORRY WRONG CALL :(:(:(:( \n";
    }
}

void main()
{
    clrscr();
    cout << " &&&       &&&&&      &&&  &&&&&&&&&  &&&          &&&&&&    &&&&&&     &&&&&     &&&&&   &&&&&&&&&  \n ";
    cout << "  &&&     &&& &&&    &&&   &&&        &&&         &&&       &&&  &&&    &&& &&& &&& &&&   &&&        \n ";
    cout << "   &&&   &&&  &&&   &&&    &&&&&&     &&&        &&&       &&&    &&&   &&&  &&&&&  &&&   &&&&&&     \n ";
    cout << "  	 &&& &&&    &&& &&&     &&&        &&&         &&&       &&&  &&&    &&&   &&&   &&&   &&&        \n ";
    cout << "	  &&&&&      &&&&&      &&&&&&&&&  &&&&&&&&     &&&&&&    &&&&&&     &&&    &    &&&   &&&&&&&&&  \n ";
    cout << endl << endl;
    cout << "						TO";
    cout << endl << endl;
    cout << "    &&&&&&&&&  &&&&&&&    &&&&&&&&&  &&&&    &&&  &&&&&&&&&  &&&&&&&&&  &&&&&&&&&  &&&&&&&    \n";
    cout << "	    &&&     &&&  &&&   &&&   &&&  &&&&&&  &&&  &&&        &&&        &&&        &&&  &&&   \n";
    cout << "	    &&&     &&&  &&&   &&&&&&&&&  &&& &&& &&&  &&&&&&&&&  &&&&&&&&&  &&&&&&&&&  &&&  &&&   \n";
    cout << "	    &&&     &&&&&&&    &&&   &&&  &&&  &&&&&&        &&&  &&&        &&&        &&&&&&&    \n";
    cout << "	    &&&     &&&  &&&   &&&   &&&  &&&    &&&&  &&&&&&&&&  &&&        &&&&&&&&&  &&&  &&&   \n";

    cout << "					          WINDOW \n";
    cout << "			     IT IS THE HOTTEST TIME OF THE FOOTBALL WORLD \n";
    cout << "			    WHEN THE MANAGERS ARE POACHING TOP FOOTBALLERS \n";
    cout << "Here u can - \n";
    cout << "1. Enter record to our database \n";
    cout << "2. Search from talent \n";
    cout << "3. Edit data base \n";
    cout << "What would you like to do, Sir \n";
    cin >> choice;
    switch(choice)
    {
	case 1:	cout << "Welcome to player database player database create data mode \n";
		cout << "Enter player details \n";
		create();
		break;
	case 2: cout << "Welcome to player database search mode \n";
		cout << "Here you can searching upcoming players for your team";
		search();
		break;
	case 3: cout << "Welcome to player database edut mode \n":
		edit();
		break;
	default: cout << "Sorry pal, wrong choice :( \n";
    }
    cout << "do you want use our service once again ?";
    cin >> ans;
    while(ans == 'Y' || ans == 'y')
    {
	cout << "1. Enter record to our database \n";
	cout << "2. Search from talent \n";
	cout << "3. Edit data base \n";
	cout << "What would you like to do, Sir \n";
	cin >> choice;
	switch(choice)
	{
	    case 1: cout << "Welcome to player database player database create data mode \n";
		    cout << "Enter player details \n";
		    create();
		    break;
	    case 2: cout << "Welcome to player database search mode \n";
		    cout << "Here you can searching upcoming players for your team";
		    search();
		    break;
	    case 3: cout << "Welcome to player database edut mode \n":
		    edit();
		    break;
	    default:cout << "Sorry pal, wrong choice :( \n";
		 // goto start;
		    break;
	}
	cout << "Sir do u want to continue";
	cin >> ans;
    }
}
