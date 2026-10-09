struct Inner {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
struct C {
    char pad0[8];
    char* p;
    char* low;
    Inner* obj;
};
extern void __cdecl FUN_00217440(C*);
extern void __cdecl FUN_00217f20(C*, int, int);
extern int __cdecl FUN_00219430(C*, const float*, int);
extern const float zero;
void __cdecl FUN_00213c90(C* self, int n) {
    Inner* o = self->obj;
    if (o->b >= o->a)
        FUN_00217440(self);
    if (n >= 2) {
        int d = ((int)(self->p - self->low) >> 3) - 1;
        FUN_00217f20(self, n, d);
        self->p += 8 - n * 8;
        return;
    }
    if (n == 0) {
        int* q = (int*)self->p;
        int x = FUN_00219430(self, &zero, 0);
        q[1] = x;
        q[0] = 4;
        self->p += 8;
    }
}