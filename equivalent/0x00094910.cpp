// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure6<CUnlockablesManager,void,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 @ 0x00094910
class CUnlockablesManager { public: void FUN_00094910(int, const char*, const char*, const char*, const char*, int); }; 
struct CallArgs { int id; const char *a; const char *b; const char *c; const char *d; int value; };
class Closure6 { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(void*, const CallArgs*, void*); private: char pad[0x18]; void (CUnlockablesManager::*callback)(int,const char*,const char*,const char*,const char*,int); CUnlockablesManager *manager; };
void Closure6::vfunc_2(void*, const CallArgs* args, void*) { (manager->*callback)(args->id,args->a,args->b,args->c,args->d,args->value); }