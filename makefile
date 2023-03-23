COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 3
LASTNAME = Wilmarth
GITUSERID = dwilmar1
EXE = zll_sample

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
#FLAGS = -Wall -Wextra -O3
CC = g++
BIN = bin
OBJ = obj
ZFILES = zany.h ZLL.h ZLL.cpp

all: $(BIN)/$(EXE) 

# ------------------------------------------------------------------------
# Builds the .o for the isZany() functions for string and int
$(OBJ)/zany.o: zany.cpp
	$(CC) $(FLAGS) -c zany.cpp -o $@

# ------------------------------------------------------------------------
# Builds the .o for a crayon class
$(OBJ)/Crayon.o: Crayon.cpp
	$(CC) $(FLAGS) -c Crayon.cpp -o $@
	
# ------------------------------------------------------------------------
# zll
$(BIN)/$(EXE): $(OBJ)/zll_sample.o $(OBJ)/zany.o $(OBJ)/Crayon.o
	$(CC) $(FLAGS) $(OBJ)/zll_sample.o $(OBJ)/zany.o $(OBJ)/Crayon.o \
		-o $@ 

$(OBJ)/zll_sample.o: zll_sample.cpp $(ZFILES) 
	$(CC) $(FLAGS) -c zll_sample.cpp -o $@

# ------------------------------------------------------------------------
tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(TESTS) *.tar.gz
#	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(TESTS) *.tar.gz
