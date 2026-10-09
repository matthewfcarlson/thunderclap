struct Tgt {
    void G(int, int, int);
};
struct Ent {
    char pad[0x128];
    Tgt* t128;
    int i12c;
    Tgt* Get(int);
};
struct Holder {
    Ent* Find();
};
struct Src {
    Holder* Hld();
};
struct Cfg {
    char pad[0x10];
    int idx;
    float f;
};
class Action {
  public:
    virtual void a();
    virtual void b();
    virtual bool vfunc_2();
};
class Prop : public Action {
  public:
    virtual bool vfunc_3(int, int);
    char pad[0x18];
    Cfg* cfg;
    Src* src;
};
bool Prop::vfunc_3(int, int) {
    if (!src)
        return false;
    {
        Holder* h = src->Hld();
        Ent* e = h->Find();
        int i = cfg->idx;
        if (e) {
            Tgt* t;
            if (i < 0)
                t = e->t128;
            else if (i < 8)
                t = e->Get(i);
            else
                return false;
            if (t)
                t->G((int)cfg->f, e->i12c, 0);
        }
    }
    return false;
}
