int Helper(int a, int b, void* c, void* d, int e);

class TrackFactoryCaster {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~TrackFactoryCaster();
};

class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(int arg);
};

bool TrackFactoryCasterTemplate::vfunc_0(int arg) {
    int x = Helper(arg, 0, (void*)0x49850c, (void*)0x4a49d0, 0);
    return (x != 0) ? 1 : 0;
}
