class ConditionFactoryCaster {
  public:
    virtual void A();
    virtual void B();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual void V0();
    virtual void* V1(void*);
};
class Helper {
  public:
    void Init();
    void Setup(void*);
};
extern "C" void* __cdecl alloc(unsigned int);
void* ConditionFactoryCasterTemplate::V1(void* p) {
    void* q = alloc(0x10);
    if (q) {
        ((Helper*)q)->Init();
        *(unsigned int*)q = 0x428a98;
        ((Helper*)((char*)q + 8))->Setup(p);
        return q;
    }
    return 0;
}