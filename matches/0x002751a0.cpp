#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042ba80[];
extern "C" int* FUN_002705f0();
// core::FileCommitRequest (records.h CoreRequest): core::FileRequest's constructor 0x00274e60 first, then its own vftable
class FileCommitRequest_2751a0 : public CoreRequest {
  public:
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileCommitRequest_2751a0* Init(void*);
};
FileCommitRequest_2751a0* FileCommitRequest_2751a0::Init(void* file) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042ba80;
    FUN_002705f0();
    return this;
}
