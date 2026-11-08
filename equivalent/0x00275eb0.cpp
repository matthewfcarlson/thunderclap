// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_3 @ 0x00275eb0
#include "compat/ptr.h"
#include "decls/data/records.h"

void* __cdecl FUN_00273560(unsigned int size);
// the drive (CoreFile provider): queues a request on its thread (0x00272b60)
struct Drive_275eb0 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275eb0 { void* FUN_00275230(void* file, void* buffer, unsigned int count, unsigned int flags); };
// core::File::vfunc_3 (records.h CoreFile): a request (0x00273560 allocates it) queued on the file's drive
struct File_275eb0 : CoreFile { void vfunc_3(void* buffer, unsigned int count, unsigned int flags); };
void File_275eb0::vfunc_3(void* buffer, unsigned int count, unsigned int flags) {
 Request_275eb0* memory = static_cast<Request_275eb0*>(FUN_00273560(0x18));
 void* request = 0;
 if (memory) request = memory->FUN_00275230(this, buffer, count, flags);
 ((Drive_275eb0*)provider)->FUN_00272b60(request, (int)key, 0);
}
