// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// audio::SeqActionCrossFade::vfunc_2 @ 0x00255a00
struct String { char data[12]; void FUN_0023fac0(); void FUN_00240170(void*); void FUN_00240060(); const char* FUN_0023fb00(); };
struct Sound { char pad[44]; unsigned value; };
struct Bank { char pad[92]; char table[1]; };
struct Context { char pad[60]; Bank* bank; };
struct Params { char pad[28]; char name[12]; char other[1]; };
void __cdecl FUN_002613b0(void*,String*,String*);
unsigned __cdecl FUN_002673a0(const char*,int);
void* __cdecl FUN_0024a370(Bank*,unsigned*);
Sound* __cdecl FUN_0024a390(Bank*,void*);
Sound* __cdecl FUN_002495f0(void*);
Sound* __cdecl FUN_0024a9c0(Bank*,void*);
void __cdecl FUN_00247a10(Sound*);
namespace audio { struct SeqActionCrossFade { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(Context*,unsigned); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); unsigned field4; Params* params; unsigned state; Sound* current; Sound* previous; unsigned previousValue; bool FUN_00255980(Bank*,Sound*); }; }
void audio::SeqActionCrossFade::vfunc_2(Context* context,unsigned id) {
 Bank* bank=context->bank;
 String result; result.FUN_0023fac0();
 String key; key.FUN_00240170(params->name);
 FUN_002613b0(context->bank->table,&result,&key);
 key.FUN_00240060();
 id=FUN_002673a0(result.FUN_0023fb00(),0);
 void* entry=FUN_0024a370(context->bank,&id);
 if(entry) {
 previous=FUN_0024a390(bank,params->other);
 if(previous) { if(!FUN_00255980(bank,previous)) previous=0; else previousValue=previous->value; }
 current=FUN_002495f0(entry);
 if(!current) current=FUN_0024a9c0(bank,entry);
 if(current) { state=1; FUN_00247a10(current); result.FUN_00240060(); return; }
 }
 state=2; result.FUN_00240060();
}
