// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,const_char_*,const_char_*,math::Vector>::vfunc_2 @ 0x001e20b0
#include "gen/global.h"

struct Vector_1e20b0 { float x, y, z; };
struct CSPManager_1e20b0 {
    void FUN_001e20b0(const char *, const char *, Vector_1e20b0);
};
struct Arguments {
    const char *first;
    const char *second;
    Vector_1e20b0 position;
};

template <> void Closure3<CSPManager, void, const char *, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * arguments = (const Arguments *)__p1;

    ((*(CSPManager_1e20b0 * *)&this->f_20)->*(*(void (CSPManager_1e20b0::**)(const char *, const char *, Vector_1e20b0))&this->f_1c))(arguments->first, arguments->second, arguments->position);
}
