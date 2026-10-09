extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);

class C {
  public:
    void* items[1];
    unsigned char Fn(int index);
};

unsigned char C::Fn(int index) {
    void* p = FUN_00344e74(items[index], 0, (const char*)0x49dab8, (const char*)0x49db80, 0);
    if (p)
        return *((unsigned char*)p + 0xb0);
    p = FUN_00344e74(items[index], 0, (const char*)0x49dab8, (const char*)0x49db1c, 0);
    if (p)
        return *((unsigned char*)p + 0x2d);
    p = FUN_00344e74(items[index], 0, (const char*)0x49dab8, (const char*)0x49dad4, 0);
    if (p)
        return *((unsigned char*)p + 0xa8);
    return 0;
}