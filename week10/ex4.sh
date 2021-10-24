mkdir tmp
cd tmp
touch file1
touch file2
link file1 link1
cd ..
gcc ex4.c -o ex4.out
echo "File - Hard Links" > ex4.txt
./ex4.out >> ex4.txt
rm ex4.out
cd tmp
rm file1 link1 file2
cd ..
rmdir tmp
