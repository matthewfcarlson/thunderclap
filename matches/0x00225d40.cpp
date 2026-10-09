class AnimationDriver { public: char pad[0x23c]; float value; void vfunc_9(int); };
extern float __stdcall GetValue(int);
void AnimationDriver::vfunc_9(int x) { value = GetValue(x); }