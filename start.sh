#!/bin/bash
cp -T ./program/defines_tic_tac_toe_start.h ./program/defines_tic_tac_toe.h
make -C ./program clean  --silent
make -C ./program         --silent                                          
./program/run "$@"
while [ $? -eq 1 ]; do
	make -C ./program clean    --silent 
	make -C ./program   --silent
	./program/run "$@"
done

#use --silent to silence to output of make.
