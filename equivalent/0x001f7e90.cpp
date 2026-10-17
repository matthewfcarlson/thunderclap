// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CEffectManager,unsigned_int,char_*>::vfunc_2 @ 0x001f7e90
class CEffectManager { public: unsigned int FUN_001f7e90_callback(char *); };
class Closure1_CEffectManager_uint_charptr {
public:
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2(void *unused, char **argument, unsigned int *result);
 char padding[0x18];
 unsigned int (CEffectManager::*callback)(char *);
 CEffectManager *manager;
};
void Closure1_CEffectManager_uint_charptr::vfunc_2(void *unused, char **argument, unsigned int *result) {
 unsigned int value = (manager->*callback)(*argument);
 if (result) *result = value;
}
