typedef unsigned int u32_213ae0;
struct Obj_213ae0 {
    char pad0[8];
    int a;
    char pad1[0x10];
    int b;
};
void helper(Obj_213ae0*, void*, void*, int, int);
void callback();
void FUN_00213ae0(Obj_213ae0* self, u32_213ae0 p2, u32_213ae0 p3) {
    u32_213ae0 local[2];
    local[0] = p2;
    local[1] = p3;
    helper(self, (void*)callback, local, self->a - self->b, 0);
}