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
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};
class Param {};
} // namespace fight
namespace hulkfight {
namespace motion {
class GrappleExecuteTrack : public fight::Track, public fight::Param {
  public:
    virtual int vfunc_8(int, int);
};
} // namespace motion
} // namespace hulkfight
int execute(int);
int hulkfight::motion::GrappleExecuteTrack::vfunc_8(int a, int b) {
    return execute(b);
}