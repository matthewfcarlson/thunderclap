extern void __cdecl R0(void*);
extern void __cdecl R1(void*);
extern void __cdecl R2(void*);
extern void __cdecl R3(void*);
class Item_f6f60 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_f6f60 {
  public:
    void* p0;
    char a[8];
    void* pC;
    char b[8];
    void* p18;
    char c[8];
    Item_f6f60* items[25];
    int count;
    char d[0x90];
    void* p11c;
    void Clear();
};
void Owner_f6f60::Clear() {
    if (p0)
        R0(p0);
    if (p11c)
        R1(p11c);
    if (pC)
        R2(pC);
    if (p18)
        R3(p18);
    for (int i = 0; i < count; ++i) {
        Item_f6f60* q = items[i];
        if (q) {
            q->B();
            items[i] = 0;
        }
    }
}