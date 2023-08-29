#include <stdio.h>
#include <string.h>
#define ROW 2
#define COL 2
#define GROUP 2
#define BLOCK 5
#define yMax 21
#define xMax 21
#define CHARMX 25

void BlnkLn(int);
void Divider(int);
void Grid(void);
void print2DMtrx(int Matrix[ROW][COL]);
void scan2DMtrx(char fileName[CHARMX], int _2dMtrx[ROW][COL]);
void scanPointCords(char fileName[CHARMX], int pointCords[2]);

int main()
{
    char Mtrx2D_F[CHARMX] = "Matrix Input.txt";
    char PointCords_F[CHARMX] = "PointCoordinates.txt";
    int Mtrx2D[ROW][COL] = {};
    int pointCords[5] = {};

    scanPointCords(PointCords_F, pointCords);

    return (0);
}

void BlnkLn(int lines)
{
    for(int i = 0; i < lines; i++)
        printf("\n\n");
}

void Divider(int length)
{
    for(int i = 0; i < length; i++)
        printf("=");
        printf("\n");
}

void Grid(void)
{
    int rise = 0, run = 0;
    char point = '+', xAxis = '-', yAxis = '|';

    for(int rise = 0; rise < xMax; rise++)
    {
        if(rise != 10)
        {
                for(int run = 0; run < yMax; run++)
                {
                    if(run != 10)
                        printf("%3c", point);
                    else
                        printf("%3c", yAxis);
                }
        }
        else
        {
            for(int run = 0; run < yMax; run++)
                printf("%3c", xAxis);
        }
        printf("\n");
    }

}

void print2DMtrx(int Matrix[ROW][COL])
{
    for(int row = 0; row < ROW; row++)
    {
        for(int col = 0; col < COL; col++)
        {
            printf("%5d", Matrix[row][col]);
        }
        printf("\n");
    }
}

void scan2DMtrx(char fileName[CHARMX], int _2dMtrx[ROW][COL])
{
    FILE *input = fopen(fileName, "r");

    for(int row = 0; row < ROW; row++)
    {
        for(int col = 0; col < COL; col++)
        {
            fscanf(input, "%d", &_2dMtrx[row][col]);
        }
    }
    fclose(input);
}

void scanPointCords(char fileName[CHARMX], int pointCords[2])
{   //char *fgets(char *str, int n, FILE *stream)      strcpy(destination[],strtok(readlocation[],deliminator ""));
    FILE *input = fopen(fileName, "r");
    char line[10];

    char indecies[4];
    char Coordinates[3];
    while(!feof(input))
    {
        fgets(line, 8, input);
	strcpy(indecies,strtok(line,","));
 
    }
    printf("%s\n%s\n", line, indecies);

    fclose(input);
}
