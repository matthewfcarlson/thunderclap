// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CActorGolem::vfunc_3 @ 0x000fe460
struct IVec3 { int x, y, z; };
struct Inner { char pad[0x40]; IVec3 v40; };
struct Sub {
    char pad0[8];
    Inner *p8;
    char pad1[0x14 - 0xc];
    float f14;
    char pad2[0x34 - 0x18];
    float f34;
    IVec3 v38;
    void FUN_000fe300(IVec3 *v, int a, int b, int c, float t);
};
class CActorGolem {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(int a1, float t);
    char pad04[0x58 - 4];
    Sub sub;
};
void CActorGolem::vfunc_3(int a1, float t)
{
    Sub *s = &sub;
    if (sub.p8 != 0) {
        IVec3 v = sub.p8->v40;
        s->FUN_000fe300(&v, 1, 0, 0, t);
        s->f34 = 0;
        s->v38 = v;
    }
    s->f14 = t + s->f14;
    s->f34 = t + s->f34;
}
