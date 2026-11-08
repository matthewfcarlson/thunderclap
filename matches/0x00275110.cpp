#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042ba60[];
extern "C" int* FUN_002705f0();
// core::FileCloseRequest (records.h CoreRequest): core::FileRequest's constructor 0x00274e60 first, then its own vftable
class FileCloseRequest_275110 : public CoreRequest {
  public:
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileCloseRequest_275110* Init(void*);
};
FileCloseRequest_275110* FileCloseRequest_275110::Init(void* file) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042ba60;
    FUN_002705f0();
    return this;
}
