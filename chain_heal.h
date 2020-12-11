#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>

struct node
{
	

	int X, Y;
	int cur_PP, max_PP;
 	char *name;

	struct node *next;

	int adj_size;
	struct node **adj_list;

	int iyilesme;
	int controlled;

}Node;

int initial_range, jump_range, num_jumps, initial_power = 0;
double power_reduction;

struct node *first;
struct node *current;
struct node *temp;

int best_iyilesme;
struct node **best_path;
int **iyilesme;

struct node **temp_path;
int **saglik_durumu;

struct node *control1;
struct node *control2;

void dfs(struct node* node, int hop, int num_jumpsL, int toplam_iyilesme, struct node* from,int dizi_sayaci)
{

     int gereken_iyilesme;
     int reset_init_power = initial_power;

     if(node->controlled == 1 || hop>num_jumpsL)
	 {
        node->controlled = 0;
        return;
     }
     
	 int count;

        
     temp_path[dizi_sayaci] = node;


    if(dizi_sayaci == num_jumpsL-1)
	{
        int loop_C;
        
		for(loop_C = 0; loop_C<num_jumpsL;loop_C++)
		{

           
            
			gereken_iyilesme = temp_path[loop_C]->max_PP - temp_path[loop_C]->cur_PP;
            if(gereken_iyilesme<initial_power)
			{
				temp_path[loop_C]->iyilesme = gereken_iyilesme;
			}
            else
			{
                temp_path[loop_C]->iyilesme = rint(initial_power);
			}

            initial_power = initial_power * (1-power_reduction);

            //total iyilesme
            toplam_iyilesme = toplam_iyilesme + temp_path[loop_C]->iyilesme;

            //recording the iyilesme
            saglik_durumu[loop_C] = (int*)temp_path[loop_C]->iyilesme;
			 printf("%s %d \n", temp_path[loop_C]->name,saglik_durumu[loop_C]);
           
          
        }
                        
		//checking duplicate and rejecting the path
        
		int dupC;
        int dupC2;
                        
		for(dupC=0; dupC<num_jumpsL-1;dupC++)
		{
            for(dupC2=dupC+1;dupC2<num_jumpsL;dupC2++)
			{
                control1 = temp_path[dupC];
                control2 = temp_path[dupC2];
                                    
				//printf("\n\nTemp Path: %s\n",temp_path[dupC]->name);
                
				if(control1 == control2)
				{
					toplam_iyilesme = 0;
				}
            }

        }



        initial_power = reset_init_power;

        int x;
        
		if(toplam_iyilesme>best_iyilesme)
		{
            best_iyilesme = toplam_iyilesme;
			
            for(x=0;x<num_jumpsL;x++)
			{
                best_path[x]=temp_path[x];     
                iyilesme[x]=saglik_durumu[x];
            }
        }
    }


    for(count = 0; count<node->adj_size; count++)
	{
        node->controlled = 1;

        dfs(node->adj_list[count], hop+1, num_jumpsL,toplam_iyilesme,node->next,dizi_sayaci+1);
    }


}