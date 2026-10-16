#include "gen/pure3d.h"

struct Item_2a1550 {
    float key;
    void* owner;
    void* ptr;
    void* sub;
    void* extra;
};

struct Sub_2a1550 {
    char pad[0x48];
    char* begin;
    char* end;
};

struct Geom_2a1550 {
    char pad[0x40];
    Sub_2a1550* sub;
    void* extra;
};

namespace pure3d {

} // namespace pure3d
void pure3d::ShadowTraversal::vfunc_6(void* __p0, unsigned int idx, float key) { Geom_2a1550 * g = (Geom_2a1550 *)__p0;

    Sub_2a1550* s = g->sub;
    if (!s)
        return;
    if (idx >= (unsigned)((s->end - s->begin) >> 4))
        return;
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].key = key;
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].owner = g;
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].ptr = g->sub->begin + (idx << 4);
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].sub = g->sub;
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].extra = g->extra;
    (*(int *)&this->f_38)++;
}
