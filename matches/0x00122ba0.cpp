class TrackFactoryCaster_122ba0 {
  public:
    virtual void cast();
};
class TrackFactoryCasterTemplate_122ba0 : public TrackFactoryCaster_122ba0 {
  public:
    virtual void cast();
};
class Receiver {
  public:
    void attach(void*);
};
void* find(void*, TrackFactoryCaster_122ba0*);
void FUN_00122ba0(Receiver* r, void* obj) {
    TrackFactoryCasterTemplate_122ba0 caster;
    r->attach(find(obj, &caster));
}