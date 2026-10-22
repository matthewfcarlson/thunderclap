class TrackFactoryCaster_10bf20 {
  public:
    virtual void f();
};
class TargetCaster : public TrackFactoryCaster_10bf20 {};
class TrackFactoryCasterTemplate_10bf20 : public TrackFactoryCaster_10bf20 {};
extern int __cdecl lookup(const char*, TrackFactoryCaster_10bf20*);
class Factory {
  public:
    void add(int);
};
void setup(Factory* p) {
    {
        TargetCaster a;
        p->add(lookup("faceTarget", &a));
    }
    {
        TrackFactoryCasterTemplate_10bf20 b;
        p->add(lookup("faceMotion", &b));
    }
}