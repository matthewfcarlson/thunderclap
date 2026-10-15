struct Item {
    void Go();
};
class Obj {
    char a[0x44];
    void* m;
    char b[0x570 - 0x48];
    void* slots[2];
    Item* Fetch(void*, void*);

  public:
    void Add(void* p);
};
void Obj::Add(void* p) {
    int i = 0;
    void** q = slots;
    do {
        if (!*q) {
            slots[i] = p;
            break;
        }
        ++i;
        ++q;
    } while (i < 2);
    Fetch(p, m)->Go();
}