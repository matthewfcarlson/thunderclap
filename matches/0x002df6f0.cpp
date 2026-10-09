class Helper { public: void go(int, int, int); };
class PrimGroupSkinnedStreamed { public: char pad[0x5c]; int a; int b; int c; void vfunc_12(int); };
void PrimGroupSkinnedStreamed::vfunc_12(int arg) { ((Helper*)a)->go(arg, b, c); }