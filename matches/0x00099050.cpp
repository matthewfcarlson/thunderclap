class Result {
  public:
    void Finish();
};
class Aux {
  public:
    Result* Create(int);
};
class Anim {
  public:
    void A(int);
    void B(int);
};
class Holder {
  public:
    char pad[0x124];
    Anim* anim;
};
class Target {
  public:
    void Do(int);
};
class Flagged {
  public:
    char pad[8];
    char flag;
};
class Arg {
  public:
    int pad0;
    Flagged* f4;
    char pad8[0x18];
    Holder* h20;
    char pad24[0x18];
    Target* t3c;
};
class Obj {
  public:
    int pad0;
    unsigned flags;
    int pad8;
    Aux* a;
    int p10;
    int p14;
    int pad18[32];
    int p98;
    void F(Arg*);
};
void Obj::F(Arg* arg) {
    bool on = ((flags >> 2) & 1) != 0;
    if (on) {
        Result* r = a->Create(0);
        r->Finish();
        arg->t3c->Do(p98);
        arg->f4->flag = 1;
        Anim* an = arg->h20->anim;
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
