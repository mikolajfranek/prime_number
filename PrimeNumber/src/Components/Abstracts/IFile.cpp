#include "IFile.h"

namespace ComponentsAbstracts {

	IFile::IFile(string pathOfFile) {
		this->pathOfFile = pathOfFile;
	}

	IFile::~IFile() {}
}
