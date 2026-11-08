#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
class ObjV {
  public:
    virtual void a();
    virtual void b();
};
class Inner_273890 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual int h();
    int FUN_00272880();
};
// core::FileRequest::vfunc_4 (records.h CoreFile): the drive's slot 7, then its error into the file's field14
// (under the file's IMutable lock)
int core::FileRequest::vfunc_4() {
    Inner_273890* p = (Inner_273890*)((CoreFile*)this->f_08)->provider;
    int first = p->h();
    int second = p->FUN_00272880();
    ((ObjV*)&((CoreFile*)this->f_08)->vftableMutable)->a();
    ((CoreFile*)this->f_08)->field14 = second;
    ((ObjV*)&((CoreFile*)this->f_08)->vftableMutable)->b();
    return first;
}
