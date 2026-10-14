typedef unsigned int u32_253f10;
struct Sub_253f10 {
    char x[16];
    float v;
};
struct Ctx_253f10 {
    char x[20];
    float s;
    float* p;
};
struct Param {
    float f;
    Ctx_253f10* c;
    char x[44];
    u32_253f10 a;
    char y[4];
    Sub_253f10* b;
};
void __cdecl Sink(u32_253f10, float);
void __stdcall Target(Param* p) {
    float x = p->b->v;
    x = x * p->f;
    x = x * *p->c->p;
    x = x * p->c->s;
    Sink(p->a, x);
}