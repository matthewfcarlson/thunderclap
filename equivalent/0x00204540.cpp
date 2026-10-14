// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 28/28)
// FUN_00204540 @ 0x00204540
struct Entry_204540 {
    unsigned int data;
    unsigned char active;
    char name[55];
};
struct Registry_204540 {
    char padding[0x48];
    Entry_204540 primary[20];
    Entry_204540 secondary[2];
    Entry_204540* FUN_00204540(const char* name);
};
Entry_204540* Registry_204540::FUN_00204540(const char* name) {
    for (int i = 0; i < 20; ++i) {
        const unsigned char* a = (const unsigned char*)name;
        const unsigned char* b = (const unsigned char*)primary[i].name;
        while (*a == *b && *a) { ++a; ++b; }
        if (*a == *b && primary[i].active != 0) return &primary[i];
    }
    for (int j = 0; j < 2; ++j) {
        const unsigned char* a = (const unsigned char*)name;
        const unsigned char* b = (const unsigned char*)secondary[j].name;
        while (*a == *b && *a) { ++a; ++b; }
        if (*a == *b && secondary[j].active != 0) return &secondary[j];
    }
    return 0;
}