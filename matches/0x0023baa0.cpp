#include "compat/ptr.h"
extern "C" char DAT_00428744[];
class Reader {
  public:
    virtual void Init();
};
class IFileDataReader_23baa0 {
  public:
    void* vf;
    int x;
    Reader* reader;
    IFileDataReader_23baa0(Reader* r);
};
IFileDataReader_23baa0::IFileDataReader_23baa0(Reader* r) {
    x = 0;
    vf = (void*)((hulk_intptr)DAT_00428744);
    reader = r;
    r->Init();
}