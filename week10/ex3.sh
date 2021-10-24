echo "Arseniy Rubtsov" > _ex3.txt
chmod a-x _ex3.txt > ex3.txt
chmod u=rwx,o=rwx _ex3.txt >> ex3.txt
chmod g=u _ex3.txt >> ex3.txt
echo "1) user=rw- group=rw- other=---" >> ex3.txt
echo "2) user=rwx group=rwx other=r-x" >> ex3.txt
echo "3) user=rwx group=rwx other=rwx" >> ex3.txt

