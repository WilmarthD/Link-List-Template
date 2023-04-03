# Link-List-Template
# - Steps to running the program
- Download all repository with all files and folders
- Run "make" or "make all" from the main directory (Not within bin or obj)
- Call executable from bin folder
  - This can be done by typeing either "./zll_sample" from inside the bin directory or "bin/./zll_sample" from the main directory

- # The main is located in zll_sample.cpp. To change the output and create your own ZLL instances, make changes there.

- # Crayon.h and Crayon.cpp are examples of a class to be instantiated with the template class, though you can create your own to insert as well.
- When createing your own class, you must either write over the code in Crayon, keeping the same file names, or adjust the makefile to include a new cpp file for compilation.
