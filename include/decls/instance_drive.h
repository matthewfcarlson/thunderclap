// core::InstanceDrive's record (x64t10): the words its constructor 0x00277110 (src/engine/core/CementLibrary.cpp)
// writes and the drive requests read, 0x24 bytes on the 32-bit builds (0x38 natively). The two vftables are
// core::IDrive's (slot 0 adds a reference, slot 1 releases one) and core::IMutable's (slot 0 locks, slot 1 unlocks).
// Evidence per word:
//   refs     +0x08  the constructor stores 1
//   source   +0x0c  the drive the requests run on (the constructor's first argument; 0x00272b60 queues a request on it)
//   priority +0x10  the queue priority (the constructor's second argument, an int: 0x00271530's callers pass 1)
//   pending  +0x14  the requests in flight: DriveRequest's constructor 0x00275600 increments it and every drive
//                   request's destructor decrements it, under the lock; vfunc_21 0x00276cc0 tests it for zero
//   status   +0x18  the last request's result: 0x00274670 / 0x002747d0 store FUN_00272880's word under the lock,
//                   vfunc_23 0x00276d20 returns it
//   handle   +0x1c  the find handle (0x002747d0 passes its address to the drive's find)
//   active   +0x20  a find is open (0x002747d0)
// The sources that reach an InstanceDrive through a pointer take this record (or check their view's size against it:
// HULK_INSTANCE_DRIVE_SAME). gen/core.h's core::InstanceDrive declares the same words.
#ifndef HULK_DECLS_INSTANCE_DRIVE_H
#define HULK_DECLS_INSTANCE_DRIVE_H

struct HulkInstanceDrive {
    void* vftable;          // core::IDrive
    void* mutableVftable;   // core::IMutable: the lock
    int refs;
    void* source;
    int priority;
    int pending;
    int status;
    unsigned int handle;
    unsigned char active;
};
#define HULK_INSTANCE_DRIVE_CAT2(a, b) a##b
#define HULK_INSTANCE_DRIVE_CAT(a, b) HULK_INSTANCE_DRIVE_CAT2(a, b)
// a compile error on the 32-bit builds unless the record is the XBE's 0x24 bytes
typedef char hulk_instance_drive_size32_[(sizeof(void*) != 4 || sizeof(HulkInstanceDrive) == 0x24) ? 1 : -1];
// HULK_INSTANCE_DRIVE_SAME(View): a compile error on every build unless the view's size is the record's
#define HULK_INSTANCE_DRIVE_SAME(V) \
    typedef char HULK_INSTANCE_DRIVE_CAT(hulk_instance_drive_same_, __LINE__)[(sizeof(V) == sizeof(HulkInstanceDrive)) ? 1 : -1]

#endif
