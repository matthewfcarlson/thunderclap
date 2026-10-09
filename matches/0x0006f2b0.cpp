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