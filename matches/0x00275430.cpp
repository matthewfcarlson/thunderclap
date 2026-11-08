#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042bb00[];
extern "C" int* FUN_002705f0();
// core::FileGetPositionRequest (records.h CoreRequest, then result): core::FileRequest's constructor 0x00274e60 first, then its own vftable
class FileGetPositionRequest_275430 : public CoreRequest {
  public:
    unsigned int* result;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileGetPositionRequest_275430* Init(void*, unsigned int*);
};
FileGetPositionRequest_275430* FileGetPositionRequest_275430::Init(void* file, unsigned int* result_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bb00;
    result = result_;
    FUN_002705f0();
    return this;
}
