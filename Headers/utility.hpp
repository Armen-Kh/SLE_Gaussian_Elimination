#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "matrix.hpp"
#include "file_reader.hpp"
#include "file_writer.hpp"

#include <string>

bool Read_Matrix_Size (File_Reader&, Matrix&);

bool Read_Matrix_Data(File_Reader&, Matrix&);

bool Read_SLE(File_Reader&, Matrix&, Matrix&);

bool Write_SLE_Solution(File_Writer&, const Matrix&, std::string&);

#endif

