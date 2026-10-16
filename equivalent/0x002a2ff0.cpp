// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// pure3d::DirectionalLight::vfunc_9 @ 0x002a2ff0
#include "decls/address.h"
struct LightData_2a2ff0 {
 unsigned char kind; char padding[3];
 unsigned int zero0; unsigned int color;
 float position[3]; float direction[3];
 float intensity; float extra[5]; float range;
};
struct Gfx {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36();
 virtual void slot37(unsigned int, LightData_2a2ff0*, unsigned int);
};
namespace pure3d {
struct DirectionalLight {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(unsigned int);
 char pad04[12]; unsigned char enabled; unsigned char kind; char pad12[2]; unsigned int color; char pad18[12]; unsigned int handle; char pad28[48]; float direction[3];
};
void DirectionalLight::vfunc_9(unsigned int index) {
 if (enabled) {
 LightData_2a2ff0 data;
 data.kind=kind; data.zero0=0; data.color=color;
 data.position[0]=0.0f; data.position[1]=0.0f; data.position[2]=0.0f;
 data.direction[0]=direction[0]; data.direction[1]=direction[1]; data.direction[2]=direction[2];
 data.intensity=1.0f;
 data.extra[0]=0.0f; data.extra[1]=0.0f; data.extra[2]=0.0f; data.extra[3]=0.0f; data.extra[4]=0.0f;
 data.range=10000000.0f;
 DAT_0052c2a8->slot37(handle, &data, index);
 }
}
}
