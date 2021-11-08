## Algoritmi 1

### Stack
#### EX 1
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Stack 1](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise)
- [Push](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise/src/stack.c#L64)
- [Pop](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise/src/stack.c#L90)
- [Top](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise/src/stack.c#L115)
- [Is empty](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise/src/stack.c#L128)
- [Size](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise/src/stack.c#L145)
- [Clear](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise/src/stack.c#L155)
```make
make clean test
./test/test_stack

valgrind --tool=memcheck --leak-check=full ./test/test_stack
```
##### File
[Open stack.c](/Abstract%20Data%20Types%201%20-%20Stack%20Exercise/src/stack.c)
#### EX 2
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Stack 2](/Abstract%20Data%20Types%202%20-%20Stack%20Exercise)
- [Eval postfix](/Abstract%20Data%20Types%202%20-%20Stack%20Exercise/apps/postfix_eval.c#L91)
- [Eval lines](/Abstract%20Data%20Types%202%20-%20Stack%20Exercise/apps/postfix_eval.c#L186)
```make
make clean apps
./apps/postfix_eval
./apps/postfix_eval -f data/postfix.txt

valgrind --tool=memcheck --leak-check=full
    ./apps/postfix_eval -f data/postfix.txt
```
##### File
[Open postfix_eval.c](/Abstract%20Data%20Types%202%20-%20Stack%20Exercise/apps/postfix_eval.c)

### Binary Search Trees
Copiare [ToolKit](/Algo1%20Core%20ToolKit) nella cartella del [Trees](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232)
#### EX 1
- [Create](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L36)
- [Destroy](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L55)
- [Clear](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L81) & [Clear impl](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L64)
- [Put](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L90) (Non implemantata)
- [Insert](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L98) (Non implemantata)
- [Get](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L106) (Non implemantata)
- [Contains](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L114) (Non implemantata)
- [Max](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L126)
- [Delete](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L145)
- [Size](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L242)
- [Height](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L265) (Non implemantata)
- [Traverse in order](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L273) (Non implemantata)
- [Is empty](/Binary%20Search%20Trees%20Exercise%20%231%20%26%20%232/src/bst.c#L281) (Non implemantata)
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
- [Resize](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L586)

```make
make clean test
./test/test_hashtable_linprob

valgrind --tool=memcheck --leak-check=full
    ./test/test_hashtable_linprob
```
#### EX 3 Esercizi Extra
- [Sepchain Keys](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L652)
- [Sepchain Traverse](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L682)
- [Linprob Keys](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L695)
- [Linprob Traverse](/Hash%20Tables%20Exercise%20%231%2C%20%232%20%26%20%233/src/hashtable.c#L707)

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

### Sort
- [Quick Sort](https://www.geeksforgeeks.org/quick-sort/)
- [Merge Sort](https://www.geeksforgeeks.org/merge-sort/)
- [Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)
- [Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
