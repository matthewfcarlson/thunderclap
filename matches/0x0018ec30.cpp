typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace hulkfight {
namespace motion {
class Base {
  public:
    Base() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    int count;
    int flag;
};
class Elem {
  public:
    Elem() throw();
    int a, b;
};
class VarAssignTrack : public Base {
  public:
    VarAssignTrack() throw() : x(0), elem(), p(0), q(0), r(0), v(0) { flag = 1; }
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    Elem elem;
    int p, q, r;
    char v;
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual hulkfight::motion::VarAssignTrack* vfunc_5();
};
} // namespace fight
hulkfight::motion::VarAssignTrack* fight::Factory::vfunc_5() {
    return new hulkfight::motion::VarAssignTrack;
}
