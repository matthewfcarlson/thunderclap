struct Mgr {
    char pad[0x1bc8];
    char flag;
};
struct Mgr2 {
    Mgr* Get();
};
extern Mgr2* g_mgr;
extern const char* g_a;
extern const char* g_b;
extern const char* g_c;
extern const char* g_d_004a0c98;

struct Menu {
    void Show(const char* a, const char* b, const char* f1, const char* f2, const char* ok, int n,
              const char* f3, const char* f4);
};

struct Obj {
    char pad[0x21c];
    int v21c;
    char pad2[0x3b0 - 0x220];
    char f3b0;
    char pad3[0x3eb - 0x3b1];
    char f3eb;
    Menu* GetMenu();
    void Run(int a, int b);
};

extern const char kZero[];
extern const char kOk[];

void Obj::Run(int a, int b) {
    Menu* m = GetMenu();
    const char* s;
    if (!f3eb) {
        Mgr* g = g_mgr->Get();
        if (g->flag)
            s = g_b;
        else
            s = g_a;
    } else {
        s = g_c;
    }
    m->Show(s, g_d_004a0c98, kZero, kZero, kOk, 2, kZero, kZero);
    f3b0 = 1;
    v21c = 0;
}
