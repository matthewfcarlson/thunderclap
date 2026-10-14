// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CHand2HandAgent::vfunc_7 @ 0x000ffde0
struct Display_ffde0 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual int vfunc_6(const char*, unsigned int);
 virtual void vfunc_7(); virtual void vfunc_8(); virtual int vfunc_9();
};
struct CHand2HandAgent {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(unsigned char enabled); virtual void vfunc_8(int);
 char pad04[0x54]; Display_ffde0* display; char pad5c[0x134]; unsigned int state;
};
void CHand2HandAgent::vfunc_7(unsigned char enabled) {
 if (!enabled) return;
 unsigned int color=0xffffffff;
 if(display->vfunc_9()==1) color=0xffffffff;
 else if(display->vfunc_9()==2) color=0xff0000ff;
 else if(display->vfunc_9()>=3) color=0xffff0000;
 switch(state) {
 case 0: vfunc_8(display->vfunc_6("H2H - D",color)); break;
 case 1: vfunc_8(display->vfunc_6("H2H - O",color)); break;
 case 2: vfunc_8(display->vfunc_6("H2H - I",color)); break;
 case 3: vfunc_8(display->vfunc_6("H2H - A",color)); break;
 }
}
