struct Mgr_d9100 {
    char pad[0x1bc8];
    char flag;
};
struct Mgr2_d9100 {
    Mgr_d9100* Get();
};
extern Mgr2_d9100* g_mgr_d9100;
extern const char* g_a_d9100;
extern const char* g_b_d9100;
extern const char* g_c_d9100;
extern const char* g_d_004a0c98;

struct Menu_d9100 {
    void Show(const char* a, const char* b, const char* f1, const char* f2, const char* ok, int n,
              const char* f3, const char* f4);
};

struct Obj_d9100 {
    char pad[0x21c];
    int v21c;
    char pad2[0x3b0 - 0x220];
    char f3b0;
    char pad3[0x3eb - 0x3b1];
    char f3eb;
    Menu_d9100* GetMenu();
    void Run(int a, int b);
};

extern const char kZero_d9100[];
extern const char kOk[];

void Obj_d9100::Run(int a, int b) {
    Menu_d9100* m = GetMenu();
    const char* s;
    if (!f3eb) {
        Mgr_d9100* g = g_mgr_d9100->Get();
        if (g->flag)
            s = g_b_d9100;
        else
            s = g_a_d9100;
    } else {
        s = g_c_d9100;
    }
    m->Show(s, g_d_004a0c98, kZero_d9100, kZero_d9100, kOk, 2, kZero_d9100, kZero_d9100);
    f3b0 = 1;
    v21c = 0;
}
