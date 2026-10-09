// Same code shape as 0x0006aaf0 (propagated; names are from that function)
class CRageModeTrack {
  public:
    char pad[0x10];
    int member;
    int vfunc_12(int);
};
class Other {
  public:
    int call(int, int);
};
extern "C" Other* __cdecl FUN_0008d690(int);
int CRageModeTrack::vfunc_12(int param) {
    Other* p = FUN_0008d690(0x24);
    if (p)
        return p->call(param, member);
    return 0;
}