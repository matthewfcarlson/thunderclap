// STATUS: equivalent (tools/equiv.py level 3: 7465 inputs, branch coverage 6/6)
// FUN_000d6c70 @ 0x000d6c70
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Clock_d6c70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual float v16(); };
struct Shape_d6c70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(float,float); };
struct Item_d6c70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); unsigned char active; };
struct Scene_d6c70 { void FUN_00294980(Shape_d6c70*); void FUN_00293ef0(); void FUN_00294080(); };
struct Gfx {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void setMode(int); virtual int getMode(); virtual void setFlag(unsigned int); virtual unsigned char getFlag();
};
  
void __cdecl FUN_0009f790(float,float,float*,float*);
struct Target_d6c70 { char pad0[4]; Scene_d6c70* scene; char pad8[4]; Item_d6c70* items[8]; Shape_d6c70* shape; void run(); };
void Target_d6c70::run() {
union { float f; unsigned int bits; unsigned char bytes[4]; } saved;
saved.f=(*(Clock_d6c70**)&DAT_0052c2a4)->v16();
float a,b; FUN_0009f790(90.0f,saved.f,&a,&b);
shape->v5(a*0.0174532924f,1.0f);
scene->FUN_00294980(shape);
DAT_004de600=22.3f;
DAT_004de600=(*(Clock_d6c70**)&DAT_0052c2a4)->v16()*DAT_004de600*0.75f;
scene->FUN_00293ef0();
saved.bytes[0]=DAT_0052c2a8->getFlag();
DAT_0052c2a8->setFlag(0);
int mode=DAT_0052c2a8->getMode();
DAT_0052c2a8->setMode(1);
for(int i=0;i<8;++i) { Item_d6c70* item=items[i]; if(item && item->active) item->v4(); }
DAT_0052c2a8->setFlag(saved.bits);
DAT_0052c2a8->setMode(mode);
scene->FUN_00294080();
}