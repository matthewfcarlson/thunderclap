typedef unsigned int u32;
struct Sub {
    char x[16];
    float v;
};
struct Ctx {
    char x[20];
    float s;
    float* p;
};
struct Param {
    float f;
    Ctx* c;
    char x[44];
    u32 a;
    char y[4];
    Sub* b;
};
void __cdecl Sink(u32, float);
void __stdcall Target(Param* p) {
    float x = p->b->v;
    x = x * p->f;
    x = x * *p->c->p;
    x = x * p->c->s;
    Sink(p->a, x);
}