// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_4 @ 0x00275f00
#include "compat/ptr.h"
#include "decls/data/records.h"

void* __cdecl FUN_00273560(unsigned int size);
// the drive (CoreFile provider): queues a request on its thread (0x00272b60)
struct Drive_275f00 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275f00 { void* FUN_002752e0(void* file, void* buffer, unsigned int count, unsigned int flags); };
// core::File::vfunc_4 (records.h CoreFile): a request (0x00273560 allocates it) queued on the file's drive
struct File_275f00 : CoreFile { int vfunc_4(void* buffer, unsigned int count, unsigned int flags); };
int File_275f00::vfunc_4(void* buffer, unsigned int count, unsigned int flags) {
 Request_275f00* memory = static_cast<Request_275f00*>(FUN_00273560(0x18));
 void* request = 0;
 if (memory) request = memory->FUN_002752e0(this, buffer, count, flags);
 return ((Drive_275f00*)provider)->FUN_00272b60(request, (int)key, 0);
}
