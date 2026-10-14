class Item_29f590 {
  public:
    virtual void A();
    virtual void B();
};
class End_29f590 {
  public:
    void Finish();
};
class Cache_29f590 {
  public:
    virtual void V();
    int pad04[9];
    int m28;
    int m2c;
    int m30;
    int m34;
    ~Cache_29f590();
};
void __cdecl Free(void*);
void __cdecl Free2(void*);
void __cdecl Free3(void*);
Cache_29f590::~Cache_29f590() {
    int i = 0;
    if (m34 > 0) {
        for (; i < m34; ++i) {
            Item_29f590* p = *(Item_29f590**)(*(char**)((char*)this + 0x2c) + i * 0x1c + 0xc);
            p->B();
        }
    }
    Free((void*)m30);
    if (m2c != 0)
        Free2((char*)m2c - 4);
    Free3((void*)m28);
    ((End_29f590*)((char*)this + 4))->Finish();
}