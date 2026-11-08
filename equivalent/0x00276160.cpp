// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// core::File::vfunc_18 @ 0x00276160
#include "compat/ptr.h"
#include "decls/data/records.h"

void* __cdecl FUN_00273560(unsigned int size);
// the drive (CoreFile provider): queues a request on its thread (0x00272b60)
struct Drive_276160 { int FUN_00272b60(void* request, int key, int front); };
extern "C" CoreThread* __cdecl FUN_0026dbb0();
struct FileCompletionRequest_276160 { void* FUN_00274ca0(void* thread, void* file, void* callback, unsigned int context); };
// core::File::vfunc_18 (records.h CoreFile): a completion request (0x00274ca0) for the calling thread, queued on
// the file's drive: the callback runs after the requests before it
struct File_276160 : CoreFile { void vfunc_18(void* callback, unsigned int context); };
void File_276160::vfunc_18(void* callback, unsigned int context) {
 FileCompletionRequest_276160* result = (FileCompletionRequest_276160*)FUN_00273560(24);
 void* value = 0;
 if (result) {
  value = result->FUN_00274ca0(FUN_0026dbb0(), this, callback, context);
 }
 ((Drive_276160*)provider)->FUN_00272b60(value, (int)key, 0);
}
