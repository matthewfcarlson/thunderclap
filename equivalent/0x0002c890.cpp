// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,float,bool>::vfunc_2 @ 0x0002c890
struct CActorManager { void FUN_0002c890(const char *, float, bool); };
struct CallArguments { const char *text; float value; bool enabled; };
class Method3 {
public:
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2(CActorManager *actor, const CallArguments *arguments, int unused);
 char padding[0x18];
 void (CActorManager::*callback)(const char *, float, bool);
};
void Method3::vfunc_2(CActorManager *actor, const CallArguments *arguments, int unused)
{
 (actor->*callback)(arguments->text, arguments->value, arguments->enabled);
}