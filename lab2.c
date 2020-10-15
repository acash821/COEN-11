#include <stdio.h>
#include <string.h>

char name[3][20];
char symptom[3][20];
int counter = 0;
int size;

int main()
{
    char command = 'a';
    counter = 0;
    while(command != 'q')
    {
        printf("Enter the command: a for adding, l for print, n for next");
        scanf("%c", &command);
        switch(command)
        {
            case 'a':
                if (counter <3)
                {
                    printf("Enter your name:");
                    char temp[20];
                    char temp_1[20];
                    scanf("%s", temp);
                    printf("Enter your symptom:");
                    scanf("%s", temp_1);
                    if(strlen(temp) < 19 && strlen(temp_1) < 19)
                    {
                        insert(temp, temp_1);
                    }
                    if(strlen(temp) > 19 || strlen(temp_1) > 19)
                    {
                        printf("Error, too long of a name");
                    }
                }
                else
                {
                        printf("List is already full");
                }
                    printf("\n");
                break;
            case 'l':
                if(counter > 0)
                {
                print();
                }
                else
                {
                        printf("Error empty list");
                }
                break;
            case 'n':
                if(counter > 0)
                {
                    next();
                }
                else if(counter == 0)
                {
                    printf("Error, 0 elements in list");
                }
                break;
        }
    }
}

void insert(char nam[], char symp[])
{
int tru = 0;
        if(counter > 0)
        {
                int a = 0;;
                while(a < counter && tru != 1)
                {
                if(strcmp(nam,name[a])==0)
                {
                        tru = 1;
                }
                        a++;
                }
        }
if(tru != 1)
{
    printf("%s", nam);
    printf("%s", symp);
    printf("%d", strlen(nam));
    printf("%d", counter);
    int i = 0;
    while(i < strlen(nam))
    {
        name[counter][i] = nam[i];
        i++;
    }
    i = 0;
    while(i < strlen(symp))
    {
        symptom[counter][i] = symp[i];
        i++;
    }
    counter++;
}
else{
        printf("Error due to same name");
}
}
void print()
{
    int i = 0;
    while(i<counter)
    {
        printf("%s", name[i]);
        printf("\t");
        printf("%s", symptom[i]);
        printf("\n");
        i++;
    }
}

void next()
{
    printf("%s", name[0]);
    printf("\t");
    printf("%s", symptom[0]);
    int i = 0;
    while(i < 9)
    {
        strcpy(name[i], name[i+1]);
        strcpy(symptom[i], symptom[i+1]);
        i++;
    }
    counter--;
}