class Ref_282190 {
  public:
    virtual void A();
    virtual void Release();
};
struct Entry_282190 {
    int key;
    Ref_282190* value;
    char pad[0x14];
};
class Owner_282190 {
  public:
    char pad[0x24];
    Entry_282190 entries[100];
    void Remove(int);
};
void Owner_282190::Remove(int key) {
    for (int i = 0; i < 100; ++i) {
        if (entries[i].value != 0 && entries[i].key == key) {
            Ref_282190* volatile* q = (Ref_282190* volatile*)&entries[i].value;
            Ref_282190* p = *q;
            if (p) {
                p->Release();
                entries[i].value = 0;
            }
        }
    }
}