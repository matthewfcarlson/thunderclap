struct Entry {
    int key;
    char pad[0x44];
    int active;
    int unused;
    int a;
    int b;
    char tail[8];
};
class Manager {
    char pad[0x18];
    Entry entries[100];

  public:
    bool Set(int key, int a, int b);
};
bool Manager::Set(int key, int a, int b) {
    bool result = false;
    int i = 0;
    Entry* p = entries;
    while (i < 100) {
        if (p->active && p->key == key) {
            int offset = i * 0x60;
            *(int*)((char*)this + offset + 0x68) = a;
            *(int*)((char*)this + offset + 0x6c) = b;
            result = true;
            break;
        }
        ++i;
        ++p;
    }
    return result;
}