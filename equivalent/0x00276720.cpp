// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// core::InstanceDrive::vfunc_1 @ 0x00276720
void* __cdecl FUN_00273560(unsigned int size);

namespace core { struct InstanceDrive; }
struct Request {
    Request* FUN_00275b40(core::InstanceDrive* file);
};
struct Queue_276720 {
    void FUN_00272b60(Request* request, unsigned int context, unsigned int zero);
};
struct Lock_276720 {
    virtual void lock();
    virtual void unlock();
};

namespace core {
struct InstanceDrive {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int flags);
    Lock_276720 lock;
    int refs;
    Queue_276720* queue;
    unsigned int context;
    char pad14[12];
    char queued;
};

void InstanceDrive::vfunc_1()
{
    Lock_276720* l = &lock;
    l->lock();
    if (--refs != 0) {
        l->unlock();
        return;
    }
    if (queued) {
        queued = 0;
        l->unlock();
        Request* memory = static_cast<Request*>(FUN_00273560(0xc));
        Request* request = 0;
        if (memory) {
            request = memory->FUN_00275b40(this);
        }
        queue->FUN_00272b60(request, context, 0);
    } else {
        refs = 0x5dc;
        l->unlock();
        vfunc_2(1);
    }
}
}
