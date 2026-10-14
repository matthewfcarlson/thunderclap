struct Mat_2fd400 {
    int v[16];
    void Op();
};
struct Inner_2fd400 {
    char pad[0x19];
    char flag;
};
struct A88 {
    void F1();
    void F2();
};
struct B74 {
    char pad[0x20];
    Inner_2fd400* inner;
    char pad2[0x68 - 0x24];
    char f68;
    char f69;
    void G();
};
struct C70 {
    void H();
};

class Obj_2fd400 {
  public:
    char pad0[0x10];
    Mat_2fd400 m;
    char pad1[0x70 - 0x50];
    C70* p70;
    B74* p74;
    char pad2[0x84 - 0x78];
    char f84;
    char pad3[3];
    A88* p88;
    char pad4[0x94 - 0x8c];
    char f94;
    void Fn();
};

void Obj_2fd400::Fn() {
    if (f94)
        return;
    Mat_2fd400 saved = m;
    m.Op();
    if (p88) {
        p88->F1();
        p88->F2();
    }
    if (p74) {
        p74->G();
        B74* b = p74;
        b->inner->flag = 0;
        b->f68 = 1;
        b->f69 = 1;
    }
    if (p70)
        p70->H();
    m = saved;
    f94 = 1;
    f84 = 0;
}
