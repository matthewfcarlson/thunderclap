// FUN_000792a0 @ 0x000792a0
struct Name_792a0 {
    int lo;
    int hi;
    Name_792a0* FUN_0027b0e0(const char* text);
    void FUN_0027af70(const Name_792a0* other);
    void FUN_0027af50();
};

struct Entry_792a0 {
    Name_792a0 name;            // 0x00
    int value;            // 0x08
    char flag;            // 0x0c
    char pad0d[3];
};

struct Registry_792a0 {
    char pad00[0x34a8];
    Entry_792a0 entries[1];     // 0x34a8
    char pad34b8[0x3548 - 0x34b8];
    int count;            // 0x3548
    void Add(const char* text, int value, char flag);
};

void Registry_792a0::Add(const char* text, int value, char flag)
{
    Name_792a0 tmp;
    Name_792a0* t = tmp.FUN_0027b0e0(text);
    entries[count].name.FUN_0027af70(t);
    tmp.FUN_0027af50();
    entries[count].value = value;
    entries[count].flag = flag;
    count++;
}
