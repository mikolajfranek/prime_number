# prime_number
Prime number

#### run eclipse
"sudo nice -n -20 /home/ubuntu/eclipse/cpp-2019-12/eclipse/eclipse"

#### install library gmp
1. "./configure --prefix= --build= --enable-cxx --with-gnu-ld" 
2. "make" 
3. "make check"
4. "sudo make install"

#### install library mpfr
1. "./configure --prefix= --build= --enable-cxx --with-gnu-ld"
2. "make" 
3. "make check"
4. "sudo make install"

#### install library benchmark
1. "mkdir build && cd build"
2. "cmake -DCMAKE_INSTALL_PREFIX= -DCMAKE_BUILD_TYPE=Release ../" 
3. "make"
4. "make test"
5. "sudo make install"

#### configure gmp/mpfr/benchmark in eclipse
1. Project => Properties => C/C++ Build => Environment => Add value "/include;/lib" to the PATH 
2. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC Assembler => General => Include paths => Add "/include"
3. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Includes => Include paths => Add "/include" 
4. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Miscellaneous => Other flags => Add "-lmpfr -lgmp -lbenchmark" (to the end of value)
5. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Includes => Include paths => Add "/include" 
6. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Miscellaneous => Other flags => Add "-lmpfr -lgmp -lbenchmark" (to the end of value)
7. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries => Add "gmp", "mpfr", "benchmark"
8. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries search path => Add "/lib"
9. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Miscellaneous => Select Support for pthread
10. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Miscellaneous => Select Support for pthread
11. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => General => Select Support for pthread

#### running benchmark in eclipse
1. "sudo cpupower frequency-set --governor performance" => Disabling CPU Frequency Scaling
2. Run => Run Configurations... => Arguments => Add value "--benchmark_format=json" to Program arguments
