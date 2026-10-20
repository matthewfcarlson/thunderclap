#include "gen/pure3d.h"

namespace pure3d {
struct Child {
    int a;
    int* first;
    int* last;
    int b;
};

} // namespace pure3d
int pure3d::DrawableContainer::vfunc_16() {
    int total = 0;
    unsigned count = ((*(Child * *)&this->f_4c) - (*(Child * *)&this->f_48));
    for (unsigned i = 0; i < count; ++i)
        total += (int)((*(Child * *)&this->f_48)[i].last - (*(Child * *)&this->f_48)[i].first);
    return total;
}
