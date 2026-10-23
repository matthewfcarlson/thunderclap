// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// hulkfight::motion::ProjectileMissile::vfunc_5 @ 0x00194ba0
#include "decls/address.h"
struct MissileManager { void FUN_001dc0d0(void *missile); };
struct World { char pad[12]; MissileManager *manager; };
namespace hulkfight { namespace motion {
struct ProjectileMissile {
    char pad[0x40];
    void *missile;
    void vfunc_5();
};
void ProjectileMissile::vfunc_5() {
    DAT_004dd700->manager->FUN_001dc0d0(missile);
}
}}