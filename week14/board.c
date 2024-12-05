//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12
#define MAX_COIN        4
// ----- EX. 3 : board ------------
// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
// ----- EX. 5 : shark ------------
// ----- EX. 3 : board ------------
static int board_coin[N_BOARD];
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------


static int shark_position;

// ----- EX. 3 : board ------------
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

int board_initBoard(void)
{
    int i;
    
    //variable initialization
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }
    
// ----- EX. 5 : shark ------------
    //상어 이동 값 초기화 -> 초기값 = -4
    shark_position = SHARK_INITPOS;
// ----- EX. 5 : shark ------------

    //coin allocation
    //board_coin에 임의로 동전 할당
    //board_coin[20] -> 20개의 배열 중 코인을 랜덤으로 할당하는 건가? 근데 12칸만 할당하는 듯
   for(i=0;i<N_COINPOS;i++){
        int allocated = 0;
        while(!allocated){
            int k = rand() % N_BOARD;
            if(board_coin[k] == 0){
                //i번째 코인 할당
                board_coin[k] = rand() % MAX_COIN + 1;
                allocated = 1;
            }
        }
   }
    
    return N_COINPOS;
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
//상어 이동 함수
//마지막 player의 인덱스 돌고 -> 상어 이동
int board_stepShark(void)
{
    int shark_pos = rand()%MAX_SHARKSTEP + 1;
    shark_position += shark_pos;
    //shark가 지나간 경로의 board_status = 1로 변경
    for(int i=0;i<shark_position;i++){
        board_status[i] = 1;
    }
    return shark_position;
}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos)
{
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------
