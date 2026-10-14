// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000d6970 @ 0x000d6970
struct Device_d6970 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual float v16();
};
extern Device_d6970* DAT_0052c2a4;
extern float DAT_004de600;
extern float DAT_004de604;
struct COverlayManager {
 virtual void slot0();
 unsigned int field4, field8;
 unsigned int entries[8];
 unsigned int field2c;
 COverlayManager();
};
COverlayManager::COverlayManager() {
 field4=0; field8=0;
 for (int i=0;i<8;++i) entries[i]=0;
 field2c=0;
 DAT_004de600=22.3f;
 float scale=DAT_0052c2a4->v16();
 DAT_004de604=17.3f;
 DAT_004de600=scale*DAT_004de600*0.75f;
}