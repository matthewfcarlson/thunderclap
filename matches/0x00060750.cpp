extern float zeroValue;
class CEffectTrack { public: char pad0[0x0c]; float f0c; float f10; char pad[0x3c]; unsigned char flag; float vfunc_7(); };
float CEffectTrack::vfunc_7() { if (flag) return f10 - f0c; return zeroValue; }