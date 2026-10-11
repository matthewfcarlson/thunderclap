extern "C" char DAT_003f423c[];
extern "C" void __stdcall Init(void*, int);
extern "C" unsigned char __cdecl Get(void*);
extern char gA;
extern char gB;
extern char gC;
class Method5 {
  public:
    virtual void Dummy();
    char pad4[12];
    unsigned char x10;
    unsigned char x11;
    unsigned char x12;
    unsigned char x13;
    unsigned char x14;
    char pad15[3];
    unsigned char x18;
    char pad19[3];
    int arg;
    Method5* Build(void* p2, int p3);
};
Method5* Method5::Build(void* p2, int p3) {
    Init(p2, 5);
    *(void**)this = (void*)((int)DAT_003f423c);
    arg = p3;
    x18 = Get(&gA);
    x10 = Get(&gB);
    x11 = Get(&gB);
    x12 = Get(&gC);
    x13 = Get(&gC);
    x14 = Get(&gC);
    return this;
}
