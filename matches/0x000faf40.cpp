typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace DollyScript {
class CScriptToken {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CScriptToken* vfunc_2();
    int zero;
    char pad[8];
    float value;
    CScriptToken(const CScriptToken&) throw();
};
class CTokenFloat : public CScriptToken {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CTokenFloat* vfunc_2();
    CTokenFloat(const CTokenFloat& a) throw() : CScriptToken(a) { value = a.value; }
};
CTokenFloat* CTokenFloat::vfunc_2() {
    CTokenFloat* p = new CTokenFloat(*this);
    p->zero = 0;
    return p;
}
} // namespace DollyScript