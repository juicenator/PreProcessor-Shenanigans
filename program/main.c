#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defines_tic_tac_toe.h"
#include "toggle.h"

const char *def_file_name = "./program/defines_tic_tac_toe.h";


//returns 0 when the game is over.
int check_if_done(){

	//Hor
	#if defined(ONE_X) && defined(TWO_X) && defined(THREE_X) 
		printf("X wins\n");
		return 0;
	#elif defined(ONE_O) && defined(TWO_O) && defined(THREE_O) 
		printf("O wins\n");
		return 0;
	#elif defined(FOUR_X) && defined(FIVE_X) && defined(SIX_X)
		printf("X wins\n");
		return 0;
	#elif defined(FOUR_O) && defined(FIVE_O) && defined(SIX_O) 
		printf("O wins\n");
		return 0;
	#elif defined(ZEVEN_X) && defined(EIGHT_X) && defined(NINE_X)
		printf("X wins\n");
		return 0;
	#elif defined(ZEVEN_O) && defined(EIGHT_O) && defined(NINE_O)
		printf("O wins\n");
		return 0; 
		
	//Vert
	#elif defined(ONE_O) && defined(FOUR_O) && defined(SEVEN_O)
		printf("O wins\n");
		return 0; 
	#elif defined(ONE_X) && defined(FOUR_X) && defined(SEVEN_X)
		printf("X wins\n");
		return 0;
	#elif defined(TWO_O) && defined(FIVE_O) && defined(EIGHT_O)
		printf("O wins\n");
		return 0;
	#elif defined(TWO_X) && defined(FIVE_X) && defined(EIGHT_X)
		printf("X wins\n");
		return 0;
	#elif defined(THREE_O) && defined(SIX_O) && defined(NINE_O)
		printf("O wins\n");
		return 0; 
	#elif defined(THREE_X) && defined(SIX_X) && defined(NINE_X)
		printf("X wins\n");
		return 0; 
		
	//Cross
	#elif defined(ONE_X) && defined(FIVE_X) && defined(NINE_X)
		printf("X wins\n");
		return 0; 
	#elif defined(ONE_O) && defined(FIVE_O) && defined(NINE_O)
		printf("O wins\n");
		return 0; 
	#elif defined(THREE_X) && defined(FIVE_X) && defined(SEVEN_X)
		printf("X wins\n");
		return 0; 
	#elif defined(THREE_O) && defined(FIVE_O) && defined(SEVEN_O)
		printf("O wins\n");
		return 0; 
	#endif
	
	//Draw
	#if (defined(ONE_X) || defined(ONE_O)) && (defined(TWO_X) || defined(TWO_O)) && (defined(THREE_X) || defined(THREE_O)) && (defined(FOUR_X) || defined(FOUR_O)) && (defined(FIVE_X) || defined(FIVE_O)) && (defined(SIX_X) || defined(SIX_O)) && (defined(SEVEN_X) || defined(SEVEN_O)) && (defined(EIGHT_X) || defined(EIGHT_O)) && (defined(NINE_X) || defined(NINE_O))
		printf("Draw\n");
		return 0;
	#endif
	
	return 1;
}


void make_move(){
	int input;
	while(1){
		printf("Make a move (1-9): ");
		input = getchar();
		printf("\n");
		#ifndef TURN_O
		if(input == '1'){
			#if !defined(ONE_X) && !defined(ONE_O) 
			toggle_definition(def_file_name, "ONE_X");
			break;
			#endif
		}else if(input == '2'){
			#if !defined(TWO_X) && !defined(TWO_O) 
			toggle_definition(def_file_name, "TWO_X");
			break;
			#endif
		}else if(input == '3'){
			#if !defined(THREE_X) && !defined(THREE_O) 
			toggle_definition(def_file_name, "THREE_X");
			break;
			#endif
		}else if(input == '4'){
			#if !defined(FOUR_X) && !defined(FOUR_O) 
			toggle_definition(def_file_name, "FOUR_X");
			break;
			#endif
		}else if(input == '5'){
			#if !defined(FIVE_X) && !defined(FIVE_O) 
			toggle_definition(def_file_name, "FIVE_X");
			break;
			#endif
		}else if(input == '6'){
			#if !defined(SIX_X) && !defined(SIX_O) 
			toggle_definition(def_file_name, "SIX_X");
			break;
			#endif
		}else if(input == '7'){
			#if !defined(SEVEN_X) && !defined(SEVEN_O) 
			toggle_definition(def_file_name, "SEVEN_X");
			break;
			#endif
		}else if(input == '8'){
			#if !defined(EIGHT_X) && !defined(EIGHT_O) 
			toggle_definition(def_file_name, "EIGHT_X");
			break;
			#endif
		}else if(input == '9'){
			#if !defined(NINE_X) && !defined(NINE_O) 
			toggle_definition(def_file_name, "NINE_X");
			break;
			#endif
		}else{
			printf("Not a valid input\n");
		}
		#else
		if(input == '1'){
			#if !defined(ONE_X) && !defined(ONE_O) 
			toggle_definition(def_file_name, "ONE_O");
			break;
			#endif
		}else if(input == '2'){
			#if !defined(TWO_X) && !defined(TWO_O) 
			toggle_definition(def_file_name, "TWO_O");
			break;
			#endif
		}else if(input == '3'){
			#if !defined(THREE_X) && !defined(THREE_O) 
			toggle_definition(def_file_name, "THREE_O");
			break;
			#endif
		}else if(input == '4'){
			#if !defined(FOUR_X) && !defined(FOUR_O) 
			toggle_definition(def_file_name, "FOUR_O");
			break;
			#endif
		}else if(input == '5'){
			#if !defined(FIVE_X) && !defined(FIVE_O) 
			toggle_definition(def_file_name, "FIVE_O");
			break;
			#endif
		}else if(input == '6'){
			#if !defined(SIX_X) && !defined(SIX_O) 
			toggle_definition(def_file_name, "SIX_O");
			break;
			#endif
		}else if(input == '7'){
			#if !defined(SEVEN_X) && !defined(SEVEN_O) 
			toggle_definition(def_file_name, "SEVEN_O");
			break;
			#endif
		}else if(input == '8'){
			#if !defined(EIGHT_X) && !defined(EIGHT_O) 
			toggle_definition(def_file_name, "EIGHT_O");
			break;
			#endif
		}else if(input == '9'){
			#if !defined(NINE_X) && !defined(NINE_O) 
			toggle_definition(def_file_name, "NINE_O");
			break;
			#endif
		}else{
			printf("Not a valid input\n");
		}
		#endif
	}
	
	toggle_definition(def_file_name, "TURN_O");
}


void draw_board(){
	/*
	1|2|3
	4|5|6
	7|8|9
	*/
	
	
	#ifdef ONE_X
		printf("X|");
	#elif defined(ONE_O)
		printf("O|");
	#else
		printf("1|");
	#endif
	
	#ifdef TWO_X
		printf("X|");
	#elif defined(TWO_O)
		printf("O|");
	#else
		printf("2|");
	#endif
		
	#ifdef THREE_X
		printf("X");
	#elif defined(THREE_O)
		printf("O");
	#else
		printf("3");
	#endif	
		
	printf("\n");
	
	#ifdef FOUR_X
		printf("X|");
	#elif defined(FOUR_O)
		printf("O|");
	#else
		printf("4|");
	#endif
	
	#ifdef FIVE_X
		printf("X|");
	#elif defined(FIVE_O)
		printf("O|");
	#else
		printf("5|");
	#endif
		
	#ifdef SIX_X
		printf("X");
	#elif defined(SIX_O)
		printf("O");
	#else
		printf("6");
	#endif	
	
	printf("\n");
	
	#ifdef SEVEN_X
		printf("X|");
	#elif defined(SEVEN_O)
		printf("O|");
	#else
		printf("7|");
	#endif
	
	#ifdef EIGHT_X
		printf("X|");
	#elif defined(EIGHT_O)
		printf("O|");
	#else
		printf("8|");
	#endif
		
	#ifdef NINE_X
		printf("X");
	#elif defined(NINE_O)
		printf("O");
	#else
		printf("9");
	#endif	
	
	printf("\n");
}

int tic_tac_toe(){
	draw_board();
	
	if(check_if_done() == 0){
		return 0;
	}
	
	make_move();
	return 1;
}



int main(){	
	//Open the file
	
	if(tic_tac_toe() == 0){
		exit(0);
	}

	exit(1); //Exit 1: Recompiles and runs.
}
