#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"

class FileIface {
  public:
    virtual void f0();
    virtual void f1();
};
// core::FileGetPositionRequest::vfunc_1 (records.h CoreFile): the file's position (field124) into the caller's
// word, the file's field14 cleared (under its IMutable lock)
int core::FileGetPositionRequest::vfunc_1() {
    *(*(int * *)&this->f_0c) = ((CoreFile*)this->f_08)->field124;
    ((FileIface*)&((CoreFile*)this->f_08)->vftableMutable)->f0();
    ((CoreFile*)this->f_08)->field14 = 0;
    ((FileIface*)&((CoreFile*)this->f_08)->vftableMutable)->f1();
    return 1;
}
