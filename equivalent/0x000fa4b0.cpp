// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_000fa4b0 @ 0x000fa4b0
#include "decls/address.h"
typedef unsigned int uint;
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern void* __cdecl FUN_00263ea0(uint);
extern void* __cdecl FUN_0008d6d0(uint);
extern uint DAT_004d9968;
extern void __fastcall __security_check_cookie(uint);
struct Name_fa4b0 { void FUN_0027b040(const char*); };
struct Reader { virtual void slot0(); virtual void slot1(); Reader* FUN_00264430(const char*,uint,uint); uint FUN_00263fb0(); void FUN_002647e0(void*,uint,uint,uint); };
struct FUN_0027b070 { FUN_0027b070(); virtual void slot0(); virtual void slot1(); uint pad4; Name_fa4b0 name; char namepad[3]; uint padc; void* data; uint size; void* cursor; uint tail; };
namespace DollyScript { struct CRawScript : FUN_0027b070 { virtual void slot0(); virtual void slot1(); }; }
struct Manager_fa4b0;
struct ManagerTable { void* slots[4]; void (__fastcall *insert)(Manager_fa4b0*,void*,unsigned __int64,DollyScript::CRawScript*); };
struct Manager_fa4b0 { ManagerTable* dispatch; };
extern Manager_fa4b0* DAT_004dd9cc;
DollyScript::CRawScript* __stdcall FUN_000fa4b0(const char* name) {
 uint cookie=DAT_004d9968;
 char buffer[256]; sprintf(buffer,"%s",name);
 Reader* mem=(Reader*)FUN_00263ea0(0x48);
 Reader* reader=mem ? mem->FUN_00264430(buffer,0,0) : 0;
 uint size=reader->FUN_00263fb0(); void* data=FUN_0008d6d0(size);
 reader->FUN_002647e0(data,size,1,1); reader->slot1();
 DollyScript::CRawScript* raw=(DollyScript::CRawScript*)FUN_00263ea0(0x20);
 if(raw) { raw->DollyScript::CRawScript::CRawScript(); raw->data=data; raw->size=size; raw->cursor=data; }
 raw->name.FUN_0027b040(name);
 ManagerTable* dispatch=DAT_004dd9cc->dispatch;
 unsigned __int64 key=FUN_002672f0(name,0,0); dispatch->insert(DAT_004dd9cc,0,key,raw);
 __security_check_cookie(cookie);
 return raw;
}