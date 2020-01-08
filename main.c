#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char playername[100];
    int price;
    int speed;
    int finishing;
    int exist;
    int defence;
} newplayer;
typedef struct
{
    char teamname[100];
    int money;
    int number;
    int loose;
    int win;
    int power;
    int draw;
    int list[100];
} newteam;

int main()
{
    newplayer p[100];
    newteam t[100];
    char com[100];
    int count = 0;
    int counter = 0;
    do
    {
        scanf("%[^\n]s",com);
        getchar();
        if(strncmp(com,"new player",sizeof("new player") - 1) == 0)
        {
            sscanf(com, "new player %s %d %d %d %d", p[count].playername,&p[count].price,&p[count].speed,&p[count].finishing,&p[count].defence);
            count++;
            p[counter].exist = 0;
        }
        if(strncmp(com,"new team",sizeof("new team") - 1) == 0)
        {
            sscanf(com,"new team %s %d",t[counter].teamname,&t[counter].money);
            t[counter].number = 0;
            counter++;
        }
        if(!strncmp(com,"buy", 3))
        {
            int id1,id2;
            sscanf(com,"buy %d %d", &id1, &id2);
            if(id1 > count)
            {
                printf("player with the id %d doesnt exist\n",id1);
            }
            else if(id2 > counter)
            {
                printf("team with the id %d doesnt exist\n",id2);
            }
            else if(t[id2].money < p[id1].price)
            {
                printf("the team cant afford to buy this player\n");
            }
            else if(p[id1].exist == 1)
            {
                printf("player already has a team\n");
            }
            else
            {
                t[counter].number++;
                //t[counter].list[number] = id1;
                p[counter].exist = 1;
                printf("player added to the team succesfully\n");
                t[id2].money = t[id2].money - p[id1].price;
            }
        }
        if(!strncmp(com,"sell",4))
        {
            int id1,id2;
            sscanf(com,"sell %d %d",&id1,&id2);
            if(id2 > count)
            {
                printf("team doesnt exist\n");
            }
            else if(p[id1].exist == 0)
            {
                printf("team doest have this player\n");
            }
            else
            {
                p[counter].exist = 0;
                printf("player sold succesfully\n");
            }
        }
        if(!strncmp(com, "match",5))
        {
            int id1,id2;
            sscanf(com,"match %d %d",&id1,&id2);
            if(id1 > counter || id2 > counter)
            {
                printf("team doesnt exist\n");
            }
            if(t[id1].number != 11 || t[id2].number != 11)
            {
                printf("the game can not be held due to loss of the players\n");
            }
            else
            {
                t[id1].power = 0;
                for(int i = 1; i <= 11; i++)
                {
                    t[id1].power += (p[count].speed + p[count].finishing);
                }
                for(int i = 1; i <= 11; i++)
                {
                    t[id2].power += (p[count].speed + p[count].defence);
                }
                if(t[id1].power > t[id2].power)
                {
                    t[id1].win++;
                    t[id2].loose++;
                }
                if(t[id2].power > t[id1].power)
                {
                    t[id2].win++;
                    t[id1].loose++;
                }
                if(t[id1].power = t[id2].power)
                {
                    t[id1].draw++;
                    t[id2].draw++;
                }
            }
        }
        if(!strncmp(com, "show players",sizeof("show players") - 1))
        {
            for(int i = 1; i <= count; i++)
            {
                printf("%d: %s",i,p[i].playername);
            }
        }
        if(!strncmp(com, "show teams",sizeof("show teams") - 1))
        {
            for(int j = 1; j <= counter; j++)
            {
                printf("%d: %s",j,t[j].teamname);
            }
        }
        if(!strncmp(com,"rank",4))
        {
            int rank[counter];
            for(int i = 1; i <= counter; i++)
            {
                t[counter].number = rank[i];
                //sorting the array
                for(int j = 1; j <= counter - 1; j++)
                {
                    for (int z = (j + 1); z < counter; z++)
                    {
                        if (rank[i] < rank[j])
                        {
                            int temp = rank[j];
                            rank[j] = rank[z];
                            rank[z] = temp;
                        }
                    }
                }
                for (i = 1; i <= counter; i++)
                {
                    printf("%d. %s \n",rank[i],t[i].teamname);
                }



                // finished
            }

        }

    }
    while(strcmp(com,"end") != 0);
    return 0;
}
