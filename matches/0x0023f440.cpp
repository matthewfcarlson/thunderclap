typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Ref {
  public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};
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
    virtual void* vfunc_10(int, int, Ref*);
};
class Param {};
class BreakPointActionBase {
  public:
    BreakPointActionBase() throw();
    virtual void v0();
    char pad[0x18];
};
class BreakPointTrack;
class BreakPointAction : public BreakPointActionBase {
  public:
    BreakPointTrack* owner;
    Ref* ref;
    BreakPointAction(BreakPointTrack* o, Ref* r) throw() : owner(o), ref(0) {
        if (r)
            r->AddRef();
        if (ref)
            ref->Release();
        ref = r;
    }
    virtual void v0();
};
class BreakPointTrack : public Track, public Param {
  public:
    virtual void* vfunc_10(int, int, Ref*);
};
void* BreakPointTrack::vfunc_10(int a, int b, Ref* r) {
    return new BreakPointAction(this, r);
}
} // namespace fight