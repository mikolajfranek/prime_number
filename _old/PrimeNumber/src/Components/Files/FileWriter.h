#include "../../../../../_old/PrimeNumber/src/Main.h"

#ifndef COMPONENTS_FILES_FILEWRITER_H_
#define COMPONENTS_FILES_FILEWRITER_H_

namespace ComponentsFiles {
	class FileWriter : public ComponentsAbstracts::IFile {
	private:
		ofstream file;
	public:
		FileWriter(string pathOfFile);
		virtual ~FileWriter();
		bool open();
		void close();
		bool writeLine(string text);
	};
}

#endif
