// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001fea40
struct Vector { float x,y,z; };
struct Parameters { const char *name; Vector position; };
struct CTriggerVolumeManager { bool FUN_001fea40(const char *, Vector); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
struct Method2 : Function {
 char pad[0x18];
 bool (CTriggerVolumeManager::*callback)(const char *, Vector);
 void vfunc_2(CTriggerVolumeManager *manager, Parameters *params, bool *result);
};
void Method2::vfunc_2(CTriggerVolumeManager *manager, Parameters *params, bool *result) {
 bool value = (manager->*callback)(params->name, params->position);
 if (result) *result = value;
}