// STATUS: equivalent (tools/equiv.py level 3: 233 inputs, branch coverage 10/10)
// FUN_00067ba0 @ 0x00067ba0
struct Name_67ba0 {
    char pad[8];
    void FUN_0027b040(const char* s);
};
struct Entry_67ba0 {
    int a, b, c, d, e;
    char pad14[4];
    Name_67ba0 name;
};
class HandleTable {
public:
    unsigned counter;
    int head;
    unsigned slot[64];
    Entry_67ba0 entry[64];
    unsigned Alloc();
};
unsigned HandleTable::Alloc() {
    int start = head;
    int i = start;
    do {
        if (slot[i] == 0) break;
        i = (i + 1) % 64;
    } while (i != start);
    Entry_67ba0* e = &entry[i];
    e->a = 0; e->d = 0; e->c = 0; e->b = 0;
    e->e = 0;
    e->name.FUN_0027b040("");
    unsigned gen = counter;
    unsigned handle = (gen << 8) | i;
    slot[i] = handle;
    head = (i + 1) % 64;
    counter = (gen + 1) % 0xffffff;
    if (counter == 0) counter = 1;
    return handle;
}
