#include "../../Main.h"

#ifndef COMPONENTS_ABSTRACTS_IFILE_H_
#define COMPONENTS_ABSTRACTS_IFILE_H_

namespace ComponentsAbstracts {
	class IFile {
	protected:
		string pathOfFile;
	public:
		IFile(string pathOfFile);
		virtual ~IFile();
		virtual bool open() = 0;
		virtual void close() = 0;
	};
}

#endif
