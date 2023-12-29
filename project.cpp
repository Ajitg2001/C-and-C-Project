#include <string.h>
#include <stdlib.h>
#include <iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

struct player {
    int jersey_Number;
    char name[20];
    int runs;
    int wicket;
    int match_played;
    
    player()
    {
    	this->jersey_Number=0;
    	strcpy(this->name,"not given");
    	this->runs=0;
    	this->wicket=0;
    	this->match_played=0;
	}
	player(int n,char*nm,int r,int w,int m)
	{
		this->jersey_Number=n;
		strcpy(this->name,nm);
		this->runs=r;
		this->wicket=w;
		this->match_played=m;
	}
	void setjersey_Number(int i)
	{
		this->jersey_Number=i;
	}
	int getjersey_Number()
	{
		return this->jersey_Number;
	}
	void setname(char* nm)
	{
		strcpy(this->name,nm);
	}
	char* getname()
	{
		return this->name;
	}
	void setruns(int r)
	{
		this->runs=r;
	}
	int getruns()
	{
		return this->runs;
	}
	void setwicket(int w)
	{
		this->wicket=w;
	}
	int getwicket()
	{
		return this->wicket;
	}
	void setmatch_played(int m)
	{
		this->match_played=m;
	}
	int getmatch_played()
	{
		return this->match_played;
	}
	
	void Display()
	{
  		int i;
   		cout<<"---------------------------------------------------------------------------------------------------------------\n";
   		cout<<"jersey_Number \t | \t name \t                |runs \t                | wickets\t|match_played   |\n";
  		cout<<"---------------------------------------------------------------------------------------------------------------\n";
		cout <<" "<<this->jersey_Number<<"\t\t |  "<<this->name<<"\t \t        | "<<this->runs<<"\t\t         | "<<this->wicket<<"\t\t| "<<this->match_played<<"\t\t|\n";
	
        cout<<"---------------------------------------------------------------------------------------------------------------\n";
	}
//	void store()
//	{
//		cout<<"Enter the Jersey_no";
//		cin>>this->jersey_Number;
//		cout<<"Enter the name";
//		cin>>this->name;
//		cout<<"Enter the runs";
//		cin>>this->runs;
//		cout<<"Enter the Wickets";
//		cin>>this->wicket;
//		cout<<"Enter the Matched_Played";
//		cin>>this->match_played;
//	}
};

void store(player* b1);
void Display(player*, int);
void Add_Player(player*, int&);
int Remove_Player(player*, int, int);
int Search_Player(player*, int, int);
void update(player*, int, int);
void maxruns(player*, int);
void maxwickets(player*, int);
void Display_All_Player(player*, int);

int main() {
    int size = 100;
    player *b1 = new player[size];
    int exit;
    int i, t, ch1;
    int count;
    cout << "Enter no of Players: ";
    cin >> count;
    store(b1);
    do {
        cout << "************************Enter Your Choice***************************";
        cout << "\n1.Display\n2.Add_Player\n3.Remove_Player\n4.Search_Player\n5.Update_data\n6.Display_Top_3_Players\n7.Display_All_Players\n";
        int choice;

        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
            	for(i=0;i<count;i++)
            	{
            		b1[i].Display();
				}
            	
                //Display(b1, count);
            }
                break;
            case 2: {
                if (count < size) {
                    Add_Player(b1, count);
                    for(i=0;i<count;i++)
                    {
                    	b1[i].Display();
					}
                    //Display(b1, count);
                } else {
                    cout << "Cannot add more players. Maximum limit reached.\n";
                }
            }
                break;
            case 3: {
                cout << "\nEnter The jersey number for remove";
                int j_no;
                cin >> j_no;
                count = Remove_Player(b1, j_no, count);
                cout<<"AFTER REMOVING PLAYER\n";
                for(i=0;i<count;i++)
                {
                    	b1[i].Display();
				}
                }
                break;
            case 4: {
                int j_no;
                cout << "\nEnter the Jersey Number to search a player:";
                cin >> j_no;
                Search_Player(b1, count, j_no);
                }
                break;
            case 5: {
                int jer_num;
                cout << "Enter players jersey number to update player : ";
                cin >> jer_num;
                update(b1, jer_num, count);   
                }
                break;
            case 6: {
                cout << "Display Top 3: ";
                cout << "\n1.Runs Scored \n2.Wickets\n";
                cin >> t;

                if (t == 1) {
                    maxruns(b1, count);
                    for(i=0;i<3;i++)
                    {
                    	b1[i].Display();
					}
                    //Display(b1, 3);
                } 
				if (t == 2) {
                    maxwickets(b1, count);
                    for(i=0;i<3;i++)
                    {
                    	b1[i].Display();
					}
                   //Display(b1, 3);
                }
                }
                break;
            case 7:
                Display_All_Player(b1, count);
                break;
            default:
                cout << "not found";
                break;
        }
        cout << "\nDo you want to continue(0/1)? \n";
        cin >> exit;
    } while (exit == 1);
}
void store(player* b){

	b[0].setjersey_Number(1);
	b[0].setname("virat");
	b[0].setruns(110);
	b[0].setwicket(15);
	b[0].setmatch_played(25);

	b[1].setjersey_Number(2);
	b[1].setname("dhoni");
	b[1].setruns(120);
	b[1].setwicket(20);
	b[1].setmatch_played(35);

	b[2].setjersey_Number(3);
	b[2].setname("Raina");
	b[2].setruns(130);
	b[2].setwicket(25);
	b[2].setmatch_played(45);
	
	b[3].setjersey_Number(4);
	b[3].setname("Rahul");
	b[3].setruns(140);
	b[3].setwicket(30);
	b[3].setmatch_played(55);
	
	b[4].setjersey_Number(5);
	b[4].setname("Dhawan");
	b[4].setruns(150);   
	b[4].setwicket(35);
	b[4].setmatch_played(65);
	
	b[5].setjersey_Number(6);
	b[5].setname("Sachin");
	b[5].setruns(150);  
	b[5].setwicket(40);
	b[5].setmatch_played(75);

    b[6].setjersey_Number(6);
	b[6].setname("Sachin");
	b[6].setruns(160);  
	b[6].setwicket(40);
	b[6].setmatch_played(75);
	
	
	b[6].setjersey_Number(7);
	b[6].setname("Ishant");
	b[6].setmatch_played(85);
	b[6].setruns(170);
	b[6].setwicket(45);
	
	b[7].setjersey_Number(8);
	b[7].setname("Ashwin");
	b[7].setmatch_played(95);
	b[7].setruns(180);
	b[7].wicket = 50;
	
	b[8].setjersey_Number(9);
	b[8].setname("Jadeja");
	b[8].setmatch_played(105);
	b[8].setruns(190);
	b[8].setwicket(55);
	
	b[9].setjersey_Number(10);
	b[9].setname("Shami");
	b[9].setmatch_played(115);
	b[9].setruns(200);
	b[9].setwicket(60);
	
	b[10].setjersey_Number(11);
	b[10].setname("Bumrah");
    b[10].setmatch_played(125);
	b[10].setruns(210);
	b[10].setwicket(65);	
}
void Add_Player(player* b1, int& count) {
    int n;
    cout << "Enter number of players you want to add: ";
    cin >> n;
    int i;
    for (i = 0; i < n; i++) {
        cout << "Enter Jersey_No: ";
        cin >> b1[count].jersey_Number;
        cout << "Enter name: ";
        cin >> b1[count].name;
        cout << "Enter runs: ";
        cin >> b1[count].runs;
        cout << "Enter wickets: ";
        cin >> b1[count].wicket;
        cout << "Enter Matches Played: ";
        cin >> b1[count].match_played;
        count++;
    } 
}
int Remove_Player(player* b1,int j_no,int n)
{
	int i,j,flag=0;
	int index = Search_Player(b1,n,j_no);
	if(index !=-1)
  	{
  		for(j=index;j<n;j++)
   		{
   	    	b1[j]=b1[j+1];
   	    	
		}
		n=n-1;	
	}
  return n;
}
int Search_Player(player* b1,int n,int j_no)
{
   int i;
   for (i = 0; i < n; i++)
   {
      if (b1[i].jersey_Number == j_no)
      {
            cout << "---------------------------------------------------------------------------------------------------------------\n";
            cout << "jersey_Number \t | \t name \t                |runs \t                | wickets\t|match_played   |\n";
            cout << "---------------------------------------------------------------------------------------------------------------\n";
            cout << " " << b1[i].jersey_Number << "\t\t |  " << b1[i].name << "\t \t        | " << b1[i].runs << "\t\t         | " << b1[i].wicket << "\t\t| " << b1[i].match_played << "\t\t|\n";
            cout << "---------------------------------------------------------------------------------------------------------------\n";
            return i;
      }
   }
    cout<<"No player found with jersey no:";
	cin>>j_no;
	return -1;	
}
void update(player *b1, int jer_num,int n)
{
   int i, flag = 0;
   for (i = 0; i <n; i++)
   {
      if ( b1[i].jersey_Number== jer_num)
      {
         flag = 1;

         cout<<"Enter Runs : ";
         cin>>b1[i].runs;
         cout<<"Enter wickets : ";
         cin>>b1[i].wicket;
         cout<<"Enter no_of_matches: ";
         cin>>b1[i].match_played;
         cout<<"updated successfully \n";
         break;
      }
   }
   if (flag == 0)
      cout<<"No player found with jersy no \n"<<jer_num;
}
void maxruns(player* b1, int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (b1[j].runs<b1[j+1].runs){
                player temp= b1[j];
                b1[j] = b1[j + 1];
                b1[j+1]=temp;
            }
        }
    }
}   
void maxwickets( player* b1,int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (b1[j].wicket<b1[j+1].wicket){
                player temp=b1[j];
                b1[j]=b1[j+1];
                b1[j+1]=temp;
            }
        }
    }
}
void Display_All_Player(player* b1, int n)
{
   int i;
   cout<<"---------------------------------------------------------------------------------------------------------------\n";
   cout<<"jersey_Number \t | \t name \t                |runs \t                | wickets\t|match_played   |\n";
   cout<<"---------------------------------------------------------------------------------------------------------------\n";
   for (i = 0; i < n; i++)
   {
       cout <<" "<<b1[i].jersey_Number<<"\t\t |  "<<b1[i].name<<"\t \t        | "<< b1[i].runs<<"\t\t         | "<<b1[i].wicket<<"\t\t| "<<b1[i].match_played<<"\t\t|\n";
	}
   cout<<"---------------------------------------------------------------------------------------------------------------\n";
}

