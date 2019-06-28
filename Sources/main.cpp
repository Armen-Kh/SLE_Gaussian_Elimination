#include "sle_matrix.hpp"
#include "file_reader.hpp"
#include "file_writer.hpp"
#include "utility.hpp"
#include "gaussian_elimination.hpp"

#include <iostream>

int main()
{
	File_Reader FR_AB("../Data/SLE.txt");
	File_Writer FW_X("../Data/SLE_Solutions.txt");
	Matrix A, B, X;

	while(Read_SLE(FR_AB, A, B)) {
		std::string conclusion;

		float epsilon = 0.00001;          //for the behavioral deviations of float number..

		Gaussian_Elimination(A, B, X, conclusion, epsilon);
		Write_SLE_Solution(FW_X, X, conclusion);
	}
	std::cout << "The result is presented in \"SLE_Solutions.txt\" file (Data folder)!\n"; 
	
	return 0;
}
