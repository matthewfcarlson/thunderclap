struct Drive {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned int slot17(void*);
    unsigned int FUN_00272880();
};
struct Lock_2749e0 {
    virtual void acquire();
    virtual void release();
};
struct State_2749e0 {
    unsigned int field0;
    Lock_2749e0 lock;
    unsigned int field8;
    Drive* drive;
    char padding[8];
    unsigned int result;
};
namespace core {
struct DriveFileDestroyRequest {
    virtual void vfunc_0();
    virtual unsigned int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    unsigned int field4;
    State_2749e0* state;
    unsigned int payload;
};
unsigned int DriveFileDestroyRequest::vfunc_1() {
    Drive* drive = state->drive;
    unsigned int result = drive->slot17(&payload);
    unsigned int status = drive->FUN_00272880();
    state->lock.acquire();
    state->result = status;
    state->lock.release();
    return result;
}
} // namespace core
