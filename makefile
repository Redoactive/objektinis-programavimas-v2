
main:
	g++ -o program main.cpp funkcijosVektoriai.cpp bendrosFunkcijos.cpp funkcijosDekai.cpp funkcijosListai.cpp
opt:
	g++ -o optimised -O3 main.cpp funkcijosVektoriai.cpp bendrosFunkcijos.cpp funkcijosDekai.cpp funkcijosListai.cpp
optRun:
	optimised.exe
run:
	program.exe
clean:
	del *.o *.exe
deleteTxt:
	del *.txt
