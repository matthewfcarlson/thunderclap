// Same code shape as 0x0006a010 (propagated; names are from that function)
extern "C" void* __cdecl FUN_0008d690(int);
struct Worker {
    int go(unsigned int, unsigned int);
};
class CComboTimerTrack {
  public:
    char pad[0x14];
    unsigned int field14;
    int vfunc_12(unsigned int);
};
int CComboTimerTrack::vfunc_12(unsigned int param) {
    void* p = FUN_0008d690(0x24);
    if (p)
        return ((Worker*)p)->go(param, field14);
    return 0;
}