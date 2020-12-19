#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void add_Matrix(float** floatArray);
void print_Matrix(float** floatArray, int nRow, int nColumn);
void addtion_Matrix_By_Matrix(float** floatArray, int nRow, int nColumn);
void addition_Constant(float** floatArray, int nRow, int nColumn);
void print_Matrix_ByValue(float** floatArray);
void write_to_binary(float** matrix, int a, int b);
void write_to_binary(float** matrix, int a, int b);
float** read_file(int nRow, int nColumn);
int main()
{
int nRow = 0, nColumn = 0, i = 0, nContinue = 0, nHold = 0;
printf("Enter the rows followed by the columns:\n");
fflush( stdout );
scanf("%d", &nRow);
scanf("%d", &nColumn);
float** floatArray = (float**)malloc(nRow * sizeof(float*));
for (i = 0; i < nRow; i++)
{
floatArray[i] = (float*)malloc(nColumn * sizeof(float));
for (int j = 0; j < nColumn; j++)
floatArray[i][j] = 0;
}
while (nContinue == 0)
{
printf("What command do you want to do?\n1. Modify Matrix\n2. Print Matrix\n3. Print Matrix By Row and Column\n4. Add Constant Value to Matrix\n5. Addition Matrix by Matrix\n6. Write to file\n7. Quit\n");
fflush( stdout );
scanf("%d", &nHold);
switch (nHold)
{
case 1:
add_Matrix(floatArray);
break;
case 2:
print_Matrix(floatArray, nRow, nColumn);
break;
case 3:
print_Matrix_ByValue(floatArray);
break;
case 4:
addition_Constant(floatArray, nRow, nColumn);
break;
case 5:
addtion_Matrix_By_Matrix(floatArray, nRow, nColumn);
break;
case 6:
write_to_file(floatArray, nRow, nColumn);
break;
case 7:
nContinue = 1;
free(floatArray);
break;
default:
printf("Enter Values between 1 to 7:\n");
fflush( stdout );
break;
}
printf("\n");
}
return 0;
}
void add_Matrix(float** floatArray)
{
int nRow = 0, nColumn = 0; float value = 0;
printf("Enter Row number:\n");
fflush( stdout );
scanf("%d", &nRow);
printf("Enter Column number:\n");
fflush( stdout );
scanf("%d", &nColumn);
printf("%s%d%s%d\n", "Enter value to add Array, Row = ", nRow, "and Column = ", nColumn);
fflush( stdout );
scanf("%f", &value);
floatArray[nRow][nColumn] = value;
}
void print_Matrix(float** floatArray, int nRow, int nColumn)
{
for (int i = 0; i < nRow; i++) {
for (int j = 0; j < nColumn; j++) {
printf("%f ", floatArray[i][j]);
}
printf("\n");
}
}
void print_Matrix_ByValue(float** floatArray)
{
int nRow = 0, nColumn = 0;
printf("Enter Row number to print:\n");
fflush( stdout );
scanf("%d", &nRow);
printf("Enter Column number to print:\n");
fflush( stdout );
scanf("%d", &nColumn);
printf("%s%d%s%d : ", "Value for the position , Row = ", nRow, "and Column = ", nColumn);
fflush( stdout );
printf("%f ", floatArray[nRow][nColumn]);
}
void addition_Constant(float** floatArray, int nRow, int nColumn)
{
float value = 0;
printf("Enter constant value to add to Matrix:\n");
scanf("%f", &value);
for (int i = 0; i < nRow; i++)
for (int j = 0; j < nColumn; j++)
floatArray[i][j] = floatArray[i][j] + value;
}
void addtion_Matrix_By_Matrix(float** floatArray, int nRow, int nColumn)
{
int i = 0, j = 0;
float value = 0;
printf("Enter constant value to create Matrix:\n");
scanf("%f", &value);
float** addArray = (float**)malloc(nRow * sizeof(float*));
for (i = 0; i < nRow; i++)
{
addArray[i] = (float*)malloc(nColumn * sizeof(float));
for (int j = 0; j < nColumn; j++)
addArray[i][j] = value;
}
for (i = 0; i < nRow; i++)
for (j = 0; j < nColumn; j++)
floatArray[i][j] = floatArray[i][j] + addArray[i][j];
}
void write_to_file(float** matrix, int a, int b)
{
FILE* fpointer;
fpointer = fopen("result.txt", "w");
for (int i = 0; i < a; i++)
{
for (int j = 0; j < b; j++)
{
fprintf(fpointer, "%f ", matrix[i][j]);
}
fprintf(fpointer, "\n");
}
fclose(fpointer);
}
void write_to_binary(float** matrix, int a, int b)
{
FILE* fpointer;
fpointer = fopen("result.bin", "wb");
for (int i = 0; i < a; i++)
{
for (int j = 0; j < b; j++)
{
fwrite(matrix, sizeof(float), a * b, fpointer);
}
}
fclose(fpointer);
}
float** read_file(int nRow, int nColumn)
{
	FILE* fpointer;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	fpointer = fopen("result.txt", "r");
	float** floatArray = (float**)malloc(nRow * sizeof(float*));
	for (int i = 0; i < nRow; i++)
	{
		floatArray[i] = (float*)malloc(nColumn * sizeof(float));
		for (int j = 0; j < nColumn; j++)
			floatArray[i][j] = 0;
	}
​
	while ((read = getline(&line, &len, fpointer)) != -1) {
		printf("Retrieved line of length %zu:\n", read);
		printf("%s", line);
​
		/* get the first token */
	   char *token = strtok(line, " ");
​
	   /* walk through other tokens */
	   while( token != NULL ) {
		  printf( " %s\n", token);
​
		  token = strtok(NULL, " ");
	   }
	}
​
	return floatArray;
