#include "stack.h"
#include <assert.h>

void test_push_pop_empty() {
    reset();
    push(24);
    assert(pop() == 24);
    assert(empty());
}

// Some of the tests you could have written, for reference

void test_push_pop_lifo_order() {
    // LIFO: "Last in, First out"
    reset();
    push(20);
    push(30);
    push(40);
    assert(!empty());
    assert(pop() == 40); // and not 20
    assert(pop() == 30);
    assert(pop() == 20);
    assert(empty());
}

void test_push_copy_into_array_lengths_match() {
    // In this case, the `space` argument to `copy_to_array` matches
    // the number of items in the stack.
    reset();
    push(11);
    push(12);
    push(20);
    push(21);
    int array[4];
    copy_to_array(array, 4);
    assert(array[0] == 21);
    assert(array[1] == 20);
    assert(array[2] == 12);
    assert(array[3] == 11);
}

void test_copy_into_array_space_less() {
    // In this case, the "space" argument to "copy_into_array"
    // is less than the number of items in the stack.
    reset();
    push(1);
    push(2);
    push(3);
    push(4);
    int array[4];
    array[2] = 99; // If copy_to_array tampers with this, we know it didn't respect "space"
    array[3] = -99;
    copy_to_array(array, 2);
    assert(array[0] == 4);
    assert(array[1] == 3);
    assert(array[2] == 99); // Rather than 2
}

void test_copy_into_array_space_more() {
    reset();
    push(2);
    push(3);
    int array[20];
    copy_to_array(array, 20);
    assert(array[0] == 3);
    assert(array[1] == 2);
    // If copy_to_array didn't check if the stack ends, this would lead to a segfault
}

// Remember to call your tests in main()
int main() {
    test_push_pop_empty();
    test_push_pop_lifo_order();
    test_push_copy_into_array_lengths_match();
    test_copy_into_array_space_less();
    test_copy_into_array_space_more();

    // Keep this call here so that you don't leak the nodes left over from
    // the last test
    reset();
}
