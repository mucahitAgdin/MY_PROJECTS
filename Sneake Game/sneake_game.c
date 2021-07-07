#include <stdio.h>
#include <conio.h>//for kbhit() function (kbhit() fonksiyonu için)
#include <time.h>//for srand() funtion (srand() fonksiyonu için)
#include <stdlib.h>
#include <Windows.h>

//--------------------------function pre-declarations---------------------------
void draw(); 
void direction();
void game();
void moving();
//--------------------------function pre-declarations---------------------------

//-------------------------------global variables-------------------------------
int areaX=50, areaY=25, snakeX, snakeY, forageX, forageY, snakemove, gameOver, score, tryAgain=0;
int tailX[100], tailY[100];
int piece=0;
char answer;
//areaX and areaY are coordinates of area. (areaX ve areaY areanın koordinatları.)
//snakeX and snakeY are coordinates of snake. (sneakeX ve sneakeY yılanın koordinatları.)
//forageX and forageY are coordinates of forage. (forageX ve forageY yemlerin koordinatları.)
//-------------------------------global variables-------------------------------

int main()
{  
    label0:
    game();
    
    while(gameOver!=1)
    {
        direction();
        draw();
        moving();
    }

    if(gameOver==1)
    {
        system("cls");
        int i, j;
        for(i=0; i<=(areaY/2);i++)
        {
            for(j=0; j<=(areaX/2);j++)
            {
                printf(" ");
            }
            printf("\n");
        }
        printf("                    GAME OVER\n\n");
        printf("                  Your score: %d\n\n", score);
        if(tryAgain!=1)
        {
            printf("             Watch ads and go on?(Y/N)");
            scanf("%c", &answer);
        }
        else
        {   
            _sleep(1000);
            exit(0);
        }
    
        switch(answer)
        {
            case 89:
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n            M O N A   R O Z A\n\n");
                printf("               G A M I N G");
                _sleep(500);
                system("cls");
                _sleep(250);    
                printf("\n\n\n\n\n\n\n\n\n\n\n\n            M O N A   R O Z A\n\n");
                printf("               G A M I N G");
                _sleep(500);
                system("cls");
                _sleep(250);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n            M O N A   R O Z A\n\n");
                printf("               G A M I N G");
                _sleep(500);
                system("cls");
                _sleep(250);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n            M O N A   R O Z A\n\n");
                printf("               G A M I N G");
                _sleep(500);
                tryAgain++;
                goto label0;
                break;
            }
            

            case 121:
            {   
                
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n            M O N A   R O Z A\n\n");
                printf("               G A M I N G");
                _sleep(500);
                system("cls");
                _sleep(250);    
                printf("\n\n\n\n\n\n\n\n\n\n\n\n            M O N A   R O Z A\n\n");
                printf("               G A M I N G");
                _sleep(500);
                system("cls");
                _sleep(250);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n            M O N A   R O Z A\n\n");
                printf("               G A M I N G");
                _sleep(500);
                system("cls");
                _sleep(250);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n            M O N A   R O Z A\n\n");
                printf("               G A M I N G");
                _sleep(500);
                tryAgain++;
                goto label0;
                break;
            }

            case 78:
            {
                exit(0);
                break;
            }

            case 110:
            {
                exit(0);
                break;
            }
        }
    }

    getchar();
    return 0;
}

void draw()
{
    system("cls");

    int i, j, k, l,m, ch;
    //i and j are horizonal(yatay) coordinates (i ve j yatay koordinatlar)
    //k and l are vertical(dikey) coordinates (k ve l dikey koordinatlar)
    char horizonal_mark=124;
    
    for(i=0; i<=areaX; i++)
    {   
        if(i==0 || i==areaY)
        {
            for(j=0; j<=areaX; j++)
            {
                printf("-");
                if(j==areaX)
                {
                    printf("\n");
                }
            }
        }

        if(i==0)
        {
            for(k=1; k<areaY; k++)
            {
                printf("%c", horizonal_mark);//left wall drawn (sol duvar çizildi)
                for(l=1; l<areaX; l++)
                {   
                    if(k==snakeY && l==snakeX)
                    {
                        printf("0");
                    }
                    else if(k==forageY && l==forageX)
                    {
                        printf("+");
                    }
                    else
                    {
                        ch=0;
                        for(m=0; m<piece; m++)
                        {
                            if(l==tailX[m] && k==tailY[m])
                            {
                                printf("o");
                                ch=1;
                            }
                        }
                        if(ch==0)
                        {
                            printf(" ");
                        }
                    }
                }
                printf("%c", horizonal_mark);//right wall drawn (sağ duvar çizildi)
                printf("\n");
                
            }
        }
    }
    printf("Your score is \t: %d", score);
}

void direction()
{   
    if(kbhit())
    {
        switch(getch())
        {
            case 72 : //72 is ASCII code of up arrow key (72 yukarı yön tuşunun ASCII kodu)
                snakemove=1;
                break;

            case 80 : //80 is ASCII code of down arrow key (80 aşağı yön tuşunun ASCII kodu)
                snakemove=2;
                break; 

            case 75: //75 is ASCII code of left arrow key (75 sol yön tuşunun ASCII kodu)
                snakemove=3;
                break;

            case 77: //77 is ASCII code of right arrow key (77 sağ yön tuşunun ASCII kodu)
                snakemove=4;
                break;
            
            default:
            break;
        }
    }

}

void game()
{
    srand(time(NULL));

    snakeX = (areaX/2);
    snakeY = (areaY/2);

    label1:
    forageX= rand()%areaX;
    if(forageX==0)
        goto label1;

    label2:
    forageY= rand()%areaY;
    if(forageY==0)
        goto label2;
    
    gameOver=0; 
    piece++;

}

void moving()
{
    int i;
    int prevX, prevY, prev2X, prev2Y;
    
    prevX=tailX[0];
    prevY=tailY[0];
    tailX[0]=snakeX;
    tailY[0]=snakeY;
    
    for(i=1; i<=piece; i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;

    }
    switch (snakemove)
    {
        case 1:
        {   
            snakeY--;
            break;
        }
    
        case 2:
        {   
            snakeY++;
            break;
        }
        
        case 3:
        {   
            snakeX--;
            break;
        }

        case 4:
        {   
            snakeX++;
            break;
        }

    }
    
    if(snakeX==-1 || snakeX==(areaX+1) || snakeY==0 || snakeY==(areaY))
    {
        gameOver=1;
    }

    if(snakeX==forageX && snakeY==forageY)
    {
        srand(time(NULL));

        label3:
        forageX= rand()%areaX;
        if(forageX==0)
        goto label3;

        label4:
        forageY= rand()%areaY;
        if(forageY==0)
        goto label4;
        score+=10;
        piece++;
    }
}
