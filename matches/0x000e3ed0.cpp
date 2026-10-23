#include "gen/global.h"

void TextTable::vfunc_14(int ) {
    int v = this->f_44;
    TextTable* p = (*(TextTable * *)&this->f_150);
    this->f_148 = v;
    if (p)
        p->f_44 = v;
    TextTable* a = (*(TextTable * *)&this->f_154);
    if (a && (*(TextTable * *)&this->f_158)) {
        a->f_118 = 0;
        (*(TextTable * *)&this->f_158)->f_118 = 0;
    }
}
