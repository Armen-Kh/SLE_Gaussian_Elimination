#include "matrix.hpp"
#include "file_reader.hpp"
#include "file_writer.hpp"
#include "utility.hpp"
#include "gaussian_elimination.hpp"

#include <iostream>
#include <cstddef>   //size_t
#include <string>

int main()
{
	File_Reader FR_AB("../Data/AB.txt");
	File_Writer FW_X("../Data/X.txt");
	Matrix A, B, X;

	while(Read_SLE(FR_AB, A, B)) {
		for(int i =0; i < A.get_rows(); ++i) {
			for(int j =0; j < A.get_columns(); ++j){
				std::cout << A(i, j) << ", ";
			}
			std::cout << "\n";
		}
                for(int i =0; i < B.get_rows(); ++i) {
                        for(int j =0; j < B.get_columns(); ++j){
                                std::cout << B(i, j) << ", ";
                        }
                        std::cout << "\n";
                }

		std::string conclusion;
		//X = Matrix(1, A.get_columns());
		Gaussian_Elimination(A, B, X, conclusion);
		
		for(std::size_t i = 0; i < X.get_size(); ++i) {
			std::cout << X(i) << ", " ;
		}
		Write_SLE_Solution(FW_X, X, conclusion);
	}
	
	/*
	Matrix A(5, 3);
	A(0, 0) = 5; A(0, 1) = 2; A(0, 2) = 0;
	A(1, 0) = 2; A(1, 1) = 1; A(1, 2) = -1;
	A(2, 0) = 2; A(2, 1) = 3; A(2, 2) = -1;
	A(3, 0) = 5; A(3, 1) = 2; A(3, 2) = 10;
	A(4, 0) = 10; A(4, 1) = 2; A(4, 2) = 10;

	Matrix B(5);
	B(0) = 2; B(1) = 0; B(2) = 3; B(3) = 13; B(4) = 12;

	Matrix X(3);

	std::string conclusion = "=?=";

	Gaussian_Elimination(A, B, X, conclusion);
	*/

	return 0;
}
