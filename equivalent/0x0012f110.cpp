// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// hulkfight::UnlockableCondition::vfunc_6 @ 0x0012f110
#include "decls/address.h"
struct Info_12f110 {
 char pad[8]; unsigned char enabled; char rest[23]; unsigned char state;
 unsigned char FUN_00091f40();
};
struct Registry_12f110 { Info_12f110* FUN_00092ad0(int); };
struct Singleton_4dd6ec { Registry_12f110* FUN_00086340(); };
extern char DAT_0049dab8, DAT_0049dafc, DAT_0049db1c;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace hulkfight {
struct UnlockableCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int,int,int);
 char pad[8]; int id; unsigned char desired;
};
bool UnlockableCondition::vfunc_6(int,int,int) {
 Registry_12f110* registry = DAT_004dd6ec->FUN_00086340();
 Info_12f110* info = registry->FUN_00092ad0(id);
 if (!info) return false;
 Info_12f110* first = (Info_12f110*)FUN_00344e74(info,0,&DAT_0049dab8,&DAT_0049dafc,0);
 if (first) return first->enabled == desired && first->state == (desired == 0);
 Info_12f110* second = (Info_12f110*)FUN_00344e74(info,0,&DAT_0049dab8,&DAT_0049db1c,0);
 if (!second) return true;
 Info_12f110* special = (Info_12f110*)FUN_00344e74(registry->FUN_00092ad0(29),0,&DAT_0049dab8,&DAT_0049dafc,0);
 if (special && special->enabled == 0 && special->state != 0) return true;
 if (second->enabled != desired) return false;
 unsigned char state = second->FUN_00091f40();
 return state == (desired == 0);
}
}