class ConditionFactoryCasterTemplate_1a95f0 {
  public:
    virtual void f();
};
class Desc;
extern Desc* __cdecl lookup(const char*, ConditionFactoryCasterTemplate_1a95f0*);
class Owner {
  public:
    void use(Desc*);
};
void fun(Owner* p, const char* s) {
    ConditionFactoryCasterTemplate_1a95f0 c;
    Desc* d = lookup(s, &c);
    p->use(d);
}