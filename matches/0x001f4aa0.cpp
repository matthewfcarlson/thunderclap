class Obj {
  public:
    int vptr;
    char pad4[0xc];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    int m1c;
    Obj(char*, char*);
};
extern "C" void __stdcall Init(void*, int);
extern "C" char __cdecl Get(void*);
Obj::Obj(char* a, char* b) {
    Init(a, 4);
    vptr = 0x424b2c;
    m1c = (int)b;
    b18 = Get((void*)0x48e100);
    b10 = Get((void*)0x49cad8);
    b11 = Get((void*)0x49cad8);
    b12 = Get((void*)0x49cad8);
    b13 = Get((void*)0x48e134);
}