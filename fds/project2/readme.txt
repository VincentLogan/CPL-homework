Compilation & Execution

1.Liunx:    cd the directory containing main.c
                gcc -o main main.c
                ./main test/test1.txt

2.Windows:  cd the directory containing main.c
                gcc -o main.exe main.c
                main.exe test\test1.txt

3.MacOS:    cd the directory containing main.c
                clang(/gcc) -o main main.c
                ./main test/test1.txt

The method to use generate.py to generate test sample

    cd the directory containing generate.py
    python3 generate.py <n1> <n2> [output_file_name]