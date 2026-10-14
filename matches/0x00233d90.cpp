typedef unsigned char u8_233d90;
namespace fight {
class Other_233d90 {
  public:
    void f1();
};
class Branch {
  public:
    virtual void v0();
    virtual void v1();
    virtual Branch* vfunc_2(u8_233d90);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7x();
    char pad[0x14];
    Other_233d90 sub;
    void vfunc_7();
    void base_fn();
};
extern "C" char fight_Branch_vftable[];
void __cdecl thunk_FUN_00267090(Branch*);
Branch* Branch::vfunc_2(u8_233d90 param) {
    *(void**)this = (void*)fight_Branch_vftable;
    vfunc_7();
    sub.f1();
    base_fn();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fight
