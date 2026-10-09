class Sub {
  public:
    void F(void*);
    char G(void*);
};
class Obj {
  public:
    char pad0[8];
    Sub* mSub;
    int mType;
    char pad10[0x30];
    int mA;
    int mB;
    int mC;
};
void FUN_00096a90(Obj* p, int* out) {
    if (!p) {
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
        return;
    }
    switch (p->mType) {
    case 1:
        if (!p->mSub->G(out)) {
            out[0] = p->mA;
            out[1] = p->mB;
            out[2] = p->mC;
        }
        return;
    case 5:
        p->mSub->F(out);
        return;
    default:
        out[0] = p->mA;
        out[1] = p->mB;
        out[2] = p->mC;
        return;
    }
}