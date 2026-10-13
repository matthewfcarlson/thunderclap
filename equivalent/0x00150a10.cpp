// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_6 @ 0x00150a10
extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" bool __cdecl FUN_00018960(float,float,float);
extern "C" double __cdecl sqrt(double);
struct Force { char pad[0x38]; float x,y,z; };
struct Source { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Force* slot3(); };
namespace hulkfight { namespace motion {
struct CollisionSourceForceMagnitudeCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Source*, void*);
char pad[8]; unsigned comparison; float threshold;
};
bool CollisionSourceForceMagnitudeCondition::vfunc_6(void*, Source* source, void*) {
if (!FUN_00344e74(source,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
Force* force=source->slot3();
if (!force) return false;
float magnitude=(float)sqrt(force->x*force->x+force->y*force->y+force->z*force->z);
switch(comparison) {
case 0: return magnitude<threshold;
case 1: return magnitude<=threshold;
case 2: return FUN_00018960(magnitude,threshold,0.00001f);
case 3: return !FUN_00018960(magnitude,threshold,0.00001f);
case 4: return magnitude>=threshold;
case 5: return magnitude>threshold;
default: return false;
}
}
}}
