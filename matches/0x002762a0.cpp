#include "decls/data/records.h"
namespace core {
class Source {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual signed char f6();
};
}
// core::File::vfunc_24 (records.h CoreFile): the file's name, unless the drive's type (slot 6) has bit 7 set
class File_2762a0 : public CoreFile {
  public:
    void* access();
};
void* File_2762a0::access() {
    if (((core::Source*)provider)->f6() & 0x80)
        return 0;
    return this->filename;
}
