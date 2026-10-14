struct Inner_213c90 {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
struct C_213c90 {
    char pad0[8];
    char* p;
    char* low;
    Inner_213c90* obj;
};
extern void __cdecl FUN_00217440(C_213c90*);
extern void __cdecl FUN_00217f20(C_213c90*, int, int);
extern int __cdecl FUN_00219430(C_213c90*, const float*, int);
extern const float zero_213c90;
void __cdecl FUN_00213c90(C_213c90* self, int n) {
    Inner_213c90* o = self->obj;
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
        int x = FUN_00219430(self, &zero_213c90, 0);
        q[1] = x;
        q[0] = 4;
        self->p += 8;
    }
}