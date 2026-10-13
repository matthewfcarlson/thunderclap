// STATUS: equivalent (tools/equiv.py level 3: 2982 inputs, branch coverage 14/14)
// FEThingsBase::vfunc_9 @ 0x000f1f40
extern unsigned int DAT_004de94c;
extern float (__cdecl *DAT_004de948)();
struct Child {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
};
struct FEThingsBase {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9();
 virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30();
 char pad[0x1760-4]; Child* child; char pad2[0x1830-0x1764]; int state; float amount; float elapsed;
};
bool FEThingsBase::vfunc_9() {
 ++DAT_004de94c;
 if (state == 1 || state == 2) {
 union { float f; unsigned int u; } ratio;
 ratio.f = elapsed / 0.25f;
 ratio.u &= 0x7fffffff;
 if (state == 2) {
 amount = 1.0f - ratio.f;
 if (elapsed >= 0.25f || !child) vfunc_30();
 } else {
 amount = ratio.f;
 if (elapsed >= 0.25f || !child) state = 0;
 }
 }
 float delta = DAT_004de948();
 elapsed = delta + elapsed;
 if (child) { child->slot10(); return true; }
 return false;
}
