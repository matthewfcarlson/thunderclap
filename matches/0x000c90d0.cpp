struct Entry_c90d0 { // 0x40 bytes
    int id;    // +0x00, -1 = unused
    char pad04[0x3d - 4];
    unsigned char value; // +0x3d
    char pad3e[0x40 - 0x3e];
};

class Thing_c90d0 {
  public:
    Entry_c90d0* GetEntry(int index) {
        if (index >= 0 && index < 0x80 && entries[index].id != -1)
            return &entries[index];
        return 0;
    }
    void Set(int index, unsigned char value);

    char pad[0x258];
    Entry_c90d0 entries[0x80]; // +0x258
};

void Thing_c90d0::Set(int index, unsigned char value) {
    Entry_c90d0* e = GetEntry(index);
    if (e)
        e->value = value;
}