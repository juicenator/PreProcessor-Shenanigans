#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defines_tic_tac_toe.h"
#include "toggle.h"

const char *def_file_name = "./program/defines_tic_tac_toe.h";

void make_move(){
	
	int input;
	
	while(1){
		printf("Make a move (1-9): ");
		input = getchar();
		printf("\n");
		#ifdef TURN_X
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
	
	toggle_definition(def_file_name, "TURN_X");
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
		printf(" |");
	#endif
	
	#ifdef TWO_X
		printf("X|");
	#elif defined(TWO_O)
		printf("O|");
	#else
		printf(" |");
	#endif
		
	#ifdef THREE_X
		printf("X");
	#elif defined(THREE_O)
		printf("O");
	#else
		printf(" ");
	#endif	
		
	printf("\n");
	
	#ifdef FOUR_X
		printf("X|");
	#elif defined(FOUR_O)
		printf("O|");
	#else
		printf(" |");
	#endif
	
	#ifdef FIVE_X
		printf("X|");
	#elif defined(FIVE_O)
		printf("O|");
	#else
		printf(" |");
	#endif
		
	#ifdef SIX_X
		printf("X");
	#elif defined(SIX_O)
		printf("O");
	#else
		printf(" ");
	#endif	
	
	printf("\n");
	
	#ifdef SEVEN_X
		printf("X|");
	#elif defined(SEVEN_O)
		printf("O|");
	#else
		printf(" |");
	#endif
	
	#ifdef EIGHT_X
		printf("X|");
	#elif defined(EIGHT_O)
		printf("O|");
	#else
		printf(" |");
	#endif
		
	#ifdef NINE_X
		printf("X");
	#elif defined(NINE_O)
		printf("O");
	#else
		printf(" ");
	#endif	
	
	printf("\n");
}

int tic_tac_toe(){
	draw_board();
	make_move();
	return 0;
}



int main(){	
	//Open the file
	
	printf("Running!\n");
	
	tic_tac_toe();
	
	#ifndef ONE
		
		printf("Exit!\n");
		exit(0); //Exit 0: Stops the "compile loop"
		
	#endif

	
	exit(1); //Exit 1: Recompiles and runs.
}
