#include "gen/global.h"

class CGolem_fe450 {
    char pad[0xf8];
};

int CActorGolem::vfunc_6() {
    return *(int*)((char*)this + 0xf8);
}
