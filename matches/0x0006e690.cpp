struct TypeDescriptor {
    char bytes[8];
};
extern TypeDescriptor sourceType;
extern TypeDescriptor targetType;
extern "C" void* __cdecl performCast(void*, long, TypeDescriptor*, TypeDescriptor*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CStageTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return performCast(p, 0, &sourceType, &targetType, 0) != 0;
}