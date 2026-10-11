class Obj {
  public:
    void Base();
    void Finish();
    void* p0;
    void* p4;
    char pad8[8];
    void* p10;
    void* p14;
    char pad18[0x0c];
    void* p24;
    void* p28;
    void* p2c;
    void* p30;
    void* p34;
    void* p38;
    void* p3c;
    void* p40;
    void* p44;
    void* p48;
    void* p4c;
    void* p50;
    void* p54;
    void* p58;
    void* p5c;
    void* p60;
};
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
void Obj::Finish() {
    Base();
    if (p10)
        operator delete(p10);
    operator delete[](p14);
    operator delete[](p24);
    p60 = p5c;
    if (p60)
        operator delete[](p60);
    p50 = p4c;
    if (p50)
        operator delete[](p50);
    p40 = p3c;
    if (p40)
        operator delete[](p40);
    p30 = p2c;
    if (p30)
        operator delete[](p30);
    p4 = p0;
    if (p4)
        operator delete[](p4);
}