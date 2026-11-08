// STATUS: equivalent (tools/equiv.py level 3: 19878 inputs, branch coverage 8/8)
// FUN_00273140 @ 0x00273140
#include "decls/data/records.h"

struct Lock_273140 {
    virtual void acquire();
    virtual void release();
};
struct Node {
    hulk_uintptr value;
    Node* next;
};
// core::DriveThread (records.h CoreDriveThread): pops the first request by priority; the lock is its IMutable base
struct Queue_273140 : CoreDriveThread {
    Node* FUN_00273140(unsigned int* index);
};
Node* Queue_273140::FUN_00273140(unsigned int* index) {
    Lock_273140* lock = (Lock_273140*)&vftableMutable;
    lock->acquire();
    Node* result = 0;
    for (unsigned int i = 0; i < 3; ++i) {
        if (heads[i]) {
            result = (Node*)heads[i];
            if (result == tails[i]) tails[i] = 0;
            heads[i] = result->next;
            result->next = 0;
            if (index) *index = i;
            break;
        }
    }
    lock->release();
    return result;
}
