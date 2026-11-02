class TrackFactoryCaster_10bf20 {
  public:
    virtual void f();
};
class TargetCaster : public TrackFactoryCaster_10bf20 {};
class TrackFactoryCasterTemplate_10bf20 : public TrackFactoryCaster_10bf20 {};
extern "C" int __cdecl FUN_00236ac0(const char*, TrackFactoryCaster_10bf20*);
class Factory {
  public:
    void add(int);
};
extern "C" void FUN_0010bf20(Factory* p) {
    {
        TargetCaster a;
        p->add(FUN_00236ac0("faceTarget", &a));
    }
    {
        TrackFactoryCasterTemplate_10bf20 b;
        p->add(FUN_00236ac0("faceMotion", &b));
    }
}