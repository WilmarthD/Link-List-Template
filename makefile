COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 3
LASTNAME = Wilmarth
GITUSERID = WilmarthD
EXE = main

#REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
#BIN = bin
#OBJ = obj

# all: $(BIN)/$(EXE)

# $(BIN)/$(EXE): $(OBJ)/scheduler.o $(OBJ)/StudentList.o $(OBJ)/CourseList.o $(OBJ)/Student.o $(OBJ)/Course.o
# 	$(CC) $(FLAGS) $(OBJ)/scheduler.o $(OBJ)/StudentList.o $(OBJ)/CourseList.o $(OBJ)/Student.o $(OBJ)/Course.o -o $@

# $(OBJ)/scheduler.o: scheduler.cpp CourseList.h StudentList.h
# 	$(CC) $(FLAGS) -c scheduler.cpp -o $@

# $(OBJ)/StudentList.o: StudentList.cpp Student.h
# 	$(CC) $(FLAGS) -c StudentList.cpp -o $@

# $(OBJ)/CourseList.o: CourseList.cpp Course.h
# 	$(CC) $(FLAGS) -c CourseList.cpp -o $@

# $(OBJ)/Student.o: Student.cpp Course.h
# 	$(CC) $(FLAGS) -c Student.cpp -o $@
	
# $(OBJ)/Course.o: Course.cpp Student.h
# 	$(CC) $(FLAGS) -c Course.cpp -o $@

all: main 

main: main.cpp
	g++ main.cpp -g -o main

#main: main.o
#	g++ main.o -g -o main

#main.o: main.cpp
#	g++ -c main.cpp

#ZLL.o: ZLL.cpp
#	g++ -c ZLL.cpp

#onefile: main.cpp
#	g++ main.cpp -g -o main

tar:	clean
	tar cvvf $(TARFILE)
	gzip $(TARFILE)

clean:
	rm -f *.o $(EXE) *.tar.gz