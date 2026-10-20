// Same code shape as 0x00045800 (propagated; names are from that function)
class CScriptToken_fa430 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable_0fa430 : public CScriptToken_fa430 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_0fa430* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable_0fa430*);
pure3d::NonCopyable_0fa430* pure3d::NonCopyable_0fa430::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}