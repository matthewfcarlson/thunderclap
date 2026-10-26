#include "compat/ptr.h"
#include "gen/pure3d.h"

struct Arg_291d60 {
    bool more();
    void skip();
    void finish();
};
namespace pure3d {  }
void pure3d::IgnoreLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { Arg_291d60 * arg = (Arg_291d60 *)__p2;

    while (arg->more()) {
        arg->skip();
        arg->finish();
    }
    this->f_0c = 0;
}
