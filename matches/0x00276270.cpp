#include "decls/data/records.h"
class Sub_276270 {
  public:
    virtual void f0();
    virtual void f1();
};
// core::File::vfunc_22 (records.h CoreFile): field14, under the IMutable lock (+4)
class File_276270 : public CoreFile {
  public:
    int vfunc_22();
};
int File_276270::vfunc_22() {
    Sub_276270* p = (Sub_276270*)&vftableMutable;
    p->f0();
    int r = field14;
    p->f1();
    return r;
}
