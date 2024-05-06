#include "../../../../../_old/PrimeNumber/src/Components/Files/FileWriter.h"

namespace ComponentsFiles {

	FileWriter::FileWriter(string pathOfFile) : ComponentsAbstracts::IFile(pathOfFile) {}

	FileWriter::~FileWriter() {}

	bool FileWriter::open()
	{
		this->file.open(this->pathOfFile.c_str(), ios::out | ios::app);
		return this->file.good();
	}

	void FileWriter::close()
	{
		this->file.close();
	}

	bool FileWriter::writeLine(string text)
	{
		if(this->file.is_open() == false)
		{
			this->open();
		}
		this->file << text << endl;
		return this->file.good();
	}
}
