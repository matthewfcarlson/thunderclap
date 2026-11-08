#include "compat/ptr.h"
#include "decls/data/records.h"

struct Lock_272fc0 {
    virtual void enter();
    virtual void leave();
};
struct Node {
    hulk_uintptr data;
    Node* next;
};
extern "C" int __cdecl FUN_0026d8a0(hulk_uintptr*);
// The function ends with the semaphore release, and the drives' requests return what it leaves in eax (0x00272b60's
// callers): the 64-bit builds return it (the 32-bit spelling with a result allocates registers differently)
#if defined(HULK_PTR64)
typedef int Result_272fc0;
#else
typedef void Result_272fc0;
#endif
// core::DriveThread (records.h CoreDriveThread): queues a request by priority and signals the worker; the lock is
// its IMutable base at +0xc
struct Queue_272fc0 : CoreDriveThread {
    Result_272fc0 FUN_00272fc0(Node* node, int index, char front);
};
Result_272fc0 Queue_272fc0::FUN_00272fc0(Node* node, int index, char front) {
    ((Lock_272fc0*)&vftableMutable)->enter();
    if (front) {
        if (!tails[index])
            tails[index] = node;
        node->next = (Node*)heads[index];
        heads[index] = node;
    } else {
        if (!heads[index])
            heads[index] = node;
        else
            ((Node*)tails[index])->next = node;
        node->next = 0;
        tails[index] = node;
    }
    ++count;
    ((Lock_272fc0*)&vftableMutable)->leave();
    return (Result_272fc0)FUN_0026d8a0(&ready);
}
