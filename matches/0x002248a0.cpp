#include "decls/data/engine/choreo2.h"
// data: gCount_2248a0 = DAT_004e5aac

#include "compat/ptr.h"
extern "C" char DAT_004272f0[];
class JointDriver_2248a0 {
  public:
    void Init();
};
class Part_2248a0 {
  public:
    void Init();
};
class JointDriver {
  public:
    int* vptr;
    char pad[12];
    int mValue;
    int mState;
    char pad2[4];
    JointDriver* Init();
};
JointDriver* JointDriver::Init() {
    ((JointDriver_2248a0*)this)->Init();
    this->vptr = (int*)((hulk_intptr)DAT_004272f0);
    mValue = 0;
    mState = 3;
    ((Part_2248a0*)((char*)this + 0x18))->Init();
    ++(*(int*)&DAT_004e5aac);
    if ((*(int*)&DAT_004e5aac) <= (*(int*)&DAT_004e5ab0)) {
    } else
        (*(int*)&DAT_004e5ab0) = (*(int*)&DAT_004e5aac);
    return this;
}