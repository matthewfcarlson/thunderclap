class ConditionFactoryCasterTemplate_11a9b0 {
  public:
    virtual void cast();
};
class LocatorCaster : public ConditionFactoryCasterTemplate_11a9b0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
void* find(const char*, ConditionFactoryCasterTemplate_11a9b0*);
void func(Obj* o, const char* s) {
    LocatorCaster c;
    void* p = find(s, &c);
    o->set(p);
}