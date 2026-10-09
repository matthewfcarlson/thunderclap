typedef unsigned int u32;
struct Obj { char pad0[8]; u32* out; char padc[4]; u32* state; };
extern void helper17440(Obj*);
extern int helper194d0(Obj*, int);
int __cdecl target(Obj* p, int a) {
    if (p->state[0x4c/4] >= p->state[0x48/4]) helper17440(p);
    int r = helper194d0(p, a);
    u32* q = p->out;
    q[1] = r;
    q[0] = 7;
    p->out += 2;
    return r + 0x10;
}