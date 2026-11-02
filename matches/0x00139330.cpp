class TrackFactoryCasterTemplate_139330 {
  public:
    virtual void Cast();
};
class Track {
  public:
    void* Make(void*);
};
extern "C" void* GetTrack(void*, TrackFactoryCasterTemplate_139330*);
extern "C" void* FUN_00139330(Track* t, void* p) {
    TrackFactoryCasterTemplate_139330 c;
    void* r = GetTrack(p, &c);
    return t->Make(r);
}