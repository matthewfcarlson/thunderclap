#include "compat/ptr.h"
#include "decls/data/records.h"
// core::File::vfunc_17 (records.h CoreFile): a cancel request (0x00275570) queued at the front of the drive's queue
class File_276120 : public CoreFile {
  public:
    void vfunc_17();
};
void* __cdecl FUN_00273560(unsigned int);
class FileCancelRequest_276120 {
  public:
    void* FUN_00275570(void*);
};
class Drive_276120 {
  public:
    int FUN_00272b60(void*, int, int);
};
void File_276120::vfunc_17() {
    FileCancelRequest_276120* p = (FileCancelRequest_276120*)FUN_00273560(12);
    void* v = p ? p->FUN_00275570(this) : 0;
    ((Drive_276120*)provider)->FUN_00272b60(v, (int)key, 1);
}
