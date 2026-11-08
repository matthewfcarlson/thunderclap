#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042bae0[];
extern "C" int* FUN_002705f0();
// core::FileSetPositionRequest (records.h CoreRequest, then position): core::FileRequest's constructor 0x00274e60 first, then its own vftable
class FileSetPositionRequest_275390 : public CoreRequest {
  public:
    unsigned int position;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileSetPositionRequest_275390* Init(void*, unsigned int);
};
FileSetPositionRequest_275390* FileSetPositionRequest_275390::Init(void* file, unsigned int position_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bae0;
    position = position_;
    FUN_002705f0();
    return this;
}
