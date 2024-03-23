main:
	g++ -o program main.cpp funkcijosVektoriai.cpp bendrosFunkcijos.cpp funkcijosDekai.cpp funkcijosListai.cpp
optCreate:
	g++ -o3 main.cpp funkcijosVektoriai.cpp bendrosFunkcijos.cpp funkcijosDekai.cpp funkcijosListai.cpp
optRun:
	3.exe
run:
	program.exe
clean:
	del *.o program.exe
deleteTxt:
	del *.txt