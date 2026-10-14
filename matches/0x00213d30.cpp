typedef unsigned int u32_213d30;
struct Obj_213d30 {
    char pad0[8];
    u32_213d30* out;
    char padc[4];
    u32_213d30* state;
};
extern void helper17440(Obj_213d30*);
extern int helper194d0(Obj_213d30*, int);
int __cdecl target(Obj_213d30* p, int a) {
    if (p->state[0x4c / 4] >= p->state[0x48 / 4])
        helper17440(p);
    int r = helper194d0(p, a);
    u32_213d30* q = p->out;
    q[1] = r;
    q[0] = 7;
    p->out += 2;
    return r + 0x10;
}