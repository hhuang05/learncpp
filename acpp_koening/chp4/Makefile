all: main

median: median.cpp median.h
	clang++ -c -o median.o median.cpp

grade: grade.cpp grade.h
	clang++ -c -o grade.o grade.cpp

stuinfo: Student_info.cpp Student_info.h
	clang++ -c -o Student_info.o Student_info.cpp

main:
	clang++ -o a.out example4-1.cpp median.o grade.o Student_info.o
