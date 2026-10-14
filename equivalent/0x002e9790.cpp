// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 12/12)
// FUN_002e9790 @ 0x002e9790
struct State_2e9790 { char pad[0x60]; unsigned flags; };
struct Info_2e9790 { char pad[8]; unsigned flags; };
extern "C" void __cdecl FUN_002e69a0(State_2e9790*, const char*);
extern "C" void __cdecl FUN_002e69d0(State_2e9790*, const char*);
extern "C" int __cdecl FUN_002e81e0(State_2e9790*, unsigned);
extern "C" void __cdecl FUN_002e7580(State_2e9790*, void*, unsigned);
extern "C" unsigned __cdecl FUN_002e7500(const void*);
extern "C" int __cdecl FUN_002eb2f0(State_2e9790*, Info_2e9790*, unsigned, unsigned, unsigned);
int __cdecl FUN_002e9790(State_2e9790* s, Info_2e9790* info, unsigned length) {
 if (!(s->flags & 1)) FUN_002e69a0(s, "Missing IHDR before oFFs");
 else if (s->flags & 4) { FUN_002e69d0(s, "Invalid oFFs after IDAT"); return FUN_002e81e0(s,length); }
 else if (info && (info->flags & 0x100)) { FUN_002e69d0(s, "Duplicate oFFs chunk"); return FUN_002e81e0(s,length); }
 if (length != 9) { FUN_002e69d0(s, "Incorrect oFFs chunk length"); return FUN_002e81e0(s,length); }
 unsigned char data[12];
 FUN_002e7580(s,data,9);
 int result = FUN_002e81e0(s,0);
 if (!result) {
 unsigned unit=data[8];
 unsigned y=FUN_002e7500(data+4);
 unsigned x=FUN_002e7500(data);
 return FUN_002eb2f0(s,info,x,y,unit);
 }
 return result;
}