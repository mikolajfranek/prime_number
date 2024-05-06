# prime_number
Prime number

#### install library gmp
1. "./configure --prefix= --build= --enable-cxx --with-gnu-ld" 
2. "make" 
3. "make check"
4. "sudo make install"

#### install library mpfr
1. "./configure --prefix= --build= --with-gnu-ld"
2. "make" 
3. "make check"
4. "sudo make install"

#### install library benchmark
1. "tar -zxvf googletest-release-1.10.0.tar.gz -C benchmark-1.5.2"
2. "mv benchmark-1.5.2/googletest-release-1.10.0/ benchmark-1.5.2/googletest"
3. "cmake -DCMAKE_INSTALL_PREFIX= -DCMAKE_BUILD_TYPE=Release" 
4. "make"
5. "make test"
6. "sudo make install"

#### configure gmp/mpfr/benchmark in eclipse
1. Project => Properties => C/C++ Build => Environment => Add value "/include;/lib" to the PATH 
2. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC Assembler => General => Include paths => Add "/include"
3. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Includes => Include paths => Add "/include" 
4. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Miscellaneous => Other flags => Add "-lmpfr -lgmp -lbenchmark" (to the end of value)
5. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Miscellaneous => Support for pthread
6. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Includes => Include paths => Add "/include" 
7. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Miscellaneous => Other flags => Add "-lmpfr -lgmp -lbenchmark" (to the end of value)
8. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Miscellaneous => Support for pthread
9. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries => Add "gmp", "mpfr", "benchmark"
10. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries search path => Add "/lib"
11. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => General => Select Support for pthread

#### running benchmark in eclipse
1. Run => Run Configurations... => Arguments => Program arguments => Add "--benchmark_format=json"
