namespace fight {
class Track {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual int vfunc_8(int, int);
};
class Param {};
} // namespace fight
namespace hulkfight {
namespace motion {
class GrappleHoverTrack : public fight::Track, public fight::Param {
  public:
    virtual int vfunc_8(int, int);
};
} // namespace motion
} // namespace hulkfight
int FUN_0005a3f0(int);
int hulkfight::motion::GrappleHoverTrack::vfunc_8(int a, int b) {
    return FUN_0005a3f0(b);
}