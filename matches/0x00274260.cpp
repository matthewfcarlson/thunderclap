#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
class FileOps {
  public:
    virtual void First();
    virtual void Second();
};
// core::FileGetSizeRequest::vfunc_1 (records.h CoreFile): the file's size (field128) into the caller's word, the
// file's field14 cleared (under its IMutable lock)
int core::FileGetSizeRequest::vfunc_1() {
    *(*(int * *)&this->f_0c) = ((CoreFile*)this->f_08)->field128;
    ((FileOps*)&((CoreFile*)this->f_08)->vftableMutable)->First();
    ((CoreFile*)this->f_08)->field14 = 0;
    ((FileOps*)&((CoreFile*)this->f_08)->vftableMutable)->Second();
    return 1;
}
