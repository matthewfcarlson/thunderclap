// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// pure3d::PointLight::vfunc_9 @ 0x002c3f70
struct LightDescription {
 unsigned char flags; char padding[3]; int type; unsigned int color;
 float value0,value1,value2;
 float directionX,directionY,directionZ;
 float positionX,positionY,positionZ;
 float attenuation0,attenuation1,attenuation2,range;
};
struct Renderer_2c3f70 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(unsigned int,LightDescription *,unsigned int);
};
extern Renderer_2c3f70 *DAT_0052c2a8;
namespace pure3d {
struct PointLight {
 char prefix[16]; unsigned char enabled,flags; char padding[2];
 unsigned int color; float value0,value1,value2; unsigned int lightIndex;
 char middle[48]; float positionX,positionY,positionZ;
 void vfunc_9(unsigned int argument);
};
void PointLight::vfunc_9(unsigned int argument) {
 if (enabled) {
 LightDescription description;
 description.flags=flags;
 description.type=1;
 description.color=color;
 description.value0=value0;
 description.value1=value1;
 description.value2=value2;
 description.directionX=0.0f;
 description.directionY=0.0f;
 description.directionZ=1.0f;
 description.positionX=positionX;
 description.positionY=positionY;
 description.positionZ=positionZ;
 description.attenuation0=0.0f;
 description.attenuation1=0.0f;
 description.attenuation2=0.0f;
 description.range=10000000.0f;
 DAT_0052c2a8->slot37(lightIndex,&description,argument);
 }
}
}
