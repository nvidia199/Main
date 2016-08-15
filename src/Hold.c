/*
 * Hold.c
 *
 *  Created on: Aug 1, 2016
 *      Author: asma
 */

#include"Hold.h"


struct Hold init_hold(){
	struct Hold hold;
	int b = pick_random_block();
//	printf("rand %d \n", i);
	init_block(b);
//	printf("%d\n", i);
	set_hold_matrix(&hold, b);
	return hold;
};

int pick_random_block(){
	int i = rand()% NUMB_SHAPES;
	return i;
}

void set_hold_matrix(struct Hold *hold,int x){
	int height;
		int width;
		for(height = 0; height < MATRIX_HEIGHT; height++){
			for(width = 0; width < MATRIX_WIDTH; width++){
				hold->hold_matrix[width][height] = blocks[x][width][height];
				hold->hold_block.rotation_matrix[width][height] = blocks[x][width][height];
				/* zowel de hold matrix als de matrix van de block initialiseren
				 * via de hold aan de block geraken.
				 */
			}
		}
};


struct Block *load_from_hold(struct Hold *hold, struct Block *block){
	block->colour = hold->hold_block.colour;
	block->shape = hold->hold_block.shape;
	determine_start_pos(block);
	int i;
			int j;
			for(i = 0; i < MATRIX_HEIGHT; i++){
				for(j = 0; j < MATRIX_WIDTH; j++){
					block->rotation_matrix[i][j] = hold->hold_block.rotation_matrix[i][j];
				}
			}

	return block;
};

void print_hold(struct Hold *x){
	int i;
	int j;
	for(i = 0; i < MATRIX_HEIGHT; i++){
		for(j = 0; j < MATRIX_WIDTH; j++){
			int c = x->hold_matrix[i][j];
			printf("%d", c);
		}
		printf("\n");
	}
};
