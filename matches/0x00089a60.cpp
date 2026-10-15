struct Raw {
    unsigned short a;
    unsigned char b, c, d, e, f, g;
};
void __cdecl Fill(Raw*);
struct Out {
    unsigned short v[6];
};
void __stdcall FUN_00089a60(Out* p) {
    Raw x;
    Fill(&x);
    p->v[0] = x.a;
    p->v[1] = x.b;
    p->v[2] = x.c;
    p->v[3] = x.d;
    p->v[4] = x.e;
    p->v[5] = x.f;
}