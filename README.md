## Algoritmi 1

### Stack
#### EX 1
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Stack 1](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise)
##### File
[Open stack.c](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise/src/stack.c)
#### EX 2
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Stack 2](/Abstract%20Data%20Types%202%20-%20Stack%20Exercise)
##### File
[Open postfix_eval.c](/Abstract%20Data%20Types%202%20-%20Stack%20Exercise/apps/postfix_eval.c)

### Binary Search Trees
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Trees](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232)
#### EX 1
- [Create](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L36)
- [Destroy](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L55)
- [Clear](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L81) & [Clear impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L64)
- [Put](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L90)
- [Insert](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L98)
- [Get](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L106)
- [Contains](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L114)
- [Max](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L126)
- [Delete](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L145)
- [Size](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L242)
- [Height](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L265)
- [Traverse in order](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L273)
- [Is empty](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L281)

#### EX 2
#### File
[Open bst.c](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c)

### Hash
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Hash](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233)
#### EX 1 HASH TABLE con Concatenazione separata
- [Create](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L38)
- [Destroy](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L85)
- [Clear](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L95)
- [Put](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L131)
- [Insert](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L167)
- [Get](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L212)
- [Contains](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L229)
- [Delete](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L246)
- [Size](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L276)
- [Empty](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L283)
- [Capacity](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L288)
- [Load factor](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L293)
- [Get comparator](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L298)
- [Get hasher](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L303)

```make
make clean test
./test/test_hashtable_sepchain

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_sepchain
```
#### EX 2 HASH TABLE con LINEAR PROBING
- [Create](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L320)
- [Destroy](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L369)
- [Clear](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L379)
- [Put](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L408)
- [Insert](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L451)
- [Get](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L501)
- [Contains](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L517)
- [Delete](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L537)
- [Size](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L563)
- [Empty](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L571)
- [Capacity](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L576)
- [Load factor](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L581)
- [upo_ht_linprob_resize](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L586)

```make
make clean test
./test/test_hashtable_linprob

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_linprob
```
#### EX 3 Esercizi Extra
- [upo_ht_sepchain_keys](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L652)
- [upo_ht_sepchain_traverse](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L682)
- [upo_ht_linprob_keys](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L695)
- [upo_ht_linprob_traverse](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L707)

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
