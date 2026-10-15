typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace DollyScript {
class CScriptToken {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CScriptToken* vfunc_2();
    CScriptToken(CScriptToken*) throw();
};
class CTokenSectionEnd : public CScriptToken {
  public:
    int value;
    char pad[8];
    CTokenSectionEnd(CTokenSectionEnd* p) throw() : CScriptToken(p) {}
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CScriptToken* vfunc_2();
};
CScriptToken* CTokenSectionEnd::vfunc_2() {
    CTokenSectionEnd* p = new CTokenSectionEnd(this);
    p->value = 0;
    return p;
}
} // namespace DollyScript