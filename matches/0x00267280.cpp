struct Ent_267280 {
    void* p;
    int a, b, c;
};
extern Ent_267280 tbl[];
extern void* vt_267280;
extern void* g40;
extern int g44, g48, g4c;
extern void* g50;
extern void* g58;
extern unsigned char g5c;
extern char Vftable[];
extern void InitA();
extern void InitB();
extern void Tail();
void Target() {
    g5c = 1;
    InitA();
    g50 = Vftable;
    InitB();
    g58 = &g50;
    g40 = &g50;
    g44 = 0;
    g48 = 0;
    g4c = 0;
    unsigned i = 0;
    do {
        Ent_267280* e = (Ent_267280*)((char*)tbl + i);
        e->a = 0;
        e->c = 0;
        e->b = 0;
        e->p = &g50;
        i += 0x10;
    } while (i < 0x2e0);
    Tail();
}
