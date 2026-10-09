struct St {
    int a;
    char p1[8];
    int b;
    char p2[0x30 - 0x10];
    int c;
    char p3[0x48 - 0x34];
    int d;
    char p4[0xa4 - 0x4c];
};
struct Dev {
    void G(St* s);
};
struct Mgr {
    Dev* F(int i);
};
struct Root {
    char pad[0x54];
    Mgr* mgr;
};
struct Sys {
    Mgr* Get();
};
struct Glob {
    char pad[0x54];
    Sys* sys;
};
extern Glob* gGlob;
extern char gFlag;
bool Fn() {
    Mgr* m = gGlob->sys->Get();
    int i = 0;
    do {
        St s;
        Dev* d = m->F(i);
        d->G(&s);
        if (s.a == 1 || s.c == 1 || s.b == 1 || s.d == 1) {
            gFlag = 1;
            return true;
        }
        i++;
    } while (i < 1);
    return false;
}
