// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00298960 @ 0x00298960
struct Entry { char pad[8]; int first; int second; };
struct Item { char pad[8]; Entry *entry; };
struct Owner { char pad[0x3c]; Item *begin; Item *end; unsigned char FUN_00298960(const int *key); };
unsigned char Owner::FUN_00298960(const int *key) {
    unsigned char count = (unsigned char)(end - begin);
    for (unsigned char i = 0; i < count; ++i) {
        Entry *e = begin[i].entry;
        if (e->first == key[0] && e->second == key[1]) return i;
    }
    return 0xff;
}