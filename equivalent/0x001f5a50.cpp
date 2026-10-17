// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_2 @ 0x001f5a50
struct CSoundVoiceManager { void FUN_001f5a50(unsigned, unsigned, unsigned); };
struct Args { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int, Args *, int); };
struct Closure3 : Function {
 char pad[0x1c-4];
 void (CSoundVoiceManager::*method)(unsigned,unsigned,unsigned);
 CSoundVoiceManager *object;
 virtual void vfunc_2(int unused, Args *args, int unused2);
};
void Closure3::vfunc_2(int unused, Args *args, int unused2) {
 (object->*method)((reinterpret_cast<unsigned>(args) & ~255u) | args->first,args->second,args->third);
}
