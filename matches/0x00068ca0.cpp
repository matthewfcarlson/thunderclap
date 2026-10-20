// Same code shape as 0x00049c80 (propagated; names are from that function)
class Track_68ca0 {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
} // namespace fight
class CTrack_68ca0 : public Track_68ca0, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int CTrack_68ca0::vfunc_0(int) {
    return 0;
}
