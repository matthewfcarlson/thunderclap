#include "compat/ptr.h"
#include "decls/data/records.h"
// core::File::vfunc_8 (records.h CoreFile): a commit request (0x002751a0) queued on the file's drive
class File_275e70 : public CoreFile {
  public:
    void vfunc_8();
};
class FileCommitRequest_275e70 {
  public:
    void* FUN_002751a0(void*);
};
void* __cdecl FUN_00273560(unsigned int);
class Drive_275e70 {
  public:
    int FUN_00272b60(void*, int, int);
};
void File_275e70::vfunc_8() {
    FileCommitRequest_275e70* a = (FileCommitRequest_275e70*)FUN_00273560(12);
    void* x = a ? a->FUN_002751a0(this) : 0;
    ((Drive_275e70*)provider)->FUN_00272b60(x, (int)key, 0);
}
