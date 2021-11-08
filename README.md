## Algoritmi 1

### Hash
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Hash](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233)
#### EX 1 HASH TABLE con Concatenazione separata
```make
make clean test
./test/test_hashtable_sepchain

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_sepchain
```
#### EX 2 HASH TABLE con LINEAR PROBING
```make
make clean test
./test/test_hashtable_linprob

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_linprob
```
#### EX 3 Esercizi Extra
```make
make clean test
./test/test_hashtable_sepchain_more

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_sepchain_more

./test/test_hashtable_linprob_more

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_linprob_more
```
#### File
[Open hashtable.c](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c)
