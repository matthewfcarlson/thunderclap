struct Param { void Initialize(const char *); char pad[24]; };
extern int __cdecl Alloc(unsigned int);
extern void __cdecl Register(void *, void *, int);
extern int gCount;
extern int gSlot;
void FUN_000534e0() {
    if (gCount == 0) {
        Param *p = (Param *)Alloc(0x18);
        void *out;
        if (p) {
            p->Initialize("interrupt");
            *(unsigned int *)p = 0x3f7938;
            *(unsigned int *)((char *)p + 0x10) = 0x47d40;
            out = p;
        }
        else out = 0;
        Register(&gSlot, &out, 1);
    }
    ++gCount;
}
