extern "C" int __cdecl Check(const char*, int, const char*, const char*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class SimulationTrack {};
} // namespace motion
} // namespace hulkfight
extern const char a[], b[];
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::SimulationTrack>::vfunc_0(const char* name) {
    return Check(name, 0, a, b, 0) != 0;
}