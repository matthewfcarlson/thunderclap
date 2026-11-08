#include "compat/ptr.h"
#include "decls/data/records.h"

// the drive thread's queue (0x00272fc0: the request, its priority, to the front; its result is the semaphore
// release's, which the requests return)
class B_272b60 {
  public:
    int FUN_00272fc0(void*, int, char);
};
// core::Drive (records.h CoreDrive): queues a request on its drive thread
class A_272b60 : public CoreDrive {
  public:
    int run(void*, int, int);
};
int A_272b60::run(void* a0, int a1, int a2) {
    return ((B_272b60*)driveThread)->FUN_00272fc0(a0, a1, (char)a2);
}
