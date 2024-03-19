main:
	g++ -o program .\main.cpp .\funkcijosVektoriai.cpp
run:
	program.exe
clean:
	del *.o program.exe
deleteTxt:
	del *.txt