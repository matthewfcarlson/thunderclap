extern "C" char DAT_0040c244[];
class FEItem {
  public:
    virtual void A();
    virtual void B();
};
class FEItem2 {
  public:
    virtual void A();
    virtual void B();
    virtual void C(int);
};
extern void __cdecl FreeThing(void*);
class FEContainer {
  public:
    virtual void V();
    char p[0x24];
    FEItem* a[8];
    int x;
    void* b[0x80];
    char r[0x200];
    FEItem2* c[0x80];
    char s[0x204];
    int y;
    void Clear();
};
void FEContainer::Clear() {
    *(int*)this = ((int)DAT_0040c244);
    for (int i = 0; i < 8; i++) {
        if (a[i]) {
            a[i]->B();
            a[i] = 0;
        }
    }
    for (int j = 0; j < 128; j++) {
        if (b[j]) {
            FreeThing(b[j]);
            b[j] = 0;
        }
    }
    for (int k = 0; k < 128; k++) {
        if (c[k]) {
            c[k]->C(1);
            c[k] = 0;
        }
    }
    x = 0;
    y = 0;
}