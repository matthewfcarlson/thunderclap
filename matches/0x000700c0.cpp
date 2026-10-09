// Same code shape as 0x0006f2b0 (propagated; names are from that function)
class TrackFactoryTemplate {
  public:
    int vfunc_5();
};
class Effect {
  public:
    int Init();
};
extern void* __cdecl operator_new(unsigned int);
int TrackFactoryTemplate::vfunc_5() {
    void* p = operator_new(0x18);
    if (p)
        return ((Effect*)p)->Init();
    return 0;
}