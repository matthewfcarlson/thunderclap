// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// core::File::vfunc_1 @ 0x00275dd0
void* __cdecl FUN_00273560(unsigned int size);

namespace core { struct File; }
struct Request {
    Request* FUN_00275110(core::File* file);
};
struct Queue_275dd0 {
    void FUN_00272b60(Request* request, unsigned int context, unsigned int zero);
};
struct Lock_275dd0 {
    virtual void lock();
    virtual void unlock();
};

namespace core {
struct File {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int flags);
    Lock_275dd0 lock;
    int refs;
    Queue_275dd0* queue;
    unsigned int context;
    char pad14[8];
    char queued;
};

void File::vfunc_1()
{
    Lock_275dd0* l = &lock;
    l->lock();
    if (--refs != 0) {
        l->unlock();
        return;
    }
    if (queued) {
        l->unlock();
        Request* memory = static_cast<Request*>(FUN_00273560(0xc));
        Request* request = 0;
        if (memory) {
            request = memory->FUN_00275110(this);
        }
        queue->FUN_00272b60(request, context, 0);
    } else {
        refs = 0x5dc;
        l->unlock();
        vfunc_2(1);
    }
}
}
