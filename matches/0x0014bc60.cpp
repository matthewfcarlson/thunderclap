extern "C" char DAT_00413598[];
extern void* __cdecl alloc(unsigned int);
class GrappleAttachedCondition {
  public:
    GrappleAttachedCondition(int);
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[8];
    unsigned char flag;
};
class ConditionFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual GrappleAttachedCondition* vfunc_5();
};
GrappleAttachedCondition* ConditionFactoryTemplate::vfunc_5() {
    GrappleAttachedCondition* p = (GrappleAttachedCondition*)alloc(16);
    if (p) {
        p->GrappleAttachedCondition::GrappleAttachedCondition(0);
        *(unsigned long*)p = ((int)DAT_00413598);
        p->flag = 1;
        return p;
    }
    return 0;
}