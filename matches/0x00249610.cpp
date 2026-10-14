typedef unsigned int u32_249610;
int __cdecl target(void* unused, void* p) {
    volatile char* q = *(char**)((char*)p + 8);
    q += 0x40;
    u32_249610 x = *(volatile u32_249610*)q;
    return x ? (int)x - 4 : 0;
}