#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042bb20[];
extern "C" int* FUN_002705f0();
// core::FileGetSizeRequest (records.h CoreRequest, then result): core::FileRequest's constructor 0x00274e60 first, then its own vftable
class FileGetSizeRequest_2754d0 : public CoreRequest {
  public:
    unsigned int* result;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileGetSizeRequest_2754d0* Init(void*, unsigned int*);
};
FileGetSizeRequest_2754d0* FileGetSizeRequest_2754d0::Init(void* file, unsigned int* result_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bb20;
    result = result_;
    FUN_002705f0();
    return this;
}
