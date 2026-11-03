#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct Helper_11cac0 {
    void Second();
};

void hulkfight::ai::RoutAction::vfunc_4() {
    if ((*(Helper_11cac0 * *)&this->f_38)) {
        Helper_11cac0* h = (*(Helper_11cac0 * *)&this->f_38);
        h = (Helper_11cac0*)((owners::Object_592a0 *)h)->FUN_000592a0();
        h->Second();
    }
}
