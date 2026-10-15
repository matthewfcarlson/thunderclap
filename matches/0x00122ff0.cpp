typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl post();
class Base {
  public:
    Base() throw();
    virtual void f();
    int v;
};
class Elem {
  public:
    Elem(int) throw();
    int x, y;
};
class Obj : public Base {
  public:
    Obj(int n) throw() : elem(n) {}
    virtual void f();
    Elem elem;
};
namespace fight {
class TrackFactoryCaster {
  public:
    virtual void f0();
    virtual void* f1(int);
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual void* f1(int);
};
} // namespace fight
namespace hulkfight {
namespace ai {
class StrafeCircleHBTrack;
}
} // namespace hulkfight
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleHBTrack>::f1(int a) {
    Obj* p = new Obj(a);
    if (p)
        post();
    return p;
}
