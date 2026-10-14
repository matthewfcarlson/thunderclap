// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 18/18)
// hulkfight::motion::TargetCharacterTemplateCondition::vfunc_6 @ 0x00168a70
struct TypeInfo; extern TypeInfo DAT_00494b44; extern TypeInfo DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
extern "C" int __cdecl _atexit(void (__cdecl*)());
void __cdecl FUN_00363f70();
struct Key_168a70 { unsigned low, high; void FUN_0027af00(); void FUN_0027b040(unsigned); };
extern Key_168a70 DAT_004e12d8;
extern unsigned DAT_004e12e0;
struct Template_168a70 { unsigned __int64 FUN_000443c0(); };
struct Data_168a70 { char pad[0x11c]; Template_168a70* characterTemplate; };
struct Link_168a70 { char pad[8]; Data_168a70* data; unsigned kind; };
struct Character_168a70 { char pad[0x328]; Link_168a70* link; };
struct Context { Character_168a70* FUN_00059a30(); };
struct Input_168a70 { Context* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct TargetCharacterTemplateCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Input_168a70*, void*);
 char pad[8]; unsigned value;
};
bool TargetCharacterTemplateCondition::vfunc_6(void*, Input_168a70* input, void*) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Character_168a70* character = input->FUN_000592a0()->FUN_00059a30();
 if (!(DAT_004e12e0 & 1)) { DAT_004e12e0 |= 1; DAT_004e12d8.FUN_0027af00(); _atexit(FUN_00363f70); }
 DAT_004e12d8.FUN_0027b040(value);
 if (!character || !character->link) return false;
 Link_168a70* link = character->link;
 if (!link->data || link->kind != 1 || !link->data->characterTemplate) return false;
 unsigned lo=DAT_004e12d8.low, hi=DAT_004e12d8.high;
 unsigned __int64 result=link->data->characterTemplate->FUN_000443c0();
 return (unsigned)result==lo && (unsigned)(result>>32)==hi;
}
}}
