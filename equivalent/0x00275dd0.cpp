// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// core::File::vfunc_1 @ 0x00275dd0
#include "compat/ptr.h"
#include "decls/data/records.h"

void* __cdecl FUN_00273560(unsigned int size);
// the drive (CoreFile provider): queues a request on its thread (0x00272b60)
struct Drive_275dd0 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275dd0 { void* FUN_00275110(void* file); };
struct Lock_275dd0 { virtual void lock(); virtual void unlock(); };
struct Slots_275dd0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int flags); };
// core::File::vfunc_1 (records.h CoreFile): the last release closes the file through the drive (a close request)
// when it was opened (flag1c), else destroys it (slot 2)
struct File_275dd0 : CoreFile { void vfunc_1(); };
void File_275dd0::vfunc_1()
{
    Lock_275dd0* l = (Lock_275dd0*)&vftableMutable;
    l->lock();
    if (--refs != 0) {
        l->unlock();
        return;
    }
    if (flag1c) {
        l->unlock();
        Request_275dd0* memory = static_cast<Request_275dd0*>(FUN_00273560(0xc));
        void* request = 0;
        if (memory) {
            request = memory->FUN_00275110(this);
        }
        ((Drive_275dd0*)provider)->FUN_00272b60(request, (int)key, 0);
    } else {
        refs = 0x5dc;
        l->unlock();
        ((Slots_275dd0*)this)->vfunc_2(1);
    }
}
