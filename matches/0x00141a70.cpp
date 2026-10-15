extern "C" int __cdecl CheckType(void* obj, int a, int b, int c, int d);
class TrackFactoryCaster {
  public:
    virtual int Cast(void* obj);
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int Cast(void* obj);
};
int TrackFactoryCasterTemplate::Cast(void* obj) {
    return (CheckType(obj, 0, 0x49850c, 0x4ad6d8, 0) != 0);
}
