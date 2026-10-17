// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CSPManager,const_char_*,const_char_*>::vfunc_2 @ 0x001e2680
struct CSPManager {
    int FUN_001e2680(const char*);
};

struct Closure1_CSPManager {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void* unused, const char** value, int* result);
    char pad[0x18];
    int (CSPManager::*callback)(const char*);
    CSPManager* manager;
};

int Closure1_CSPManager::vfunc_2(void* unused, const char** value, int* result) {
    int answer = (manager->*callback)(*value);
    if (result) *result = answer;
    return answer;
}
