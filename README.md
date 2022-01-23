# Algoritmi 1

## Sperimentazione

### Stack
#### EX 1
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Stack 1](/Stack%20Exercise%20-%20Abstract%20Data%20Types)
- [Push](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L64)
- [Pop](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L91)
- [Top](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L116)
- [Is empty](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L129)
- [Size](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L146)
- [Clear](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L156)
```make
make clean test
./test/test_stack

valgrind --tool=memcheck --leak-check=full ./test/test_stack
```
##### File
[Open stack.c](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c)
#### EX 2
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Stack 2](/Stack%20Exercise%20-%20Abstract%20Data%20Types)
- [Eval postfix](/Stack%20Exercise%20-%20Abstract%20Data%20Types/apps/postfix_eval.c#L91)
- [Eval lines](/Stack%20Exercise%20-%20Abstract%20Data%20Types/apps/postfix_eval.c#L186)
```make
make clean apps
./apps/postfix_eval
./apps/postfix_eval -f data/postfix.txt

valgrind --tool=memcheck --leak-check=full ./apps/postfix_eval -f data/postfix.txt
```
##### File
[Open postfix_eval.c](/Stack%20Exercise%20-%20Abstract%20Data%20Types/apps/postfix_eval.c)

### Binary Search Trees
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Trees](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232)
#### EX 1
- [Create](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L35)
- [Destroy](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L55)
- [Clear](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L80) & [Clear impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L64)
- [Put](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L91) & [Put impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L104)
- [Insert](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L138) & [Insert impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L145)
- [Get](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L172) & [Get impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L184)
- [Contains](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L205)
- [upo_bst_max_impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L220)
- [Delete](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L248) & [Delete impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L259)
- [Size](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L340) & [Size impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L348)
- [Height](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L360) & [Height impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L366)
- [Traverse in order](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L377) & [Traverse impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L382)
- [Is empty](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L392)
```make
make clean test
./test/test_bst

valgrind --tool=memcheck --leak-check=full ./test/test_bst
```
#### EX 2
- [Min](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L409)
- [Max](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L424)
- [Delete min](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L439)
- [Delete max](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L473)
- [Floor](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L512) & [Floor impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L525)
- [Ceiling](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L563)
- [Keys range](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L605) & [Traverse impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L611)
- [Keys](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L640) & [Traverse impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L651)
- [Is bst](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L717) & [Traverse impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L725)
```make
make clean test
./test/test_bst_more

valgrind --tool=memcheck --leak-check=full ./test/test_bst_more
```
#### File
[Open bst.c](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c)

### Hash
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Hash](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233)
#### EX 1 HASH TABLE con Concatenazione separata
- [Create](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L35)
- [Destroy](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L82)
- [Clear](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L92)
- [Put](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L147) & [upo_ht_sepchain_list_node_create](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L130)
- [Insert](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L179) & [upo_ht_sepchain_list_node_create](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L130)
- [Get](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L213)
- [Contains](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L230)
- [Delete](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L241)
- [Size](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L278)
- [Empty](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L304) & [Size](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L278)
- [Capacity](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L309)
- [Load factor](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L314) & [Size](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L278)
- [Get comparator](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L319)
- [Get hasher](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L324)

```make
make clean test
./test/test_hashtable_sepchain

valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_sepchain
```
#### EX 2 HASH TABLE con LINEAR PROBING
- [Create](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L336)
- [Destroy](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L385)
- [Clear](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L395)
- [Put](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L426)
- [Insert](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L476)
- [Get](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L529)
- [Contains](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L549)
- [Delete](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L563)
- [Size](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L594)
- [Empty](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L613)
- [Capacity](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L618)
- [Load factor](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L623)
- [Resize](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L628)

```make
make clean test
./test/test_hashtable_linprob

valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_linprob
```
#### EX 3 Esercizi Extra
- [Sepchain Keys](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L695)
- [Sepchain Traverse](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L727)
- [Linprob Keys](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L755)
- [Linprob Traverse](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L791)

```make
make clean test
./test/test_hashtable_sepchain_more

valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_sepchain_more

./test/test_hashtable_linprob_more

valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_linprob_more
```
#### File
[Open hashtable.c](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c)

## Fondamenti
### Sort
- [Quick Sort](https://www.geeksforgeeks.org/quick-sort/)
- [Merge Sort](https://www.geeksforgeeks.org/merge-sort/)
- [Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)
- [Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
### Complessità Computazionale
Complessità di una funzione [part 1](https://italiancoders.it/complessita-computazionale-parte-1/) & [part 2](https://italiancoders.it/complessita-computazionale-parte-2/)
