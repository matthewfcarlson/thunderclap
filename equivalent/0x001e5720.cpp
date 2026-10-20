// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 8/8)
// FUN_001e5720 @ 0x001e5720
class Thing_1e5720 {
  public:
    char pad0[0x14c];
    char f14c;
    char f14d;
    char f14e;
    void Init();
    void Set(int);
};
class Manager_1e5720 {
  public:
    char pad[0x4c];
    void A(void*);
    void B(void*);
};
class Owner_1e5720 {
  public:
    char pad[0x1e830];
    struct Sub {
        char pad[0x4c];
        Manager_1e5720* m;
    }* mgr;
    // equiv-conv: FUN_001e51b0 ecx stack esi
    void Notify(Thing_1e5720*, int);
    void Run(Thing_1e5720*);
};
void Owner_1e5720::Run(Thing_1e5720* p) {
    if (!p)
        return;
    p->Init();
    if (p->f14e)
        Notify(p, (int)p);
    p->Set(1);
    if (p->f14c) {
        p->Set(1);
        mgr->m->A(&p->pad0[8]);
    }
    if (p->f14d) {
        p->Set(1);
        mgr->m->B(&p->pad0[8]);
    }
}