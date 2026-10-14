// Same code shape as 0x000694c0 (propagated; names are from that function)
class CDropTrack {
  public:
    int vfunc_12(int);
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Helper_69d70 {
  public:
    int FUN_000190a0(CDropTrack*, int);
};
int CDropTrack::vfunc_12(int param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_69d70*)p)->FUN_000190a0(this, param);
    return 0;
}