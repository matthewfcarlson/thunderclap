typedef unsigned int U;
struct Triple { U a,b,c; };
struct Obj { char pad[0x90]; U a,b,c,d,e,f,g; };
void target(Obj* self, Triple* p, Triple* q, U value) {
    if (p) { self->a=p->a; self->b=p->b; self->c=p->c; }
    if (q) { self->d=q->a; self->e=q->b; self->f=q->c; }
    self->g=value;
}