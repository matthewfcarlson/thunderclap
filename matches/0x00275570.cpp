#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042bb40[];
extern "C" int* FUN_002705f0();
// core::FileCancelRequest (records.h CoreRequest): core::FileRequest's constructor 0x00274e60 first, then its own vftable
class FileCancelRequest_275570 : public CoreRequest {
  public:
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileCancelRequest_275570* Init(void*);
};
FileCancelRequest_275570* FileCancelRequest_275570::Init(void* file) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bb40;
    FUN_002705f0();
    return this;
}
