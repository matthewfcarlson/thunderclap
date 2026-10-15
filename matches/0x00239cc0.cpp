typedef unsigned int size_t;
void* __cdecl operator new(size_t);
namespace fight {
class Base {
  public:
    Base() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
};
class Sub {
  public:
    Sub() throw();
};
class Tail {
  public:
    Tail() throw();
};
class ExecuteTrack : public Base {
  public:
    ExecuteTrack() throw() : fieldC(0), field10(-1.0f), field20(-1000) {}
    int fieldC;
    float field10;
    Sub sub;
    char pad2[11];
    int field20;
    Tail tail;
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual ExecuteTrack* vfunc_5();
};
ExecuteTrack* TrackFactoryTemplate::vfunc_5() {
    return new ExecuteTrack;
}
} // namespace fight