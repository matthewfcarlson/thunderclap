class TrackFactoryCasterTemplate_18b080 {
  public:
    virtual void cast();
};
extern void* findTrack(int, TrackFactoryCasterTemplate_18b080*);
class Holder {
  public:
    void put(void*);
};
extern "C" void FUN_0018b080(Holder* h, int n) {
    TrackFactoryCasterTemplate_18b080 c;
    void* p = findTrack(n, &c);
    h->put(p);
}