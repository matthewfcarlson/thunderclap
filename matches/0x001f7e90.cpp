class CEffectManager {
  public:
    unsigned int FUN_001f7e90_callback(char*);
};
class Closure1_CEffectManager_uint_charptr {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, char**, unsigned int*);
    char padding[0x18];
    unsigned int (CEffectManager::*callback)(char*);
    CEffectManager* manager;
};
void Closure1_CEffectManager_uint_charptr::vfunc_2(void*, char** argument, unsigned int* result) {
    CEffectManager* m = manager;
    unsigned int (CEffectManager::*fn)(char*) = callback;
    unsigned int value = (m->*fn)(*argument);
    if (result)
        *result = value;
}