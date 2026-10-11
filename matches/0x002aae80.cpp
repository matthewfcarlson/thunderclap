extern "C" char DAT_0042e064[];
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
    vt = (int*)((int)DAT_0042e064);
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
