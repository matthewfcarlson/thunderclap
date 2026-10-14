// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 0/0)
// FUN_000792a0 @ 0x000792a0
struct Name {
    int lo;
    int hi;
    Name* FUN_0027b0e0(const char* text);
    void FUN_0027af70(const Name* other);
    void FUN_0027af50();
};

struct Entry {
    Name name;            // 0x00
    int value;            // 0x08
    char flag;            // 0x0c
    char pad0d[3];
};

struct Registry {
    char pad00[0x34a8];
    Entry entries[1];     // 0x34a8
    char pad34b8[0x3548 - 0x34b8];
    int count;            // 0x3548
    void Add(const char* text, int value, char flag);
};

void Registry::Add(const char* text, int value, char flag)
{
    Name tmp;
    entries[count].name.FUN_0027af70(tmp.FUN_0027b0e0(text));
    tmp.FUN_0027af50();
    entries[count].value = value;
    entries[count].flag = flag;
    count++;
}
