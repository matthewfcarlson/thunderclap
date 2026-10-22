class TrackFactoryCasterTemplate_157b10 {
  public:
    TrackFactoryCasterTemplate_157b10() {}
    virtual void cast();
};
extern "C" void __cdecl Use(void*, TrackFactoryCasterTemplate_157b10*);
void __cdecl target(void* p) {
    TrackFactoryCasterTemplate_157b10 c;
    Use(p, &c);
}