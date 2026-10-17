// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CSPManager,bool,const_char_*,int,int>::vfunc_2 @ 0x001e1400
struct CSPManager { bool FUN_001e1400(const char*, int, int); };
struct Arguments { const char* text; int a; int b; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, Arguments*, bool*);
    char padding[0x18];
    bool (CSPManager::*method)(const char*, int, int);
    CSPManager* manager;
};
void Closure3::vfunc_2(void*, Arguments* args, bool* result) {
    bool value = (manager->*method)(args->text, args->a, args->b);
    if (result) *result = value;
}