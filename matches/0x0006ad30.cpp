class CHeadTrackerTrack {
  public:
    int vfunc_12(int);
};
class Helper_6ad30 {
  public:
    int run(CHeadTrackerTrack*, int);
};
extern void* __cdecl FUN_0008d690(unsigned int);
int CHeadTrackerTrack::vfunc_12(int param) {
    Helper_6ad30* p = (Helper_6ad30*)FUN_0008d690(0x90);
    if (p)
        return p->run(this, param);
    return 0;
}