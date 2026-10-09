extern int gCount;
extern int gSlot;
extern void* Alloc(unsigned int);
struct Obj {
    int v;
    char pad4[12];
    int a;
    int b;
    int c;
    void Init(const char*);
};
extern void Register(int*, Obj**, int);
extern const char name[];
void FUN_001abe80() {
    if (gCount == 0) {
        Obj* p;
        Obj* q = (Obj*)Alloc(0x20);
        if (q != 0) {
            q->Init(name);
            q->v = 0x41d4ac;
            q->a = 0x4c2a28;
            q->b = 0x1f;
            q->c = 0x1aacf0;
            p = q;
        } else {
            p = 0;
        }
        Register(&gSlot, &p, 1);
    }
    ++gCount;
}
