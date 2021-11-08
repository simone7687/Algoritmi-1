## Algoritmi 1

### Hash
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Hash](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233)
#### EX 1 HASH TABLE con Concatenazione separata
- [Create](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L38)
- [Destroy](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L85)
- [Clear](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L95)
- [Put](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L131)
- [Insert](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L167)
- [Get](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L212)
- [Contains](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L229)
- [Delete](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L246)
- [Size](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L276)
- [Empty](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L283)
- [Capacity](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L288)
- [Load factor](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L293)
- [Get comparator](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L298)
- [Get hasher](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L303)

```make
make clean test
./test/test_hashtable_sepchain

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_sepchain
```
#### EX 2 HASH TABLE con LINEAR PROBING
- [Create](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L320)
- [Destroy](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L369)
- [Clear](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L379)
- [Put](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L408)
- [Insert](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L451)
- [Get](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L501)
- [Contains](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L517)
- [Delete](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L537)
- [Size](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L563)
- [Empty](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L571)
- [Capacity](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L576)
- [Load factor](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L581)
- [upo_ht_linprob_resize](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L586)

```make
make clean test
./test/test_hashtable_linprob

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_linprob
```
#### EX 3 Esercizi Extra
- [upo_ht_sepchain_keys](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L652)
- [upo_ht_sepchain_traverse](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L682)
- [upo_ht_linprob_keys](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L695)
- [upo_ht_linprob_traverse](/Hash Tables Exercise #1, #2 & #3/src/hashtable.c#L707)

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
