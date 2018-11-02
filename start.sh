#!/bin/bash      
make -C ./program                                                               
./program/run "$@"
while [ $? -eq 1 ]; do
	make -C ./program
	./program/run "$@"
done
