// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 2/2)
// FEPoseAnimation::vfunc_3 @ 0x000e1510
#include "decls/data/engine/pure3d/prop.h"

struct Renderer {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14();
 virtual void slot15(int); virtual void slot16(int); virtual void slot17(int, void*);
};
struct PoseObject {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(int,int);
};
struct Manager { Renderer* renderer; void FUN_00293da0(int,int,int); };
struct FEAnimation { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct FEPoseAnimation : FEAnimation {
 char pad[0x14-4]; char pose[0x40]; int value; char pad2[8]; PoseObject* object;
 void vfunc_3();
};
void FEPoseAnimation::vfunc_3() {
 (*(Manager**)&DAT_0052c2ac)->renderer->slot15(0);
 (*(Manager**)&DAT_0052c2ac)->renderer->slot17(0,pose);
 int v=value;
 (*(Manager**)&DAT_0052c2ac)->FUN_00293da0(v,v,v);
 if (object) object->slot8(0,0);
 (*(Manager**)&DAT_0052c2ac)->renderer->slot16(0);
}
