#include "decls/data/records.h"
class IMutable_276210 {
  public:
    virtual void e();
    virtual void f();
};
// core::File::vfunc_20 (records.h CoreFile): no request pending (field18), under the IMutable lock (+4)
class File_276210 : public CoreFile {
  public:
    bool vfunc_20();
};
bool File_276210::vfunc_20() {
    IMutable_276210* p = (IMutable_276210*)&vftableMutable;
    p->e();
    bool r = (field18 == 0);
    p->f();
    return r;
}
