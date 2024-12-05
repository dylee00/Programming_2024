//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER]; //플레이어 위치
char player_name[N_PLAYER][MAX_CHARNAME]; //플레이어 이름
int player_coin[N_PLAYER]; //플레이어 누적 동전 수
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end 플레이어 현재 상태
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"}; //플레이어 상태 설명 문자열
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;
    
    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
        {
            flag_end = 0;
            break;
        }
    }
    
    return flag_end;
}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE && board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}
// ----- EX. 5 : shark ------------

// ----- EX. 6 : game end ------------
int getAlivePlayer(void)
{
   int i;
   int cnt = 0;
   for(i=0;i<N_PLAYER;i++){
     if(player_status[i] == PLAYERSTATUS_END){
        cnt++;
     }
   }
   return cnt;
}

int getWinner(void)
{
    int i;
    int winner = 0;
    int max_coin = -1;
    
    for (i=0;i<N_PLAYER;i++)
    { 
        if(player_status[i] == PLAYERSTATUS_END || player_status[i] == PLAYERSTATUS_LIVE) {
            if(player_coin[i] > max_coin) {
                max_coin = player_coin[i];
                winner = i;
            }
        }
    }
    return winner;
}
// ----- EX. 6 : game end ------------


int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0;

// ----- EX. 1 : Preparation------------
    srand(time(NULL)); //main 함수 윗부분 초기화 함수
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    int pos = 0; //위치 변수 선언
    board_initBoard();
// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    //player 상태 초기화(입력 받기)
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;

// ----- EX. 4 : player ------------
    // 살아있는 player조회 후 다음 player 조회
    //turn -> player의 인덱스
        while (player_status[turn] != PLAYERSTATUS_LIVE) {
            turn = (turn + 1) % N_PLAYER;
        }
// ----- EX. 4 : player ------------
        
        //step 2-1. status printing
// ----- EX. 3 : board ------------
        board_printBoardStatus();

// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        //player의 상태 표시, 모든 Player의 상태
        printPlayerStatus();
// ----- EX. 4 : player ------------

        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum); //아무 Key나 누르면 주사위 돌림
        fflush(stdin);
// ----- EX. 4 : player ------------
        dieResult = rolldie(); //주사위 던짐 
        //step 2-3. moving
        //해당 turn에 해당하는 player의 칸 이동
        player_position[turn] += dieResult;
        pos = player_position[turn];
        printf("Die result: %d, %s moved to %d\n",dieResult,player_name[turn],pos);

        if (pos >= N_BOARD) 
        {
            player_status[turn] = PLAYERSTATUS_END;}
        
        //step 2-4. coin
        //해당 칸의 coin 결과 -> 주사위 굴린 후 몇칸인지 표시하고 해당 칸에 coin얼마나 있는지 확인
        coinResult = board_getBoardCoin(pos);
        if(coinResult != 0) {printf("\nLucky! %s got %d coins\n", player_name[turn],coinResult);}
        player_coin[turn] += coinResult;

        turn = (turn + 1) % N_PLAYER;


        //step 2-5. end process -> 상어 이동?
        if (turn == 0) {
            int shark_pos = board_stepShark();
            printf("Shark moved to %i\n", shark_pos);
            checkDie();
        }

// ----- EX. 6 : game end ------------
    } while(game_end() == 0);
    
    //step 3. game end process
    printf("GAME END!!\n");
    printf("%i players are alive! winner is %s\n", getAlivePlayer(), player_name[getWinner()]);
// ----- EX. 6 : game end ------------
    
// ----- EX. 2 : structuring ------------

    return 0;
}
