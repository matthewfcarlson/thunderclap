// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// fight::ParamValueEntity::vfunc_5 @ 0x00235070
#include "decls/address.h"
extern unsigned DAT_004d9968;
void __fastcall __security_check_cookie(unsigned);
struct Context { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual bool slot8(unsigned a, unsigned b, char* buffer, unsigned size); };
void __cdecl FUN_00232cc0(Context*, const char*, const char*);
namespace fight {
struct ParamValue { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(void*,void*,Context*); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void vfunc_9(); virtual void* vfunc_10(void*, unsigned __int64); virtual void slot11(void*,void*); unsigned field4; unsigned field8; unsigned fieldC; };
struct ParamValueEntity : ParamValue { virtual bool vfunc_5(void*,void*,Context*); };
bool ParamValueEntity::vfunc_5(void* arg1, void* arg2, Context* context) {
 unsigned cookie = DAT_004d9968;
 char buffer[256] = {0};
 bool success = context->slot8(field8, fieldC, buffer, 256);
 if (success) {
 unsigned __int64 key = FUN_0027b020(buffer);
 if (!key) slot11(arg1, 0);
 else {
 void* entity = vfunc_10(arg1, key);
 if (entity) slot11(arg1, entity);
 else {
 FUN_00232cc0(context, "\"%s\" could not be found in the inventory.", buffer);
 success = false;
 }
 }
 }
 __security_check_cookie(cookie);
 return success;
}
}