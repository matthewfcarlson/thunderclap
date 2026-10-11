// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_105 @ 0x0031d3f0
extern "C" int __cdecl sprintf(char*, const char*, ...);
namespace pure3d {
struct pddiBaseContext {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(const char*, int, int, unsigned int);
char padding[0x9c]; float frameTime;
void vfunc_105();
};
void pddiBaseContext::vfunc_105() {
char text[128];
sprintf(text, "%.2fms (%2.0ffps)", (double)frameTime, (double)(1000.0f / frameTime));
vfunc_33(text, 10, 25, 0xff141414u);
vfunc_33(text, 9, 24, 0xff969696u);
}
}
