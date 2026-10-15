typedef unsigned int size_t;
void* operator new(size_t);
namespace fight {
class Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};
class Param {};
} // namespace fight
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
namespace hulkfight {
class DebugPrintTrack;
class ActionBase {
  public:
    virtual void Run();
    char pad[24];
    ActionBase() throw();
};
class DebugPrintAction : public ActionBase {
  public:
    DebugPrintTrack* owner;
    Ref* ref;
    DebugPrintAction(DebugPrintTrack* t, Ref* r) throw() : owner(t), ref(0) {
        if (r)
            r->Add();
        if (ref)
            ref->Release();
        ref = r;
    }
    virtual void Run();
};
class DebugPrintTrack : public fight::Track, public fight::Param {
  public:
    virtual DebugPrintAction* vfunc_10(int a, int b, Ref* r);
};
DebugPrintAction* DebugPrintTrack::vfunc_10(int a, int b, Ref* r) {
    return new DebugPrintAction(this, r);
}
} // namespace hulkfight