// STATUS: equivalent (tools/equiv.py level 3: 894 inputs, branch coverage 14/14)
// FUN_001f6580 @ 0x001f6580
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct Item { char pad[4]; void* handle; void FUN_001f5860(float step); };
extern "C" void __cdecl FUN_00247890(void*, int);
extern "C" void __cdecl FUN_00240bb0();
struct State { char pad0[8]; Item* items[32]; int count; char pad1[0x32c-0x8c]; unsigned int nesting; char pad2[4]; int value; void FUN_001f4610(int,int,int); void FUN_001f4140(int); void target(); };
void State::target() { unsigned int cookie=DAT_004d9968; ++nesting; if(nesting == 1) { FUN_001f4610(1,1,1); value=0; for(int i=0;i<count;++i) { void* h=items[i]->handle; if(h) FUN_00247890(h,value); } for(int j=0;j<100;++j) { FUN_001f4140(0); for(int i=0;i<count;++i) items[i]->FUN_001f5860(0.01666666753590107f); FUN_00240bb0(); } } __security_check_cookie(cookie); }
