#include "file_reader.hpp"
#include "file_writer.hpp"
#include "matrix.hpp"

#include <iostream>
#include <cstddef>
#include <cassert>

bool Read_Matrix_Size (File_Reader& fr, Matrix& M) 
{
       	char c;
	std::size_t row, col;
        if(fr.char_reading(c) && fr.char_reading(c) &&
           fr.sizet_reading(row) && fr.char_reading(c) &&
           fr.sizet_reading(col) && fr.char_reading(c)) {
		M = Matrix(row, col);
		return true;
        }
        else {
                return false;
        }
}

bool Read_Matrix_Data(File_Reader& fr, Matrix& M) 
{
	char c;
	for(std::size_t i = 0; i < M.get_rows(); ++i) {
                for(std::size_t j = 0; j < M.get_columns(); ++j) {
                        if(!(fr.float_reading(M(i, j)) && fr.char_reading(c))) {
                                return false;
                        }
                }
        }
	return true;
}

bool Read_SLE(File_Reader& fr, Matrix& A, Matrix& B)
{
	char c;
	std::size_t number;

	if(!(fr.char_reading(c) && fr.sizet_reading(number))) {
		return false;
	}
	

	if(Read_Matrix_Size(fr, A) && Read_Matrix_Data(fr, A) ){
                for(int i =0; i < A.get_rows(); ++i) {
                        for(int j =0; j < A.get_columns(); ++j){
                                std::cout << A(i, j) << ", ";
                        }
                        std::cout << "\n";
                }
	}
	else {	return false;}


	if(Read_Matrix_Size(fr, B) && Read_Matrix_Data(fr, B)) {
                for(int i =0; i < B.get_rows(); ++i) {
                        for(int j =0; j < B.get_columns(); ++j){
                                std::cout << B(i, j) << ", ";
                        }
                        std::cout << "\n";
                }

               // B.set_size(B.get_columns());
               assert(A.get_rows() == B.get_size() && "Size mismatch!");
               
        }
        else { return false; }

	return true;
}


bool Write_SLE_Solution(File_Writer& fw,const Matrix& X, std::string& info)
{
	if(!(fw.char_writing('#') && fw.sizet_writing(X.get_number()) && fw.char_writing('\n'))) {
		return false;
	}

	if(!(fw.string_writing(info) && fw.char_writing('\n'))) {
		return false;
	}

	if(!(fw.string_writing("X(") && fw.float_writing(X.get_rows()) &&
	   fw.char_writing('x') && fw.float_writing(X.get_columns()) &&
	   fw.string_writing(")\n"))) {
                return false;
        }

	for(std::size_t i = 0; i < X.get_size(); ++i) { 
		if(!(fw.float_writing(X(i)) && fw.string_writing(", "))) {
			return false;
		}
	}
       
	if(!fw.char_writing('\n')) {
                return false;
        }

	return true;
}





