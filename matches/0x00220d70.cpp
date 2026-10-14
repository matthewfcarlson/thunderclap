typedef unsigned int u32_220d70;
struct Obj_220d70 {
    char pad[0x18];
    u32_220d70 a;
    u32_220d70 b;
    char tail[4];
};
void helper(Obj_220d70*, void*, u32_220d70);
void target(Obj_220d70* p, u32_220d70 x) {
    p->b = p->a;
    helper(p, &p->tail, x);
}