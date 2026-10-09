class SeqAction { public: virtual void vfunc_0(); virtual void vfunc_1(void*); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
class SeqActionVarPosDist : public SeqAction { public: char pad4[4]; int a; int b; int c; void vfunc_1(void*); };
struct Obj { char pad[0x38]; int value; };
void SeqActionVarPosDist::vfunc_1(void* param) { *(int*)((char*)*(int*)((char*)param + 4) + 0x38) = *(int*)((char*)this + 8) + 8; *(int*)((char*)this + 0xc) = 0; }