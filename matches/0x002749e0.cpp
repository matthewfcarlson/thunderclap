#include "gen/core.h"

struct Drive_2749e0 {
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
    Drive_2749e0* drive;
    char padding[8];
    unsigned int result;
};
namespace core {

} // namespace core
int core::DriveFileDestroyRequest::vfunc_1() {
    Drive_2749e0* drive = (*(State_2749e0 * *)&this->f_08)->drive;
    unsigned int result = drive->slot17(&(*(unsigned int *)&this->f_0c));
    unsigned int status = drive->FUN_00272880();
    (*(State_2749e0 * *)&this->f_08)->lock.acquire();
    (*(State_2749e0 * *)&this->f_08)->result = status;
    (*(State_2749e0 * *)&this->f_08)->lock.release();
    return (int)(result);
}
