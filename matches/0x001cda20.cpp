// Same code shape as 0x0002e290 (propagated; names are from that function)
class CActorManager {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager::*MFn_1cda20)(unsigned char);
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method1 : public Function {
  public:
    char pad[0x18];
    MFn_1cda20 fn;
    void vfunc_2(CActorManager* obj, unsigned char* b, void* unused);
};
void Method1::vfunc_2(CActorManager* obj, unsigned char* b, void* unused) {
    (obj->*fn)(*b);
}
