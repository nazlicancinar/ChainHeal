/**
* @author Yunus Şen yunus.sen3@ogr.sakarya.edu.tr
* @author Nazlıcan Çınar nazlican.cinar@ogr.sakarya.edu.tr
* @author Cansu Bıdıcı 
* @author Mısra Erilmez 
* @author Osman Kurt  
* @since 10.04.2020
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include "chain_heal.h"


#define BUFSIZE 1000

int main(int argc, char * argv [])
{


    FILE *f;
    f = stdin;
    int x, y, cur_PP, max_PP;
    char *name = malloc(sizeof(char) * 100);
	


   char str1[20], str2[20], str3[30] ;


   scanf("%s %d %d %d %d %lf %s %s",&str1, &initial_range, &jump_range, &num_jumps, &initial_power, &power_reduction,&str2,&str3);
	
    f = fopen(str3,"r");
    
    int dugum_sayaci = 0;


	while (fscanf(f, "%d %d %d %d %s", &x, &y, &cur_PP, &max_PP, name) != EOF)
	{
		
		

		temp = (struct node*) malloc(sizeof(struct node));
		temp->X = x;
		temp->Y = y;
		temp->cur_PP = cur_PP;
		temp->max_PP = max_PP;
		temp->name = malloc(sizeof(char) * 100);
		strcpy(temp->name, name);	

		if(dugum_sayaci <= 0) // Düğüm sayısı 0 ise henüz dizimizin hiç elemanı yok demektir. Okunan ve temp değişkeninde tutulan düğüm değerlerini, dizinin ilk elemanı olan fisrt isimli düğüme atarız. Bu kod dosyadan okunun ilk değerde çalışır.
		{
		        first = temp; // okunan ve temp değişeninde tutulan değerler first düğümüne atanır.
		        first->next = NULL; // Listenin sonunu belirtmek için first değişkeninin gösterdiği sonraki düğüm boş olucaktır.Çünkü henüz bir eleman var.
		        current = first; // bulunulan düğümü de değer atanır.
		}
		else
		{
			current->next = temp; 
		        current = temp;
		        current->next = NULL;
		}

		dugum_sayaci++;
	}
	
	
	fclose(f);

	current = first;

        int looper = 0;

       

    while(current)
	{
		
		current = current->next;
    }



	struct node *outer_current = (struct node*) malloc(sizeof(struct node));
    struct node *inner_current = (struct node*) malloc(sizeof(struct node));

    outer_current = first;


    while(outer_current)
	{
        int adj_counter = 0;
        inner_current = first;


        while(inner_current )
		{

			


			if( outer_current != inner_current)
			{
				if(sqrt(((outer_current->X - inner_current->X)*(outer_current->X - inner_current->X)) + ((outer_current->Y - inner_current->Y)*(outer_current->Y - inner_current->Y))) <= jump_range)
				{
                    adj_counter++;
				}
			}

                inner_current = inner_current->next;
        }

            outer_current->adj_size = adj_counter;
            outer_current = outer_current->next;
    }

    current = first;
    
    while(current)
	{
       
        current = current->next;
    }

    //putting the nodes onto adjacency list
    outer_current = first;

    while(outer_current)
	{
        outer_current->adj_list = (struct node**)malloc(sizeof(struct node*) * outer_current->adj_size);
        int index_counter = 0;
        inner_current = first;


        while(inner_current)
		{

                    if(outer_current == first){

                    }

                if( outer_current != inner_current){
                    if(sqrt(((outer_current->X - inner_current->X)*(outer_current->X - inner_current->X)) + ((outer_current->Y -
                    inner_current->Y)*(outer_current->Y - inner_current->Y))) <= jump_range){
                        outer_current->adj_list[index_counter++]=inner_current;
                    }
                }

                inner_current = inner_current->next;
            }
            outer_current = outer_current->next;
        }

	int listC = 0;
        current = first;
      
        while(current)
	{
          

          
                

            current = current->next;
        }


      

        //


        temp_path = (struct node**)malloc(sizeof(struct node*) * num_jumps);
        saglik_durumu =  (int**)malloc(sizeof(int*) * num_jumps);

        best_path = (struct node**)malloc(sizeof(struct node*) * num_jumps);
        iyilesme =   (int**)malloc(sizeof(int*)*num_jumps);

        control1 = (struct node*) malloc(sizeof(struct node));
        control2 = (struct node*) malloc(sizeof(struct node));

        best_iyilesme = 0;

        int counter;
        current = first;

        for(counter = 0; counter<dugum_sayaci; counter++){
                if(sqrt(((first->X - current->X)*(first->X - current->X)) +
                        ((first->Y - current->Y)*(first->Y - current->Y))) <= initial_range){
                           
                            dfs(current, 1, num_jumps,0, NULL,0);
                            current = current->next;

            }
        }

        int cX=0;
       
       
            
        
        printf("Toplam_Iyilesme: %d", best_iyilesme);


	int val;

	scanf("%d", val);


    
    return 0;



	
}
