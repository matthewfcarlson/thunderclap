class Ref {
  public:
    virtual void A();
    virtual void Release();
};
struct Entry {
    int key;
    Ref* value;
    char pad[0x14];
};
class Owner {
  public:
    char pad[0x24];
    Entry entries[100];
    void Remove(int);
};
void Owner::Remove(int key) {
    for (int i = 0; i < 100; ++i) {
        if (entries[i].value != 0 && entries[i].key == key) {
            Ref* volatile* q = (Ref* volatile*)&entries[i].value;
            Ref* p = *q;
            if (p) {
                p->Release();
                entries[i].value = 0;
            }
        }
    }
}