#ifndef BLOCK_H
#define BLOCK_H

#include "header.h"

#define BLOCK_SIZE 4
#define BLOCK_NUMBER 7
#define BLOCK_TURN_NUMBER 4


/*
    @brief ブロックを定義する
*/
void define_Block();

/*
    @brief ブロックを回転させる
    @param[in] ブロックの配列
*/
void turn_Block(int **block);

/*
    @brief 出現するブロックを選択する
    @return 出現するブロックの配列
*/
int **select_Block();





int square[BLOCK_SIZE][BLOCK_SIZE] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
};

int line[BLOCK_SIZE][BLOCK_SIZE] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
};

int tBlock[BLOCK_SIZE][BLOCK_SIZE] = {
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
};

int lBlock[BLOCK_SIZE][BLOCK_SIZE] = {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0}
};

int jBlock[BLOCK_SIZE][BLOCK_SIZE] = {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
};

int sBlock[BLOCK_SIZE][BLOCK_SIZE] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
};

int zBlock[BLOCK_SIZE][BLOCK_SIZE] = {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
};




void define_Block()
{
    int **SQUARE = (int **)malloc(sizeof(int *) * BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i++){
        SQUARE[i] = (int *)malloc(sizeof(int) * BLOCK_SIZE);
    }
    for(int x = 0; x < BLOCK_SIZE; x++){
        for(int y = 0; y < BLOCK_SIZE; y++){
            SQUARE[x][y] = square[x][y];
        }
    }

    int **LINE = (int **)malloc(sizeof(int *) * BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i++){
        LINE[i] = (int *)malloc(sizeof(int) * BLOCK_SIZE);
    }
    for(int x = 0; x < BLOCK_SIZE; x++){
        for(int y = 0; y < BLOCK_SIZE; y++){
            LINE[x][y] = line[x][y];
        }
    }

    int **T_BLOCK = (int **)malloc(sizeof(int *) * BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i++){
        T_BLOCK[i] = (int *)malloc(sizeof(int) * BLOCK_SIZE);
    }
    for(int x = 0; x < BLOCK_SIZE; x++){
        for(int y = 0; y < BLOCK_SIZE; y++){
            T_BLOCK[x][y] = tBlock[x][y];
        }
    }

    int **L_BLOCK = (int **)malloc(sizeof(int *) * BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i++){
        L_BLOCK[i] = (int *)malloc(sizeof(int) * BLOCK_SIZE);
    }
    for(int x = 0; x < BLOCK_SIZE; x++){
        for(int y = 0; y < BLOCK_SIZE; y++){
            L_BLOCK[x][y] = lBlock[x][y];
        }
    }

    int **J_BLOCK = (int **)malloc(sizeof(int *) * BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i++){
        J_BLOCK[i] = (int *)malloc(sizeof(int) * BLOCK_SIZE);
    }
    for(int x = 0; x < BLOCK_SIZE; x++){
        for(int y = 0; y < BLOCK_SIZE; y++){
            J_BLOCK[x][y] = jBlock[x][y];
        }
    }

    int **S_BLOCK = (int **)malloc(sizeof(int *) * BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i++){
        S_BLOCK[i] = (int *)malloc(sizeof(int) * BLOCK_SIZE);
    }
    for(int x = 0; x < BLOCK_SIZE; x++){
        for(int y = 0; y < BLOCK_SIZE; y++){
            S_BLOCK[x][y] = sBlock[x][y];
        }
    }

    int **Z_BLOCK = (int **)malloc(sizeof(int *) * BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i++){
        Z_BLOCK[i] = (int *)malloc(sizeof(int) * BLOCK_SIZE);
    }
    for(int x = 0; x < BLOCK_SIZE; x++){
        for(int y = 0; y < BLOCK_SIZE; y++){
            Z_BLOCK[x][y] = zBlock[x][y];
        }
    }
}



void turn_Block(int **block)
{
    int tmp[BLOCK_SIZE][BLOCK_SIZE];
    for(int i = 0; i < BLOCK_SIZE; i++){
        for(int j = 0; j < BLOCK_SIZE; j++){
            tmp[i][j] = block[i][j];
        }
    }

    for(int i = 0; i < BLOCK_SIZE; i++){
        for(int j = 0; j < BLOCK_SIZE; j++){
            block[i][j] = tmp[BLOCK_SIZE - j - 1][i];
        }
    }
}

int **select_Block()
{
    int random = rand() % BLOCK_NUMBER;
    int turn = rand() % BLOCK_TURN_NUMBER;
    int **block = (int **)malloc(sizeof(int *) * BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i++){
        block[i] = (int *)malloc(sizeof(int) * BLOCK_SIZE);
    }

    switch(random){
        case 0:
            for(int x = 0; x < BLOCK_SIZE; x++){
                for(int y = 0; y < BLOCK_SIZE; y++){
                    block[x][y] = square[x][y];
                }
            }
            break;
        case 1:
            for(int x = 0; x < BLOCK_SIZE; x++){
                for(int y = 0; y < BLOCK_SIZE; y++){
                    block[x][y] = line[x][y];
                }
            }
            break;
        case 2:
            for(int x = 0; x < BLOCK_SIZE; x++){
                for(int y = 0; y < BLOCK_SIZE; y++){
                    block[x][y] = tBlock[x][y];
                }
            }
            break;
        case 3:
            for(int x = 0; x < BLOCK_SIZE; x++){
                for(int y = 0; y < BLOCK_SIZE; y++){
                    block[x][y] = lBlock[x][y];
                }
            }
            break;
        case 4:
            for(int x = 0; x < BLOCK_SIZE; x++){
                for(int y = 0; y < BLOCK_SIZE; y++){
                    block[x][y] = jBlock[x][y];
                }
            }
            break;
        case 5:
            for(int x = 0; x < BLOCK_SIZE; x++){
                for(int y = 0; y < BLOCK_SIZE; y++){
                    block[x][y] = sBlock[x][y];
                }
            }
            break;
        case 6:
            for(int x = 0; x < BLOCK_SIZE; x++){
                for(int y = 0; y < BLOCK_SIZE; y++){
                    block[x][y] = zBlock[x][y];
                }
            }
            break;
    }

    if(turn != 0){
        for(int i = 0; i < turn; i++){
            turn_Block(block);
        }
    }

    return block;
}


#endif // BLOCK_H
