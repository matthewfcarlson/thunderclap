extern "C" int __cdecl strncmp(const char*, const char*, unsigned int);
struct NameEntry {
    char text[32];
};
struct NameRing {
    char pad0[0x10];
    unsigned int current;
    unsigned int capacity;
    char pad18[0x20];
    NameEntry entries[1];
    bool FUN_0027a970(const char* name);
};
bool NameRing::FUN_0027a970(const char* name) {
    unsigned int start = current;
    for (;;) {
        if (strncmp(entries[current].text, name, 32) == 0)
            return true;
        current = (current + 1U) % capacity;
        if (current == start)
            return false;
    }
}