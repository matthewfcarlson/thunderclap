typedef unsigned int U_2485c0;
struct Triple_2485c0 {
    U_2485c0 a, b, c;
};
struct Obj_2485c0 {
    char pad[0x90];
    U_2485c0 a, b, c, d, e, f, g;
};
void target(Obj_2485c0* self, Triple_2485c0* p, Triple_2485c0* q, U_2485c0 value) {
    if (p) {
        self->a = p->a;
        self->b = p->b;
        self->c = p->c;
    }
    if (q) {
        self->d = q->a;
        self->e = q->b;
        self->f = q->c;
    }
    self->g = value;
}