class ConditionFactoryCaster_11a9b0 {
  public:
    virtual void cast();
};
class ConditionFactoryCasterTemplate_11a9b0 : public ConditionFactoryCaster_11a9b0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
void* find(const char*, ConditionFactoryCaster_11a9b0*);
void func(Obj* o, const char* s) {
    ConditionFactoryCasterTemplate_11a9b0 c;
    void* p = find(s, &c);
    o->set(p);
}