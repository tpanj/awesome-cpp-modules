# Intro to awesome-cpp-modules

Have you come from different language background or you are tired to spending time
implementing function declarations (in header files) besides function definitions?
There is better way of spending time in coding in c++ - you can use modules now.

With each new version and [standard of the C++](https://isocpp.org/tour) language
 and [CMake](https://cmake.org/), one of the more interesting things
 like modules becomes more accessible and easier to use.

This project hold a minimal working cross platform hello world module example
tested by three most commonly used c++ compilers.
 
## Detailed explanation

Why is this so interesting?
Key benefits of modules include:

- Improved Compilation Speed: Traditional C++ includes header files, which often lead to redundant and repetitive parsing during the compilation process. Modules provide a more efficient way of organizing and using code, leading to faster compilation times since the module interface is only parsed once and stored separately. Because modules eliminate the need for multiple header files and are only imported once this significantly improve compile times and complexity of your code. Especially for large projects
- Easier dependency management: Modules can be used to express the logical dependencies between your code, which can make it easier to manage dependencies and avoid conflicts.
- Support for named exports: Modules allow you to explicitly specify which names should be exported from a module, which can help to improve the readability and maintainability of your code.
- Improved error reporting: Modules can help to improve error reporting by providing more context about the location of errors.
- Better support for the C++ Standard Library: The C++ Standard Library is now available as modules, which can make it easier to use and understand.
- Better Encapsulation: Modules allow you to control which parts of your code are exposed externally and which parts remain private to the module. This improves encapsulation and information hiding, leading to more maintainable and secure code.
- Easier Code Maintenance: Modules can make codebases easier to maintain and understand. By grouping related code together and specifying dependencies explicitly, it becomes clearer which parts of the code rely on others.
- Avoiding Header File Cyclic Dependencies: Traditional header file inclusion can lead to cyclic dependencies, making it difficult to compile the code. Modules offer a solution to this problem by providing a better way of handling dependencies between different parts of the code.
- Forward Declarations Not Required: In the traditional header-based approach, forward declarations are often used to avoid cyclic dependencies. With modules, this becomes less of a concern as the module system itself resolves the dependencies.

# System preparation

This CMakeLists checks most of system requirement versions to use modules.
All dependencies are also on the list
- cmake >= 3.27.1 on posix systems or 3.26 otherwise
  - g++ >= 13 (with "Unix Makefiles" or Ninja generators) or
  - clang 17 (with clang-tidy and ninja-build >= 1.11 ) or
  - gcc Visual Studio 22
 
## Following instructions for Ninja at https://ninja-build.org

    wget https://github.com/ninja-build/ninja/releases/download/v1.11.1/ninja-linux.zip
    unzip ninja-linux.zip
    sudo cp ninja /usr/local/bin/

## Build latest cmake example

    sudo apt install build-essential libssl-dev # ubuntu build dependencies
    wget https://github.com/Kitware/CMake/releases/download/v3.27.1/cmake-3.27.1.zip
    unzip cmake*.zip
    cd cmake-3.27.1
    ./configure
    make
    sudo make install

## For Clang by following instructions at https://apt.llvm.org

    wget https://apt.llvm.org/llvm.sh && chmod +x llvm.sh
    sudo ./llvm.sh 17
    apt install clang-tidy-17
    cd /usr/bin/
    sudo ln -s clang-tidy-17 clang-tidy

# Installation

Clone repository and build

    git clone https://github.com/tpanj/awesome-cpp-modules.git
    cd awesome-cpp-modules
    mkdir build
    cd build
    cmake ..

Explicit defining `clang` compiler and `ninja` generator

    CXX=clang-17 cmake -G Ninja ..

Make executable

    cmake --build .
    
You can now run hello executable.

# Troubles solving

## MSVS

- [ ] Solve IntelliSense support for 17.7.3 +

## CLang

- [ ] Warning: it is deprecated to read module 'speech:X' implicitly; it is going to be removed in clang 18; consider to specify the dependencies explicitly [-Wread-modules-implicitly]
