#!/bin/bash
make -C ./program clean --silent      
make -C ./program --silent                                                        
./program/run "$@"
while [ $? -eq 1 ]; do
	sleep 1s
	make -C ./program clean --silent
	make -C ./program --silent
	./program/run "$@"
done

#use --silent to silence to output of make.
