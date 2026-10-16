extern "C" void* __cdecl do_cast(void*, long, const void*, const void*, int);
extern char source_type;
extern char target_type;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class JointRelativeTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_0(void* p) {
    return do_cast(p, 0, &source_type, &target_type, 0) != 0;
}