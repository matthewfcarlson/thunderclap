// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_2 @ 0x001fe8f0
namespace math { struct Vector { float x,y,z; }; }
struct CTriggerVolumeManager { math::Vector* FUN_001fe8f0(math::Vector*, const char*); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
struct Method1 : Function {
 char padding[0x18];
 math::Vector* (CTriggerVolumeManager::*method)(math::Vector*,const char*);
 void vfunc_2(CTriggerVolumeManager* manager, const char** text, math::Vector* result);
};
void Method1::vfunc_2(CTriggerVolumeManager* manager, const char** text, math::Vector* result) {
 math::Vector temp;
 math::Vector* source = (manager->*method)(&temp, *text);
 temp = *source;
 if(result) *result = temp;
}