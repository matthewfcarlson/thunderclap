typedef unsigned char u8;
typedef int i32;
u8 __cdecl target(i32 a, i32 b) {
    if (a && b)
        return *(u8*)(b + 0x19);
    return 0;
}