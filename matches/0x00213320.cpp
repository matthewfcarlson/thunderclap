typedef unsigned int u32;
struct Thing { char pad[8]; u32* ptr; };
void FUN_00213320(Thing* p) {
    *p->ptr = 0;
    p->ptr = (u32*)((char*)p->ptr + 8);
}
