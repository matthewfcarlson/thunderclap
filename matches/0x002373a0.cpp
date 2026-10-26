#include "compat/ptr.h"
#include "gen/fight.h"

extern int gPayload;
extern void(__cdecl* gUnknown)(int, int, int, int*, int*);

bool fight::OpportunityAction::vfunc_3(hulk_intptr value, hulk_intptr unused) {
    hulk_intptr adjusted = value - 1;
    this->f_40 = adjusted;
    this->f_44 = adjusted;
    if (gUnknown)
        gUnknown(this->f_1c, this->f_3c, gPayload, &this->f_40, &this->f_44);
    return true;
}
