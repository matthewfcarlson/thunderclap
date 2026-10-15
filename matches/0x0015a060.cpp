typedef unsigned int size_t;
void* __cdecl operator new(size_t);
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    int count;
    int zero;
};
class ClearFightParamsHitRecordTrack : public BaseTrack {
  public:
    ClearFightParamsHitRecordTrack() throw() {
        zero = 0;
        count = 1;
    }
    virtual void a();
    virtual void b();
    virtual void c();
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class TrackFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::motion::ClearFightParamsHitRecordTrack* vfunc_5();
};
hulkfight::motion::ClearFightParamsHitRecordTrack* TrackFactoryTemplate::vfunc_5() {
    return new hulkfight::motion::ClearFightParamsHitRecordTrack;
}
} // namespace fight