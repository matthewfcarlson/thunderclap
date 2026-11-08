#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042bac0[];
extern "C" int* FUN_002705f0();
// core::FileWriteRequest (records.h CoreRequest, then buffer, count, flags): core::FileRequest's constructor 0x00274e60 first, then its own vftable
class FileWriteRequest_2752e0 : public CoreRequest {
  public:
    void* buffer;
    unsigned int count;
    unsigned int flags;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileWriteRequest_2752e0* Init(void*, void*, unsigned int, unsigned int);
};
FileWriteRequest_2752e0* FileWriteRequest_2752e0::Init(void* file, void* buffer_, unsigned int count_, unsigned int flags_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bac0;
    buffer = buffer_;
    count = count_;
    flags = flags_;
    FUN_002705f0();
    return this;
}
