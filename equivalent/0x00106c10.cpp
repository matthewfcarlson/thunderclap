// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CPatrolPathManager,bool,const_char_*,bool,int>::vfunc_2 @ 0x00106c10
struct CPatrolPathManager { bool FUN_00106c10(const char*, bool, int); };
struct Arguments { const char* text; bool flag; char padding[3]; int count; };
struct Closure { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int unused, Arguments* args, bool* result); char padding[24]; bool (CPatrolPathManager::*method)(const char*, bool, int); CPatrolPathManager* object; };
void Closure::vfunc_2(int unused, Arguments* args, bool* result) { bool value = (object->*method)(args->text, args->flag, args->count); if (result) *result = value; }