struct Path_274720;
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
    virtual unsigned slot16(Path_274720*);
    unsigned FUN_00272880();
};
struct Lock_274720 {
    virtual void acquire();
    virtual void release();
};
struct State_274720 {
    unsigned unknown0;
    Lock_274720 lock;
    unsigned unknown8;
    Drive* drive;
    char pad10[8];
    unsigned result;
};
struct Path_274720 {
    char data[4];
};
namespace core {
struct DriveDestroyDirectoryRequest {
    virtual void vfunc_0();
    virtual unsigned vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    unsigned unknown4;
    State_274720* state;
    Path_274720 path;
};
unsigned DriveDestroyDirectoryRequest::vfunc_1() {
    Drive* drive = state->drive;
    unsigned result = drive->slot16(&path);
    unsigned status = drive->FUN_00272880();
    state->lock.acquire();
    state->result = status;
    state->lock.release();
    return result;
}
} // namespace core
