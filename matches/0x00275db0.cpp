// Same code shape as 0x00276700 (propagated; names are from that function)
#include "decls/data/records.h"
class Sub_275db0 {
  public:
    virtual void F0();
    virtual void F1();
};
// core::File's AddRef (records.h CoreFile): the reference count under its IMutable base (+4)
class File_275db0 : public CoreFile {
  public:
    void F0();
};
void File_275db0::F0() {
    ((Sub_275db0*)&vftableMutable)->F0();
    ++refs;
    ((Sub_275db0*)&vftableMutable)->F1();
}
