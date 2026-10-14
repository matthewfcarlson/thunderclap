// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 15/16, incomplete)
// FUN_00090270 @ 0x00090270
struct Entry_90270 {
    int value;
    char name[0x20];
    char text[0x20];
};

class Registry_90270 {
public:
    char pad0[0xc8c];
    Entry_90270 entries[16];      // 0xc8c
    void FUN_00090270(const char *name, const char *text, int value);
};

// Stores a new named entry in the first free slot (an empty name marks a free slot).
void Registry_90270::FUN_00090270(const char *name, const char *text, int value)
{
    int i = 0;
    while (i < 16 && entries[i].name[0] != 0)
        i++;
    if (i >= 16)
        return;
    Entry_90270 *e = &entries[i];
    e->value = value;
    const char *src = text;
    char *dst = e->text;
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c != 0);
    src = name;
    dst = e->name;
    do {
        c = *src++;
        *dst++ = c;
    } while (c != 0);
}
