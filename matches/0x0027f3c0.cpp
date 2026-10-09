struct Entry {
    int key;
    char pad[0x44];
    int occupied;
    char tail[0x14];
};
struct Block {
    int x[16];
};
class Manager {
  public:
    char pad[0x18];
    Entry entries[100];
    int Update(int key, Block* source);
};
int Manager::Update(int key, Block* source) {
    int i = 0;
    while (i < 100) {
        if (entries[i].occupied != 0 && entries[i].key == key) {
            Block* dest = (Block*)((char*)this + 0x20 + i * 0x60);
            *dest = *source;
            return key;
        }
        ++i;
    }
    return 0;
}