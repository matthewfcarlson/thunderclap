// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_6 @ 0x00275fa0
#include "compat/ptr.h"
#include "decls/data/records.h"

void* __cdecl FUN_00273560(unsigned int size);
// the drive (CoreFile provider): queues a request on its thread (0x00272b60)
struct Drive_275fa0 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275fa0 { void* FUN_00275430(void* file, unsigned int* result); };
// core::File::vfunc_6 (records.h CoreFile): a request (0x00273560 allocates it) queued on the file's drive
struct File_275fa0 : CoreFile { int vfunc_6(unsigned int* result); };
int File_275fa0::vfunc_6(unsigned int* result) {
 Request_275fa0* memory = static_cast<Request_275fa0*>(FUN_00273560(0x10));
 void* request = 0;
 if (memory) request = memory->FUN_00275430(this, result);
 return ((Drive_275fa0*)provider)->FUN_00272b60(request, (int)key, 0);
}
