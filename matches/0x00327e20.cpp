extern void* vD[];
extern void* vB[];
extern "C" void _ReadWriteBarrier();
extern "C" void thunk_FUN_00267090(void*) throw();
namespace pure3d { class pddiBaseShader; }
extern pure3d::pddiBaseShader* g_cur_327e20;
namespace pure3d { class pddiBaseShader {
  public:
    void* vptr;
    pddiBaseShader* vfunc_3(unsigned char f) throw();
    void Fini() throw();
}; }
pure3d::pddiBaseShader* pure3d::pddiBaseShader::vfunc_3(unsigned char f) throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if (g_cur_327e20 == this)
        g_cur_327e20 = 0;
    vptr = vB;
    Fini();
    if (f & 1)
        thunk_FUN_00267090(this);
    return this;
}
