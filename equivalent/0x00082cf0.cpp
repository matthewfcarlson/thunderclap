// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_00082cf0 @ 0x00082cf0
// FUN_00082cf0 @ 0x00082cf0
#include "decls/address.h"
#include "gen/owners.h"
struct Recipient { int FUN_001dc3b0(int); }; struct World { char pad[12]; Recipient* recipient; };   hulk_intptr owners::Owner_82cf0::FUN_00082cf0() { return DAT_004dd700->recipient->FUN_001dc3b0(value); }
