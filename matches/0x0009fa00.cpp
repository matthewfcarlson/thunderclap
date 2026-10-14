struct St_9fa00 {
    int a;
    char p1[8];
    int b;
    char p2[0x30 - 0x10];
    int c;
    char p3[0x48 - 0x34];
    int d;
    char p4[0xa4 - 0x4c];
};
struct Dev_9fa00 {
    void G(St_9fa00* s);
};
struct Mgr_9fa00 {
    Dev_9fa00* F(int i);
};
struct Root_9fa00 {
    char pad[0x54];
    Mgr_9fa00* mgr;
};
struct Sys_9fa00 {
    Mgr_9fa00* Get();
};
struct Glob_9fa00 {
    char pad[0x54];
    Sys_9fa00* sys;
};
extern Glob_9fa00* gGlob_9fa00;
extern char gFlag_9fa00;
bool Fn() {
    Mgr_9fa00* m = gGlob_9fa00->sys->Get();
    int i = 0;
    do {
        St_9fa00 s;
        Dev_9fa00* d = m->F(i);
        d->G(&s);
        if (s.a == 1 || s.c == 1 || s.b == 1 || s.d == 1) {
            gFlag_9fa00 = 1;
            return true;
        }
        i++;
    } while (i < 1);
    return false;
}
