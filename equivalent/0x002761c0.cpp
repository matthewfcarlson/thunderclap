// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// core::File::vfunc_19 @ 0x002761c0
#include "compat/ptr.h"
#include "decls/data/records.h"

void* __cdecl FUN_00273560(unsigned int size);
// the drive (CoreFile provider): queues a request on its thread (0x00272b60)
struct Drive_2761c0 { int FUN_00272b60(void* request, int key, int front); };
struct CompletionEventRequest_2761c0 { void* FUN_00274ba0(hulk_uintptr* signal, void* drive); };
// core::File::vfunc_19 (records.h CoreFile): a completion event request (0x00274ba0: it releases the caller's
// semaphore) queued on the file's drive
struct File_2761c0 : CoreFile { void vfunc_19(hulk_uintptr* signal); };
void File_2761c0::vfunc_19(hulk_uintptr* signal) {
    CompletionEventRequest_2761c0* value = (CompletionEventRequest_2761c0*)FUN_00273560(16);
    void* request = 0;
    if (value)
        request = value->FUN_00274ba0(signal, provider);
    ((Drive_2761c0*)provider)->FUN_00272b60(request, (int)key, 0);
}
