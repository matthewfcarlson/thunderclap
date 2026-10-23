#include "gen/hulkfight.h"

namespace hulkfight {
namespace scenario {

}
} // namespace hulkfight
struct Result {
    char pad[4];
    int id;
};
struct Obj {
    Result* get();
};
extern "C" Obj* __cdecl cast(void*, int, void*, void*, int);
extern int desc1, desc2;
namespace hulkfight {
namespace scenario {

} // namespace scenario
} // namespace hulkfight
bool hulkfight::scenario::EventCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; void * b = (void *)__p1; int c = (int)__p2;

    Obj* p = cast(b, 0, &desc1, &desc2, 0);
    if (!p)
        return (bool)(false);
    return (bool)(p->get()->id == this->f_0c);
}
