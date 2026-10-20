#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Helper_11cac0 {
    hulk_intptr First();
    void Second();
};

void hulkfight::ai::RoutAction::vfunc_4() {
    if ((*(Helper_11cac0 * *)&this->f_38)) {
        Helper_11cac0* h = (*(Helper_11cac0 * *)&this->f_38);
        h = (Helper_11cac0*)h->First();
        h->Second();
    }
}
