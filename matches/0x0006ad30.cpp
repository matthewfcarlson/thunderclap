class CHeadTrackerTrack { public: int vfunc_12(int); };
class Helper { public: int run(CHeadTrackerTrack*, int); };
extern void* __cdecl FUN_0008d690(unsigned int);
int CHeadTrackerTrack::vfunc_12(int param) { Helper* p = (Helper*)FUN_0008d690(0x90); if (p) return p->run(this, param); return 0; }