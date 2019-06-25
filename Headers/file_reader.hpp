#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <fstream>
#include <cstddef>

class File_Reader {
public:
	File_Reader(const char*);
	~File_Reader();

	bool float_reading(float&);
	bool sizet_reading(std::size_t&);
	bool char_reading(char&);

private:
	const char* file_name;
	std::ifstream fin;
};

#endif
