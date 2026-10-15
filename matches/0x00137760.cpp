int FUN_00344e74(void*, int, void*, int, int);
namespace hulkfight {
namespace motion {
class HoverTrack;
}
} // namespace hulkfight
struct TrackFactoryCaster {
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};
template <class T> struct TrackFactoryCasterTemplate : TrackFactoryCaster {
    virtual int vfunc_0(int a);
};
template <> int TrackFactoryCasterTemplate<hulkfight::motion::HoverTrack>::vfunc_0(int a) {
    return (FUN_00344e74((void*)a, 0, (void*)0x49850c, 0x4abd00, 0) != 0);
}
