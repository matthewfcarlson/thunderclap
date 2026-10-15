typedef unsigned int size_t;
void* operator new(size_t);
namespace fight {
class Track {
  public:
    virtual void f();
    Track() throw();
    char pad[4];
    int count;
};
class TrackFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Track* vfunc_5();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class ClearProjectileDistanceTrack : public fight::Track {
  public:
    virtual void f();
    ClearProjectileDistanceTrack() throw();
    int unused;
    float distance;
    char flag;
};
} // namespace ai
} // namespace hulkfight
inline hulkfight::ai::ClearProjectileDistanceTrack::ClearProjectileDistanceTrack() throw()
    : unused(0), distance(-1.0f), flag(0) {}
class Factory : public fight::TrackFactory {
  public:
    virtual fight::Track* vfunc_5();
};
fight::Track* Factory::vfunc_5() {
    hulkfight::ai::ClearProjectileDistanceTrack* p = new hulkfight::ai::ClearProjectileDistanceTrack;
    if (p)
        p->count = 1;
    return p;
}