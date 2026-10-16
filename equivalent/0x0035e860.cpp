// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035e860 @ 0x0035e860
#include "decls/data/game/global.h"

extern unsigned __int64 FUN_0027afb0(const char *name);
void FUN_0035e860() {
    (*(unsigned __int64*)&DAT_004e2448) = FUN_0027afb0("object_class");
    (*(unsigned __int64*)&DAT_004e2450) = FUN_0027afb0("base_name");
    (*(unsigned __int64*)&DAT_004e2458) = FUN_0027afb0("material");
    (*(unsigned __int64*)&DAT_004e2460) = FUN_0027afb0("collision_type");
    (*(unsigned __int64*)&DAT_004e2468) = FUN_0027afb0("can_turn_transparent");
    (*(unsigned __int64*)&DAT_004e2470) = FUN_0027afb0("held_damage_factor");
    (*(unsigned __int64*)&DAT_004e2478) = FUN_0027afb0("collectable");
    (*(unsigned __int64*)&DAT_004e2480) = FUN_0027afb0("ers_increase");
    (*(unsigned __int64*)&DAT_004e2488) = FUN_0027afb0("target_offset");
    (*(unsigned __int64*)&DAT_004e2490) = FUN_0027afb0("cargo");
    (*(unsigned __int64*)&DAT_004e2498) = FUN_0027afb0("invulnerable_to_tank_bumper");
    (*(unsigned __int64*)&DAT_004e24a0) = FUN_0027afb0("mission_critical");
    (*(unsigned __int64*)&DAT_004e24a8) = FUN_0027afb0("draw_last");
    (*(unsigned __int64*)&DAT_004e24b0) = FUN_0027afb0("opaque_while_held");
    (*(unsigned __int64*)&DAT_004e24b8) = FUN_0027afb0("opaque_while_occluding");
}
