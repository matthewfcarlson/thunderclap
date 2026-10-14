class Thing_4a050 {
  public:
    char pad[0x11c];
    void* p;
};
class Agent_4a050 {
  public:
    Thing_4a050* get();
};
class Arg_4a050 {
  public:
    Agent_4a050* get();
};
class Item_4a050 {
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
    virtual bool vfunc_7(Arg_4a050*);
    char pad[4];
    int mode;
    __int64 key;
};
bool CCharacterTemplateVariationCondition::vfunc_7(Arg_4a050* arg) {
    Thing_4a050* t = arg->get()->get();
    __int64 v;
    if (!t->p)
        v = 0;
    else
        v = ((Item_4a050*)t->p)->get();
    switch (mode) {
    case 0:
        return v == key;
    case 1:
        return v != key;
    default:
        return false;
    }
}