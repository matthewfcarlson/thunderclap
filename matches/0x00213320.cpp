typedef unsigned int u32_213320;
struct Thing_213320 {
    char pad[8];
    u32_213320* ptr;
};
void FUN_00213320(Thing_213320* p) {
    *p->ptr = 0;
    p->ptr = (u32_213320*)((char*)p->ptr + 8);
}
