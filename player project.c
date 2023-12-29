#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct player{       
	int jersey_Number;
	char name[20];
	int runs;
	int wicket;
	int match_played;
	
	
}player;


void store(player* b1);
void Display(player*,int);
void Add_Player(player*,int*);
int  Remove_Player(player* b1,int,int);
int Search_Player(player* b1,int,int);
void update(player *, int,int);
void maxruns(player*,int);
void maxwickets(player*,int);
void Display_All_Player(player*,int);


void main(){
	int size = 100 ;
	player b1[size];

	int exit;
	int i,t,ch1;
	int count;
	printf("Enter no of Players");
	scanf("%d",&count);

    store(b1);
	 do
	 {
	 	printf("************************Enter Your Choice***************************");
	 	printf("\n1.Display\n2.Add_Player\n3.Remove_Player\n4.Search_Player\n5.Update_data\n6.Display_Top_3_Players\n7.Display_All_Players\n");
	 	int choice;

	 	printf("\nEnter your choice: ");
	    scanf("\n%d",&choice);
	 	switch(choice)
	 	{
	 		case 1:
	 			{
	 				Display(b1,count);
				}
	 			break;
	 		case 2:
				{
					if(count<size){
						Add_Player(b1, &count);
						Display(b1, count);
					}
					else {
                    printf("Cannot add more players. Maximum limit reached.\n");
                	}
                }
                break;  
	 		case 3:
	 			{
	 				printf("\nEnter The jersey number for remove");
					int j_no;
					scanf("%d",&j_no);
			 		count =	Remove_Player(b1,j_no,count);
			 		
				 }
	 			             
	 			break;
	 		case 4:
	 			{
	 				int j_no;
					printf("\nEnter the Jersey Number to search a player: ");
	 				scanf("\n%d",&j_no);
	 				Search_Player(b1,count,j_no);
				 }
	 			break;
	 		case 5:
	 			{
	 				int jer_num;
	 		        printf("Enter players jersy number to update player : ");
         			scanf("%d", &jer_num);
         			update(b1, jer_num,count);
         		}
	 			break;
	 			case 6:
	 				    
	 				{	printf("Display Top 3: ");
						printf("\n1.Runs Scored \n2.Wickets\n");
						scanf("%d",&t);
						
						if(t==1){
						maxruns(b1,count);
	    				Display(b1,3);
						}
						else if(t==2){
						maxwickets(b1,count);
						Display(b1,3);
						}
					 }
	 				break;
	 			case 7:
	 				Display_All_Player(b1,count);
	 				break;
	 					
	 				default:
	 					printf("not found");
					 break;		
		 }
		 	printf("\nDo you want to continue(0/1)? \n");
	    	scanf("%d",&exit);	
	 }while(exit==1);
}

void store(player* b1){

	b1[0].jersey_Number=1;
	strcpy(b1[0].name,"virat");
	b1[0].runs=110;
	b1[0].wicket=15;
	b1[0].match_played=25;

	b1[1].jersey_Number=2;
	strcpy(b1[1].name,"dhoni");
	b1[1].runs=120;
	b1[1].wicket=20;
	b1[1].match_played=35;

	b1[2].jersey_Number=3;
	strcpy(b1[2].name,"Raina");
	b1[2].runs=130;
	b1[2].wicket=25;
	b1[2].match_played=45;
	
	b1[3].jersey_Number=4;
	strcpy(b1[3].name,"Rahul");
	b1[3].runs=140;
	b1[3].wicket=30;
	b1[3].match_played=55;
	
	b1[4].jersey_Number=5;
	strcpy(b1[4].name,"Dhawan");
	b1[4].runs=150;   
	b1[4].wicket=35;
	b1[4].match_played=65;
	
	b1[5].jersey_Number=6;
	strcpy(b1[5].name,"Sachin");
	b1[5].runs=160;  
	b1[5].wicket=40;
	b1[5].match_played=75;
	
	b1[6].jersey_Number = 7;
	strcpy(b1[6].name,"Ishant");
	b1[6].match_played =85;
	b1[6].runs = 170;
	b1[6].wicket = 45;
	
	b1[7].jersey_Number = 8;
	strcpy(b1[7].name,"Ashwin");
	b1[7].match_played =95;
	b1[7].runs = 180;
	b1[7].wicket = 50;
	
	b1[8].jersey_Number = 9;
	strcpy(b1[8].name,"Jadeja");
	b1[8].match_played =105;
	b1[8].runs = 190;
	b1[8].wicket = 55;
	
	b1[9].jersey_Number = 10;
	strcpy(b1[9].name,"Shami");
	b1[9].match_played =115;
	b1[9].runs = 200;
	b1[9].wicket = 60;
	
	b1[10].jersey_Number = 11;
	strcpy(b1[10].name,"Bumrah");
    b1[10].match_played =125;
	b1[10].runs = 210;
	b1[10].wicket=65;
}
void Display(player* b1,int n)
{
   int i;
   printf("---------------------------------------------------------------------------------------------------------------\n");
   printf("jersey_Number \t | \t name \t                |runs \t                | wickets\t|match_played   |\n");
   printf("---------------------------------------------------------------------------------------------------------------\n");
   for (i = 0; i < n; i++)
   {
      printf(" %d \t\t |  %s \t \t        | %d \t\t         | %d \t\t| %d\t\t|\n", b1[i].jersey_Number, b1[i].name, b1[i].runs, b1[i].wicket, b1[i].match_played);
   }
   printf("---------------------------------------------------------------------------------------------------------------\n");
}

void Add_Player(player* b1, int* count)
{
	int n ,i;
	printf("Enter no of players you want to add");
	scanf("%d",&n);

	for( i=0;i<n;i++){
	
		printf("Enter Jersey_No: ");
        scanf("%d", &b1[*count].jersey_Number);
        printf("Enter name: ");
        scanf("%s", &b1[*count].name);
        printf("Enter runs: ");
        scanf("%d", &b1[*count].runs);
        printf("Enter wickets: ");
        scanf("%d", &b1[*count].wicket);
        printf("Enter Matches Played: ");
        scanf("%d", &b1[*count].match_played); 
        *count = *count+1;
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
   		Display(b1,n);
   		return n;	
	}
		
   
}
int Search_Player(player* b1,int n,int j_no)
{
   int i;
   for (i = 0; i < n; i++)
   {
      if (b1[i].jersey_Number == j_no)
      {
        
         Display(&b1[i],1);
         return i;
      }
   }
    printf("No player found with jersey no %d", j_no);
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

         printf("Enter Runs : ");
         scanf("%d", &b1[i].runs);
         printf("Enter wickets : ");
         scanf("%d", &b1[i].wicket);
         printf("Enter no_of_matches: ");
         scanf("%d", &b1[i].match_played);

         printf("updated successfully \n");
         Display(&b1[i],1);
         //   printf("jersy_no \t | name \t | runs \t | wickets \t| no_of-matches \n");
         //   printf(" %d \t\t |  %s \t | %d \t\t | %d \t\t | %d \n",s[i].jersy_no,s[i].name,s[i].runs,s[i].wickets,s[i].no_of_matches);

         break;
      }
   }
   if (flag == 0)
      printf("No player found with jersy no %d\n", jer_num);
}
void maxruns(struct player* b1, int n){
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
void Display_All_Player(player* b1,int n)
{
   int i;
	printf("------------------------------------------------------------------------------------------------------------------\n");
	printf("jersey_no \t |  name \t                 |runs        \t                 | wickets\t| match_played  |\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++){
		printf(" %d \t\t |  %s \t \t        | %d \t\t         | %d \t\t| %d\t\t|\n", b1[i].jersey_Number, b1[i].name, b1[i].runs,b1[i].wicket,b1[i].match_played);
    }
}
