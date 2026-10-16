// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/8, incomplete)
// FUN_00096740 @ 0x00096740
#include "decls/address.h"
typedef unsigned int U_96740;
struct Pos_96740 { U_96740 x,y,z; };
struct Batch_96740 { char pad[8]; Pos_96740* volatile position; U_96740 unused; U_96740* volatile color; void FUN_0008ef00(); };
struct Resource_96740 { char pad[16]; U_96740 handle; };
struct Gfx {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void setMode(U_96740); virtual U_96740 getMode(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual Batch_96740* begin(U_96740,U_96740,U_96740,U_96740,U_96740); virtual void end(Batch_96740*); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void setA(U_96740); virtual U_96740 getA(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void setB(U_96740); virtual U_96740 getB();
};
struct Context { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void finish(U_96740); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void start(U_96740); };
extern unsigned char DAT_004dd8e4; extern U_96740 DAT_004dd944; extern float DAT_004dd910; extern Resource_96740* DAT_004dd930;  extern Context** DAT_0052c2ac;
void FUN_000966f0(); U_96740 FUN_00267f00();
void FUN_00096740() {
 if (!DAT_004dd8e4) return;
 FUN_000966f0();
 U_96740 now=FUN_00267f00(); U_96740 delta=now-DAT_004dd944;
 double elapsed=(int)delta; if((int)delta<0) elapsed+=4294967296.0f;
 DAT_004dd944=now; DAT_004dd910=(float)(elapsed*0.000001f);
 U_96740 a=DAT_0052c2a8->getA(); DAT_0052c2a8->setA(0);
 U_96740 b=DAT_0052c2a8->getB(); DAT_0052c2a8->setB(1);
 U_96740 m=DAT_0052c2a8->getMode(); DAT_0052c2a8->setMode(2);
 (*DAT_0052c2ac)->start(0);
 Batch_96740* batch=DAT_0052c2a8->begin(DAT_004dd930->handle,0,0x2020,6,0);
 U_96740 color;
 if (DAT_004dd910>=0.044f) color=0x80ff0000;
 else if (DAT_004dd910>0.038f) color=0x80ffff00;
 else color=0x8000ff00;
 for(int i=0;i<6;++i) {
 *batch->color=color;
 batch->position->x=(i==2 || i==4 || i==5)?0x42700000:0;
 batch->position->y=(i==0 || i==2 || i==4)?0x42700000:0;
 batch->position->z=0x3f800000;
 batch->FUN_0008ef00();
 }
 DAT_0052c2a8->end(batch);
 (*DAT_0052c2ac)->finish(0);
 DAT_0052c2a8->setA(a); DAT_0052c2a8->setB(b); DAT_0052c2a8->setMode(m);
}
