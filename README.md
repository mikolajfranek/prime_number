# prime_number
Prime number

#### run eclipse
/home/ubuntu/eclipse/cpp-2019-12/eclipse/eclipse

#### install library gmp
1. "./configure --prefix=${gmp_build} --build= --enable-cxx --with-gnu-ld" => Apparently if you don't explicitly tell GMP to build for your platform it builds everything, which is bad. The cxx option builds the C++ libraries and --with-gnu-ld allows it to work with ld.
2. "make" 
3. "make check"
4. "sudo make install"

#### configure gmp in eclipse
1. Project => Properties => C/C++ Build => Environment => Add value "${gmp_build}/include;${gmp_build}/lib" to the PATH 
2. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC Assembler => General => Include paths => Add "${gmp_build}/include"
3. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Includes => Include paths => Add "${gmp_build}/include" 
4. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Miscellaneous => Other flags => Add "-lgmp -lgmpxx" (to the end of value)
5. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Includes => Include paths => Add "${gmp_build}/include" 
6. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Miscellaneous => Other flags => Add "-lgmp -lgmpxx" (to the end of value)
7. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries => Add "gmp"
8. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries => Add "gmpxx"
9. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries search path => Add "${gmp_build}/lib"

#### install library benchmark
1. "mkdir build && cd build"
2. "cmake -DCMAKE_INSTALL_PREFIX=${benchmark_build} -DCMAKE_BUILD_TYPE=Release ../" 
3. "make"
4. "make test"
5. "sudo make install"

#### configure benchmark in eclipse
1. Project => Properties => C/C++ Build => Environment => Add value "${benchmark_build}/include;${benchmark_build}/lib" to the PATH 
2. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC Assembler => General => Include paths => Add "${benchmark_build}/include"
3. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Includes => Include paths => Add "${benchmark_build}/include" 
4. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Includes => Include paths => Add "${benchmark_build}/include" 
5. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries => Add "benchmark"
6. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => Libraries => Libraries search path => Add "${benchmark_build}/lib"
7. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Linker => General => Select Support for pthread
8. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Miscellaneous => Select Support for pthread
9. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Miscellaneous => Select Support for pthread
10. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C++ Compiler => Miscellaneous => Other flags => Add "-lbenchmark"
11. Project => Properties => C/C++ Build => Settings => Tool Settings => GCC C Compiler => Miscellaneous => Other flags => Add "-lbenchmark"

#### running benchmark in eclipse
1. "sudo cpupower frequency-set --governor performance" => Disabling CPU Frequency Scaling
2. Run => Run Configurations... => Arguments => Add value "--benchmark_format=json" to Program arguments
3. "apt-get install gnulib"
