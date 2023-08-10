g++ ./P3834maker.cpp -o maker -O2 -lm -std=c++14
g++ ./P3834.cpp -o test -O2 -lm -std=c++14
g++ ./P3834tj.cpp -o std -O2 -lm -std=c++14

for i in {1..100000};
do
./maker > ttm.in
./std < ttm.in > ttm.ans
./test < ttm.in > ttm.out
if diff ttm.out ttm.ans
then
echo "Testcase$i Accepted"
else
echo "Testcase$i Unaccepted"
exit 0
fi
done