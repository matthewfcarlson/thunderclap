typedef unsigned int u32;
int __cdecl target(void* unused, void* p) {
    volatile char* q = *(char**)((char*)p + 8);
    q += 0x40;
    u32 x = *(volatile u32*)q;
    return x ? (int)x - 4 : 0;
}