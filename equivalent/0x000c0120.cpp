// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure7<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x000c0120
struct CFEManager { char unused; };
struct Args { const char* values[7]; };
struct Closure7 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, Args*, void*);
    char pad[0x18];
    void (CFEManager::*callback)(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
    CFEManager* manager;
};
void Closure7::vfunc_2(void*, Args* args, void*) {
    (manager->*callback)(args->values[0], args->values[1], args->values[2], args->values[3], args->values[4], args->values[5], args->values[6]);
}