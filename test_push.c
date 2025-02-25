#include "stack.h"
#include <assert.h>

int test_push_pop_empty() {
    reset();
    push(24);
    assert(pop() == 24);
    assert(empty());
}

// TODO Write more tests below
// Since your tests depend on functions written by your row's other teams,
// you cannot run your tests until they are done!

// Remember to call your tests in main()
int main() {
    test_push_pop_empty();

    // Keep this call here so that you don't leak the nodes left over from
    // the last test
    reset();
}
