# Algoritmi 1

## Sperimentazione

### Stack
#### EX 1
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Stack 1](/Stack%20Exercise%20-%20Abstract%20Data%20Types)
- [Push](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L64)
- [Pop](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L90)
- [Top](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L115)
- [Is empty](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L128)
- [Size](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L145)
- [Clear](/Stack%20Exercise%20-%20Abstract%20Data%20Types/src/stack.c#L155)
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
- [Put](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L91)
- [Insert](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L134)
- [Get](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L168)
- [Contains](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L201)
- [upo_bst_max_impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L216)
- [Delete](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L244)
- [Size](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L336)
- [Height](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L356)
- [Traverse in order](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L373)
- [Is empty](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L388)
```make
make clean test
./test/test_bst

valgrind --tool=memcheck --leak-check=full ./test/test_bst
```
#### EX 2
- [Min](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L304) (Non implemantata)
- [Max](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L312) (Non implemantata)
- [Delete min](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L320) (Non implemantata)
- [Delete max](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L328) (Non implemantata)
- [Floor](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L336)
- [Ceiling](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L388) (Non implemantata)
- [Keys range](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L396) (Non implemantata)
- [Keys](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L404)
- [Is bst](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L443)
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

valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_sepchain
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
- [Resize](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L586)

```make
make clean test
./test/test_hashtable_linprob

valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_linprob
```
#### EX 3 Esercizi Extra
- [Sepchain Keys](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L652)
- [Sepchain Traverse](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L682) (Non implemantata)
- [Linprob Keys](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L695) (Non implemantata)
- [Linprob Traverse](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L707)

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
