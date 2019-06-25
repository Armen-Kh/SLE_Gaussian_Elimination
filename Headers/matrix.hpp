#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>    //size_t

class Matrix {

public:
	Matrix();
	Matrix(std::size_t i, std::size_t j = 0);

	//Matrix(Matrix&&);
	//Matrix& operator=(Matrix&&);

	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);

	~Matrix();

	void Swap_Rows(std::size_t, std::size_t);

	float& operator()(std::size_t, std::size_t);
	const float& operator()(std::size_t, std::size_t) const;
	
	float& operator()(std::size_t);
	const float& operator()(std::size_t) const;

	std::size_t get_rows() const;
	std::size_t get_columns() const;
	std::size_t get_size() const;
	std::size_t get_number() const;

	void set_rows(std::size_t);
	void set_columns(std::size_t);
	void set_size(std::size_t);
	void set_number(std::size_t);

private:
	std::size_t rows;
	std::size_t columns;
	std::size_t size;
	std::size_t number;
	float ** data;
};

#endif
