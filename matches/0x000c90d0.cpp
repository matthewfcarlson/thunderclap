struct Entry { // 0x40 bytes
    int id;    // +0x00, -1 = unused
    char pad04[0x3d - 4];
    unsigned char value; // +0x3d
    char pad3e[0x40 - 0x3e];
};

class Thing {
  public:
    Entry* GetEntry(int index) {
        if (index >= 0 && index < 0x80 && entries[index].id != -1)
            return &entries[index];
        return 0;
    }
    void Set(int index, unsigned char value);

    char pad[0x258];
    Entry entries[0x80]; // +0x258
};

void Thing::Set(int index, unsigned char value) {
    Entry* e = GetEntry(index);
    if (e)
        e->value = value;
}