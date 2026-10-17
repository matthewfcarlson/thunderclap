// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,float>::vfunc_2 @ 0x001e2540
struct CSPManager { };
struct Arguments { const char* text; float value; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void FUN_001e2540(void* unused, Arguments* args, bool* result);
    char pad[0x18];
    bool (CSPManager::*method)(const char*, float);
    CSPManager* manager;
};
void Closure2::FUN_001e2540(void* unused, Arguments* args, bool* result) {
    bool value = (manager->*method)(args->text, args->value);
    if (result) *result = value;
}