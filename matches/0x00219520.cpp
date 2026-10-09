typedef unsigned char u8;
struct Owner;
void* __cdecl FUN_0021add0(Owner*, int, int, int);
void __cdecl FUN_00217130(Owner*, void*, int);

void* __cdecl FUN_00219520(Owner* owner, int count) {
    void* p = FUN_0021add0(owner, 0, 0, count * 8 + 0x10);
    FUN_00217130(owner, p, 6);
    ((u8*)p)[7] = (u8)count;
    ((u8*)p)[6] = 1;
    return p;
}