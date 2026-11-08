#include "decls/data/records.h"
// the drive's pending list (0x002728e0 appends)
struct Drive_2736e0 {
    void FUN_002728e0(void* request);
};
// core::FileCompletionRequest::vfunc_1 (records.h CoreCompletionRequest): runs on the drive thread: hands itself to
// the file's drive (its pending list; the queuing thread's vfunc_3 0x00272df0 calls back)
struct FileCompletionRequest_2736e0 : CoreCompletionRequest {
    int vfunc_1();
};
int FileCompletionRequest_2736e0::vfunc_1() {
    ((Drive_2736e0*)((CoreFile*)file)->provider)->FUN_002728e0(this);
    return 3;
}
