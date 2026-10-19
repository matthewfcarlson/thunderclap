class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class PropDropCaster : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
extern int __cdecl Check(void*, int, void*, void*, int);
extern char a, b;
int PropDropCaster::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}