class TrackFactoryCasterTemplate_122ab0 {
  public:
    virtual void fn();
};
void call(void*, TrackFactoryCasterTemplate_122ab0*);
void target(void* p) {
    TrackFactoryCasterTemplate_122ab0 c;
    call(p, &c);
}