// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 8/8)
// FUN_0027b710 @ 0x0027b710
struct Entry_27b710 {
    char pad0[8];
    unsigned int a;
    unsigned int b;
    char pad10[0x28 - 0x10];
};

struct Table_27b710 {
    char pad0[0x44];
    Entry_27b710* begin;
    Entry_27b710* end;
    Entry_27b710* Find(unsigned int a, unsigned int b);
};

Entry_27b710* Table_27b710::Find(unsigned int a, unsigned int b) {
    Entry_27b710* first = begin;
    for (unsigned int i = 0; i < (unsigned int)(end - begin); ++i) {
        Entry_27b710* e = &first[i];
        if (e->a == a && e->b == b)
            return e;
    }
    return 0;
}
