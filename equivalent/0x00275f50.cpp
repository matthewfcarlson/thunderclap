// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_5 @ 0x00275f50
#include "compat/ptr.h"
#include "decls/data/records.h"

void* __cdecl FUN_00273560(unsigned int size);
// the drive (CoreFile provider): queues a request on its thread (0x00272b60)
struct Drive_275f50 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275f50 { void* FUN_00275390(void* file, unsigned int position); };
// core::File::vfunc_5 (records.h CoreFile): a request (0x00273560 allocates it) queued on the file's drive
struct File_275f50 : CoreFile { void vfunc_5(unsigned int position); };
void File_275f50::vfunc_5(unsigned int position) {
 Request_275f50* memory = static_cast<Request_275f50*>(FUN_00273560(0x10));
 void* request = 0;
 if (memory) request = memory->FUN_00275390(this, position);
 ((Drive_275f50*)provider)->FUN_00272b60(request, (int)key, 0);
}
