#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct ObjC_11ca80 {
    char pad[0x10];
    void* next;
};
struct ObjA_11ca80 {
    char pad[0x1c];
    float value;
    ObjC_11ca80* step();
};
struct ObjB_11ca80 {
    char pad[0x10];
    void* child;
    ObjA_11ca80* get();
};
struct Child_11ca80 {
    void run(void*);
};

bool hulkfight::ai::RoutAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    ObjA_11ca80* x = (*(ObjB_11ca80 * *)&this->f_38)->get();
    ObjC_11ca80* y = x->step();
    (*(void * *)&this->f_5c) = y;
    float f = (*(ObjA_11ca80 * *)&this->f_34)->value;
    this->f_70 = f * f;
    ((Child_11ca80*)y->next)->run((char*)this + 0x28);
    return true;
}
