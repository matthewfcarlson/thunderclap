typedef unsigned int u32;
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern void __cdecl CopyText(char*, unsigned int, const char*, const char*);
struct Obj {
    u32 data[21];
    Obj* Init(const char* a, u32 b);
};
Obj* Obj::Init(const char* a, u32 b) {
    memset(this, 0, 0x54);
    data[0] = 0x54;
    data[1] = 0x1d;
    CopyText((char*)&data[5], 0x40, "%s", a);
    data[4] = b;
    return this;
}