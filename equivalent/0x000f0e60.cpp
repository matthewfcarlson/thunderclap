// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 26/26)
// FEThingsBase::vfunc_7 @ 0x000f0e60
struct Timer { void FUN_000dff70(); };
struct Widget {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void update(float);
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void tick();
 bool FUN_000ef610(); void FUN_000e5440(int);
};
extern float (__stdcall *DAT_004de948)(int);
extern unsigned DAT_004de94c;
struct FEThingsBase {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
 char pad0[0x175c-4]; Widget* child; int blocked; int unused[2]; int state;
 char pad1[0x1818-0x1770]; Widget* animation;
 char pad2[0x1a5c-0x181c]; Widget* extras[2];
 char pad3[0x2074-0x1a64]; bool enabled; char pad4[3]; Timer timer;
 char pad5[0x2218-0x2079]; Widget* other;
};
bool FEThingsBase::vfunc_7() {
 if(blocked) return false;
 timer.FUN_000dff70(); ++DAT_004de94c;
 if(animation) animation->update(DAT_004de948(0)*1000.0f);
 if(enabled) for(int i=0;i<2;++i) if(extras[i]) extras[i]->update(DAT_004de948(0)*1000.0f);
 if(other) other->tick();
 if(child) child->tick();
 if(state==2) { if(!child || !child->FUN_000ef610()) vfunc_20(); }
 else if(state==1 && child && !child->FUN_000ef610()) {state=0; child->FUN_000e5440(0);}
 return true;
}