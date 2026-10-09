class HUDOverlay { public: void Call(unsigned char, float); };
class Closure2 { public: char pad[0x1c]; void (HUDOverlay::*mFn)(unsigned char, float); HUDOverlay *mObj; void vfunc_2(void *, unsigned char *, int); };
void Closure2::vfunc_2(void *, unsigned char *args, int) { (mObj->*mFn)(args[0], *(float *)(args + 4)); }
