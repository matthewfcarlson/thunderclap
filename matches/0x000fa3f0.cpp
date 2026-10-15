typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace DollyScript {
class CScriptToken {
  public:
    CScriptToken(CScriptToken const&) throw();
    virtual void f0();
    virtual void f1();
    virtual CScriptToken* f2();
};
class CTokenSectionStart : public CScriptToken {
  public:
    int value;
    char pad[8];
    CTokenSectionStart(CTokenSectionStart const& src) throw() : CScriptToken(src) {}
    virtual CScriptToken* f2();
};
CScriptToken* CTokenSectionStart::f2() {
    CTokenSectionStart* p = new CTokenSectionStart(*this);
    p->value = 0;
    return p;
}
} // namespace DollyScript