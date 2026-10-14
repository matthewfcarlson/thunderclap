class Thing {
  public:
    char pad[0x11c];
    void* p;
};
class Agent {
  public:
    Thing* get();
};
class Arg {
  public:
    Agent* get();
};
class Item {
  public:
    __int64 get();
};
class CCharacterTemplateVariationCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool vfunc_7(Arg*);
    char pad[4];
    int mode;
    __int64 key;
};
bool CCharacterTemplateVariationCondition::vfunc_7(Arg* arg) {
    Thing* t = arg->get()->get();
    __int64 v;
    if (!t->p)
        v = 0;
    else
        v = ((Item*)t->p)->get();
    switch (mode) {
    case 0:
        return v == key;
    case 1:
        return v != key;
    default:
        return false;
    }
}