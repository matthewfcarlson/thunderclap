struct Sub;
struct Root {
    char pad[0x54];
    Sub* sub;
};
extern Root* g_root;
int fmt(char* buf, int n, const char* f, int a, int b);
struct R {
    void Go();
};
struct Sub {
    R* Get();
};
struct W {
    char pad[0x80];
    int i80, i84;
    char pad2[0xa8 - 0x88];
    int ia8, iac;
    char pad3[0xd0 - 0xb0];
    int d0, d4;
    char d8[0x20];
    void Fn();
    void P();
};
void W::Fn() {
    Sub* s = g_root->sub;
    d0 = 0;
    d4 = 1;
    fmt(d8, 0x20, "c%02dm%02d", 0, 1);
    int* q = &i80;
    i84 = -1;
    *q = -1;
    iac = -1;
    ia8 = -1;
    P();
    s->Get()->Go();
}
