#include <stdio.h>
#include <string.h>                                                                                                     
#include <math.h>

char gender[10][10] = {{'m','a','l','e'},{'f','e','m','a','l','e'}};                                                    
char symptom[10][10] = {{'c','o','u','g','h'}, {'s','n','e','e','z','e'}, {'s','t','o','m','a','c','h'}, {'t','h','r','o','a','t'},
{'b','r','e','a','t','h'}, {'v','o','m','i','t',}, {'f','e','v','e','r'}, {'p','a','i','n'}, {'b','l','o','o','d'}, {'s','p','i','t'}};
int gender_code[10];
int symptom_code[10];                                                                                                   
double gender_waitlist[2] = {0.0,0.0};
double symptom_wailist[10] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};                                                 
int gender_count[2] = {0,0};
int symptom_count[10] = {0,0,0,0,0,0,0,0,0,0};
int turn_away = 0;                                                                                                      
int counter = 0;
int main()
{
    srand((int)time(NULL));
    int i = 0;
    while(i < 10000)                                                                                                        {                                                                                                                           experiment();
        i++;
    }
    printf("Turned Away: ");
    printf("%d", turn_away);
    printf("\nTables:\n");
    printf("Genders\tNumber\tAverage Waittime\n");
    int a = 0;
    while(a < 2)
    {
        printf("%s", gender[a]);
        printf("\t");
        printf("%d", gender_count[a]);                                                                                          printf("\t");
        double hold = (double) (gender_waitlist[a] / gender_count[a]);
        printf("%f", hold);
        printf("\n");
        a++;
    }
    printf("Symptoms\tNumber\tAverage Waittime\n");
    a = 0;
    while(a < 2)
    {
        printf("%s", gender[a]);
        printf("\t");
        printf("%d", gender_count[a]);                                                                                          printf("\t");
        double hold = (double) (gender_waitlist[a] / gender_count[a]);
        printf("%f", hold);
        printf("\n");
        a++;
    }
    printf("Symptoms\tNumber\tAverage Waittime\n");
    a = 0;
    while(a < 10)
    {
        printf("%s", symptom[a]);
        printf("\t\t");
        printf("%d", symptom_count[a]);
        printf("\t");
        double hold = (double) (symptom_wailist[a] / symptom_count[a]);
        printf("%f", hold);
        printf("\n");
        a++;
    }
}
void experiment()
{
    int a = rand() % 100;
    if(a > 50)
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
        next();
    }
}
void add(pos_1, pos_2)
{
    gender_code[counter] = pos_1;
    symptom_code[counter] = pos_2;
    counter++;
}
void next()
{
    int idk = rand() % 100;
    double wait_time = (double)(rand() % 30);
    gender_count[gender_code[0]]++;
    symptom_count[symptom_code[0]]++;
    gender_waitlist[gender_code[0]] += wait_time;
    symptom_wailist[symptom_code[0]] += wait_time;
    int gc_temp = 0;
    int sc_temp = 0;
    if(idk > 85)
    {
        gc_temp = gender_code[0];
        sc_temp = symptom_code[0];
    }
    int a = 0;
    while(a < 9)
    {
        gender_code[a] = gender_code[a+1];
        symptom_code[a] = symptom_code[a+1];
        a++;
    }
    if(idk > 85)
    {
        gender_code[2] = gc_temp;
        symptom_code[2] = sc_temp;
        counter++;
    }
        counter--;
}  