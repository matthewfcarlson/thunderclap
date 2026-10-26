#include "decls/data/engine/pure3d.h"
// data: g_cur_327e20 = DAT_005555bc

extern void* vD[];
extern void* vB[];
extern "C" void _ReadWriteBarrier();
extern "C" void thunk_FUN_00267090(void*) throw();
namespace pure3d { class pddiBaseShader; }
namespace pure3d { class pddiBaseShader {
  public:
    void* vptr;
    pddiBaseShader* vfunc_3(unsigned char f) throw();
    void Fini() throw();
}; }
pure3d::pddiBaseShader* pure3d::pddiBaseShader::vfunc_3(unsigned char f) throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if ((*(pure3d::pddiBaseShader**)&DAT_005555bc) == this)
        (*(pure3d::pddiBaseShader**)&DAT_005555bc) = 0;
    vptr = vB;
    Fini();
    if (f & 1)
        thunk_FUN_00267090(this);
    return this;
}
