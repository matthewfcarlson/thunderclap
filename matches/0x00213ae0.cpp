typedef unsigned int u32;
struct Obj {
    char pad0[8];
    int a;
    char pad1[0x10];
    int b;
};
void helper(Obj*, void*, void*, int, int);
void callback();
void FUN_00213ae0(Obj* self, u32 p2, u32 p3) {
    u32 local[2];
    local[0] = p2;
    local[1] = p3;
    helper(self, (void*)callback, local, self->a - self->b, 0);
}