// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_2 @ 0x0007d0d0
class CAmbientsManager {};
struct AmbientArgs { const char* name; int value; unsigned char enabled; };
class Function {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method3 : public Function {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CAmbientsManager* manager, AmbientArgs* args, void* unused);
    char padding[0x1c - 4];
    void (CAmbientsManager::*callback)(const char*, int, int);
};
void Method3::vfunc_2(CAmbientsManager* manager, AmbientArgs* args, void* unused) {
    (manager->*callback)(args->name, args->value, args->enabled);
}
