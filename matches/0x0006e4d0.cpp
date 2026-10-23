extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_0049850c, DAT_0049ab78;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool test(void*) = 0;
    virtual void other() = 0;
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool test(void*);
    virtual void other();
};
} // namespace fight
bool fight::TrackFactoryCasterTemplate::test(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049ab78, 0) != 0;
}