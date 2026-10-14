extern void F24bae0(void*, int);
extern void F259b40(void*);
extern void F25d300(void*);
extern void F25e280(void*);
extern void* F25e070();
extern void F247550(void*, void*);
extern char g4e61a0[];
extern void* g4e61e8;
extern void* g4e61ec;
struct Obj_24bf90 {
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
};
void FUN_0024bf90(Obj_24bf90* p) {
    F24bae0(p, 1);
    F259b40(p->c);
    F25d300(p->d);
    F25e280(p->e);
    if (p->e)
        F247550(F25e070(), p->e);
    if (p->f) {
        F25e280(p->f);
        if (p->f)
            F247550(F25e070(), p->f);
    }
    if (!p->b)
        g4e61e8 = p->a;
    else
        *(void**)p->b = p->a;
    if (!p->a)
        g4e61ec = p->b;
    else
        *(void**)((char*)p->a + 4) = p->b;
    F247550(g4e61a0, p);
}