#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char gender[10][10] = {{'m','a','l','e'},{'f','e','m','a','l','e'}};
char symptom[10][10] = {{'c','o','u','g','h'}, {'s','n','e','e','z','e'}, {'s','t','o','m','a','c','h'}, {'t','h','r','o','a','t'},
{'b','r','e','a','t','h'}, {'v','o','m','i','t',}, {'f','e','v','e','r'}, {'p','a','i','n'}, {'b','l','o','o','d'}, {'s','p','i','t'}};
int *gender_queue;
int *symptom_queue;
double gender_waitlist[2] = {0.0,0.0};
double symptom_wailist[10] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
int gender_count[2] = {0,0};
int symptom_count[10] = {0,0,0,0,0,0,0,0,0,0};
int turn_away;
int counter = 0;
int MAX_SIZE;
double perc;
int main(int argc, char *argv[])
{
    if(argc < 2)
        {
        return 1;
        }
    MAX_SIZE = atoi(argv[1]);
        perc = atof(argv[2]);
    srand((int)time(NULL));
    gender_queue = (int*) malloc(MAX_SIZE * sizeof(int));
    symptom_queue = (int*) malloc(MAX_SIZE * sizeof(int));
    int a = 0;
    turn_away = 0;
    int i = 0;
    int temp = (int) (perc * 100);
    while(i < 10000)                                                                                                    
    {
           experiment(MAX_SIZE, temp);
            i++;
    }
    printf("Max : ");
    printf("%d", MAX_SIZE);
    printf("\tPercent : ");
    printf("%f", perc);
    printf("\tTurnaway: ");
    printf("%d", turn_away);
    printf("\n");
    free(gender_queue);
    free(symptom_queue);
}
void experiment(int one, int two)
{
    int hold = MAX_SIZE * 2;
    int a = rand() % hold;
    if(a > one)
    {
        if(counter < 3)
        {
            int g_pos = rand() % 2;
            int s_pos = rand() % 10;
            add(g_pos,s_pos);
        }
        else
        {
            turn_away++;
        }
    }
    else
    {
        next(two);
    }
}
void add(pos_1, pos_2)
{
    *(gender_queue + counter) = pos_1;
    *(symptom_queue + counter) = pos_2;
    counter++;
}
void next(int three)
{
    int idk = rand() % 100;
    double wait_time = (double)(rand() % 30);
    gender_count[*gender_queue]++;
    symptom_count[*symptom_queue]++;
    gender_waitlist[*gender_queue] += wait_time;
    symptom_wailist[*symptom_queue] += wait_time;
    int gc_temp = 0;
    int sc_temp = 0;
    if(idk > perc)
    {
        gc_temp = *gender_queue;
        sc_temp = *symptom_queue;
    }
    int a = 0;
    while(a < 9)
    {
        *(gender_queue + a) = *(gender_queue + a + 1);
        *(symptom_queue + a) = *(symptom_queue + a + 1);
        a++;
    }
    if(idk > perc)
    {
        *(gender_queue + 2) = gc_temp;
        *(symptom_queue + 2) = sc_temp;
        counter++;
    }
    counter--;
}