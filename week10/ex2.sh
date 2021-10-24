mkdir week01
mkdir week10
cd week01
echo "Arseniy" > file.txt
cd ..
cd week10
link ../week01/file.txt _ex2.txt
cd ..
cd week01
find .. -inum $( ls -i file.txt | awk '{print $1}') > ex2.txt
find .. -inum $( ls -i file.txt | awk '{print $1}') -exec rm {} \; >> ex2.txt