#include "gen/owners.h"
struct Sub_89e10;
struct Root_89e10 {
    char pad[0x54];
    Sub_89e10* sub;
};
extern Root_89e10* g_root;
int fmt(char* buf, int n, const char* f, ...);
struct R_89e10 {
    void Go();
};
struct Sub_89e10 {
    R_89e10* Get();
};
void owners::W_89e10::FUN_00089e10() {
    Sub_89e10* s = g_root->sub;
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
