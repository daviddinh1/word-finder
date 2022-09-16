#Compile the code
# if the file HW1 exits then remove it
if [ -f HW1 ]; then
    rm HW1
fi
g++ HW1.cpp -o HW1
# if the file HW1 does not exit then exit the test
if [ ! -f HW1 ]; then
    echo   "\033[1;91mCompile FAILED.\033[0m"
    exit
fi