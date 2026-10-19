class Result_99050 {
  public:
    void Finish(int);
};
class Aux_99050 {
  public:
    Result_99050* Create();
};
class Anim_99050 {
  public:
    void A(int);
    void B(int);
};
class Holder_99050 {
  public:
    char pad[0x124];
    Anim_99050* anim;
};
class Target_99050 {
  public:
    void Do(int);
};
class Flagged_99050 {
  public:
    char pad[8];
    char flag;
};
class Arg_99050 {
  public:
    int pad0;
    Flagged_99050* f4;
    char pad8[0x18];
    Holder_99050* h20;
    char pad24[0x18];
    Target_99050* t3c;
};
class Obj_99050 {
  public:
    int pad0;
    unsigned flags;
    int pad8;
    Aux_99050* a;
    int p10;
    int p14;
    int pad18[32];
    int p98;
    void F(Arg_99050*);
};
void Obj_99050::F(Arg_99050* arg) {
    bool on = ((flags >> 2) & 1) != 0;
    if (on) {
        a->Create()->Finish(0);
        arg->t3c->Do(p98);
        arg->f4->flag = 1;
        Anim_99050* an = arg->h20->anim;
        if (an) {
            an->A(0);
            an->B(0);
        }
        unsigned f = flags & 0xfffffffb;
        p10 = p14;
        p14 = 0;
        flags = f;
    }
}
