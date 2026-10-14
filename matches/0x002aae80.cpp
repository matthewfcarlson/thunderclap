extern "C" char DAT_0042e064[];
class Ref_2aae80 {
  public:
    virtual void A();
    virtual void Release();
};
class Loader_2aae80 {
  public:
    int* vt;
    int pad4;
    unsigned count;
    Ref_2aae80* items[8];
    Ref_2aae80* last;
    void BaseDestroy();
    void F();
};
void Loader_2aae80::F() {
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
