#CFLAGS+=-Wall -Wextra -ansi -pedantic -g
CFLAGS+=-Wall -Wextra -std=c11 -pedantic -g

objects = int_by_byte \
		  dangling_ptr \
		  dangling_ptr_free \
		  dangling_ptr_outscope \
		  func_ptr \
		  memleak \
		  memleak_nofree \
		  swap \
		  void_ptr \
		  wild_ptr

all: $(objects)

clean:
	$(RM) $(objects)
