// Same code shape as 0x000694c0 (propagated; names are from that function)
class CKeyPoseTrack {
  public:
    int vfunc_12(int);
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Helper_69660 {
  public:
    int FUN_000190a0(CKeyPoseTrack*, int);
};
int CKeyPoseTrack::vfunc_12(int param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_69660*)p)->FUN_000190a0(this, param);
    return 0;
}