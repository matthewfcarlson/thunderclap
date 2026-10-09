class Ref {
  public:
    virtual void A();
    virtual void Release();
};
class Loader {
  public:
    int* vt;
    int pad4;
    unsigned count;
    Ref* items[8];
    Ref* last;
    void BaseDestroy();
    void F();
};
void Loader::F() {
    unsigned i = 0;
    vt = (int*)0x42e064;
    if (count > 0) {
        do {
            if (items[i]) {
                items[i]->Release();
                items[i] = 0;
            }
            ++i;
        } while (i < count);
    }
    if (last) {
        last->Release();
        last = 0;
    }
    BaseDestroy();
}
