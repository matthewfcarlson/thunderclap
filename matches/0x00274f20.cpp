#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042ba00[];
extern "C" int* FUN_002705f0();
// core::FileOpenRequest (records.h CoreRequest, then the open's mode and flag): core::FileRequest's constructor
// 0x00274e60 first
class FileOpenRequest : public CoreRequest {
  public:
    int field;
    unsigned char flag;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileOpenRequest* target(void*, int, unsigned char);
};
FileOpenRequest* FileOpenRequest::target(void* a, int b, unsigned char c) {
    FUN_00274e60((hulk_uintptr)a);
    vftable = DAT_0042ba00;
    field = b;
    flag = c;
    FUN_002705f0();
    return this;
}
