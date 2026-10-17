// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,const_char_*,bool,float>::vfunc_2 @ 0x001e1c60
struct CSPManager { void invoke(const char*, bool, float); };
struct Arguments { const char* text; bool flag; char pad[3]; float value; };
typedef void (CSPManager::*Callback)(const char*, bool, float);
class Closure3 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, Arguments* args, int unused2);
    char pad[24];
    Callback callback;
    CSPManager* manager;
};
void Closure3::vfunc_2(int unused, Arguments* args, int unused2) {
    (manager->*callback)(args->text, args->flag, args->value);
}
