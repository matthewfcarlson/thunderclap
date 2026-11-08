#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042baa0[];
extern "C" int* FUN_002705f0();
// core::FileReadRequest (records.h CoreRequest, then buffer, count, flags): core::FileRequest's constructor 0x00274e60 first, then its own vftable
class FileReadRequest_275230 : public CoreRequest {
  public:
    void* buffer;
    unsigned int count;
    unsigned int flags;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileReadRequest_275230* Init(void*, void*, unsigned int, unsigned int);
};
FileReadRequest_275230* FileReadRequest_275230::Init(void* file, void* buffer_, unsigned int count_, unsigned int flags_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042baa0;
    buffer = buffer_;
    count = count_;
    flags = flags_;
    FUN_002705f0();
    return this;
}
