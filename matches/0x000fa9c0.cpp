typedef unsigned int size_t;
void* operator new(size_t);
namespace DollyScript {
class CScriptToken {
  public:
    virtual void f0();
    virtual void f1();
    virtual CScriptToken* vfunc_2();
    int a, b, c;
    CScriptToken(const CScriptToken& o) : a(o.a), b(o.b), c(o.c) {}
};
class CTokenHashed : public CScriptToken {
  public:
    virtual void f0();
    virtual void f1();
    virtual CScriptToken* vfunc_2();
    int d, e;
    CTokenHashed(const CTokenHashed& o) : CScriptToken(o), d(o.d), e(o.e) {}
};
CScriptToken* CTokenHashed::vfunc_2() {
    CTokenHashed* p = new CTokenHashed(*this);
    p->a = 0;
    return p;
}
} // namespace DollyScript