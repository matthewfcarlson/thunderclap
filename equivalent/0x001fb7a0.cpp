// STATUS: equivalent (tools/equiv.py level 3: 12739 inputs, branch coverage 2/2)
// CTriggerVolume::vfunc_15 @ 0x001fb7a0
// cl-flags: /GS
struct Params { unsigned kind; char text[692]; void FUN_001d1630(); };
struct Recipient_1fb7a0 { void FUN_001d3b00(const char*, Params); };
Recipient_1fb7a0* __cdecl FUN_001d4c90();
struct Argument_1fb7a0 { const char* FUN_00036d00(); };
int __cdecl sprintf(char*, const char*, ...);
void __cdecl FUN_000964a0(char*, unsigned, const char*, const char*);
struct CTriggerVolume { char pad[0x90]; char name[1]; void vfunc_15(Argument_1fb7a0*); };
void CTriggerVolume::vfunc_15(Argument_1fb7a0* argument) {
 Recipient_1fb7a0* recipient = FUN_001d4c90();
 if (recipient) {
 char eventName[256];
 sprintf(eventName, "%s_OnInside", name);
 Params params;
 params.FUN_001d1630();
 params.kind = 1;
 const char* value = argument->FUN_00036d00();
 FUN_000964a0(params.text, 64, "%s", value);
 recipient->FUN_001d3b00(eventName, params);
 }
}
