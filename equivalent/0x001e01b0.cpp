// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSPManager,void,const_char_*,bool,float>::vfunc_2 @ 0x001e01b0
struct Args { const char* text; unsigned char flag; char pad[3]; float value; };
struct CSPManager { void FUN_001e01b0(const char*,unsigned char,float); };
struct Method3 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(CSPManager*,Args*,void*); char pad[24]; void (CSPManager::*callback)(const char*,unsigned char,float); };
void Method3::vfunc_2(CSPManager* manager, Args* args, void* extra) { (manager->*callback)(args->text,args->flag,args->value); }