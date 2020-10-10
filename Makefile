sudoku : SudokuAlgorithm.o sudoku.o
	g++ -o $@ $^

sudoku.o : sudoku.cpp SudokuAlgorithm.h
	g++ -c $<
	
	
SudokuAlgorithm.o : SudokuAlgorithm.cpp  SudokuAlgorithm.h 
	g++ -c $<
	
clean:
	rm *.o