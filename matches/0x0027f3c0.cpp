struct Entry_27f3c0 {
    int key;
    char pad[0x44];
    int occupied;
    char tail[0x14];
};
struct Block_27f3c0 {
    int x[16];
};
class Manager_27f3c0 {
  public:
    char pad[0x18];
    Entry_27f3c0 entries[100];
    int Update(int key, Block_27f3c0* source);
};
int Manager_27f3c0::Update(int key, Block_27f3c0* source) {
    int i = 0;
    while (i < 100) {
        if (entries[i].occupied != 0 && entries[i].key == key) {
            Block_27f3c0* dest = (Block_27f3c0*)((char*)this + 0x20 + i * 0x60);
            *dest = *source;
            return key;
        }
        ++i;
    }
    return 0;
}