// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_7 @ 0x00275ff0
#include "compat/ptr.h"
#include "decls/data/records.h"

void* __cdecl FUN_00273560(unsigned int size);
// the drive (CoreFile provider): queues a request on its thread (0x00272b60)
struct Drive_275ff0 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275ff0 { void* FUN_002754d0(void* file, unsigned int* result); };
// core::File::vfunc_7 (records.h CoreFile): a request (0x00273560 allocates it) queued on the file's drive
struct File_275ff0 : CoreFile { unsigned int vfunc_7(unsigned int* result); };
unsigned int File_275ff0::vfunc_7(unsigned int* result) {
 Request_275ff0* memory = static_cast<Request_275ff0*>(FUN_00273560(0x10));
 void* request = 0;
 if (memory) request = memory->FUN_002754d0(this, result);
 return ((Drive_275ff0*)provider)->FUN_00272b60(request, (int)key, 0);
}
