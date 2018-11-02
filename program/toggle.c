#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64

int size_of_string(char * string, const int max_size);
int find_definition(FILE *fp, const char * find_string);

//Returns 0 on success. Error handling sucks though.
int toggle_definition(FILE * fp, const char * definition){ 
	char buffer_char;
	char *buffer_text;
	int length_file;
	int defined = 1;
	int start_of_line = -1;
	int counter = 0;
	
	//Find the definition
	if(find_definition(fp, definition) != 0){
		fprintf(stderr, "Couldn't find a definition, defines.h might be broken!\n");
		return -1;
	}
	
	//Check if it is already defined.
	if(fgetc(fp) == '/'){
		defined = 0;
	}
	
	//Start of the line
	fseek(fp, -1, SEEK_CUR);
	start_of_line = (int) ftell(fp);
	
	//Check the size of the file.
	fseek (fp, 0, SEEK_END);
	length_file = ftell (fp);
	fseek (fp, 0, SEEK_SET);
	
	//Set the length_file to the length AFTER our little edit.
	if(defined == 1){
		length_file = length_file+2;
	}else{
		length_file = length_file-2;
	}
	
	buffer_text = malloc (length_file);
	if(!buffer_text){
		fprintf(stderr, "Could not create a buffer for the text\n");
		return -1;
	}
	
	const char slash = '/';
	
	//Write the file to a buffer and add/remove the slashes.
	rewind(fp);
	if(defined == 0){ //Remove slashes
		fread(buffer_text, 1, start_of_line, fp);
		fseek(fp, 2, SEEK_CUR);
		fread(buffer_text+start_of_line, 1, length_file-(start_of_line), fp);
	}else{ //Add slashes
		fread(buffer_text, 1, start_of_line, fp);	
		memcpy(buffer_text + start_of_line, &slash, sizeof(slash));
		memcpy(buffer_text + start_of_line + 1, &slash, sizeof(slash));
		fread(buffer_text+start_of_line+2, 1, length_file-(start_of_line-2), fp);
	}

	//Write it to our defines.h.
	fclose(fp);
	fp = fopen("./program/defines.h", "w");
	fwrite(buffer_text, 1, length_file, fp);
	fclose(fp);
	fp = fopen("./program/defines.h", "r+");
	
	free(buffer_text);
	
	return 0;
}

//Helper function for toggle_definition(...). Returns the size of a char * till the first \0.
int size_of_string(char * string, const int max_size){
	int pos = 0;
	while(pos < max_size){
		if(string[pos] == '\0'){
			return pos;
		}
		pos++;
	}
	return -1;
}

//Helper function for toggle_definition(...). Find the place of find_string. Returns 0 on success.
//fp will be at the start of the line of this definition.
int find_definition(FILE *fp, const char * find_string){
	int length;
	char def_1[BUFFER_SIZE], def_2[BUFFER_SIZE];
	while(fscanf(fp, "%s %s", def_1, def_2) > 0){
		if(strcmp(def_2, find_string) == 0){
			length = size_of_string(def_1, BUFFER_SIZE) + size_of_string(def_2, BUFFER_SIZE) + 1;
			fseek(fp, -length, SEEK_CUR);
			return 0;
		}
	}
	return -1;
}
