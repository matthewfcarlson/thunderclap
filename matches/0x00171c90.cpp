#include "compat/ptr.h"
#include "gen/hulkfight.h"

bool hulkfight::motion::TeleportAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    return (*(volatile int *)&this->f_20);
}
