main:
	g++ -o program main.cpp funkcijosVektoriai.cpp bendrosFunkcijos.cpp funkcijosDekai.cpp funkcijosListai.cpp
run:
	program.exe
clean:
	del *.o program.exe
deleteTxt:
	del *.txt