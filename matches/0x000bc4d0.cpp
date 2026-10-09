struct Obj;
extern void* g_a;
extern void* g_b;
void __cdecl Fa(void*);
void __cdecl Release(void*);
void Fb();
Obj* Fc();
struct Obj {
    void Fd();
};
struct Sub {
    void Fe();
};
struct Mgr {
    void Ff();
};
struct Dev {
    void Fg(int);
};

extern Mgr* g_mgr;

struct Main {
    char pad0[0x10];
    int state;
    char pad1[0xc];
    Dev* dev;
    int arg;
    char pad2[0x34];
    Sub* sub;
    char pad3[0xc];
    void* a[0x80];
    void* b[0x80];
    char pad4[0x1bc8 - 0x46c];
    char flag;
    void Run();
};

void Main::Run() {
    Fa(g_a);
    int i;
    for (i = 0; i < 0x80; i++) {
        if (!a[i])
            break;
        Release(a[i]);
        a[i] = 0;
    }
    for (i = 0; i < 0x80; i++) {
        if (!b[i])
            break;
        Release(b[i]);
        b[i] = 0;
    }
    Fb();
    Obj* o = Fc();
    if (o)
        o->Fd();
    if (sub)
        sub->Fe();
    g_mgr->Ff();
    dev->Fg(arg);
    state = 3;
    flag = 0;
}
