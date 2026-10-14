// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 8/8)
// FUN_0027b710 @ 0x0027b710
struct Entry {
    char pad0[8];
    unsigned int a;
    unsigned int b;
    char pad10[0x28 - 0x10];
};

struct Table {
    char pad0[0x44];
    Entry* begin;
    Entry* end;
    Entry* Find(unsigned int a, unsigned int b);
};

Entry* Table::Find(unsigned int a, unsigned int b) {
    Entry* first = begin;
    for (unsigned int i = 0; i < (unsigned int)(end - begin); ++i) {
        Entry* e = &first[i];
        if (e->a == a && e->b == b)
            return e;
    }
    return 0;
}
