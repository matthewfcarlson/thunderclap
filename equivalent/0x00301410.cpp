// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00301410 @ 0x00301410
#include "decls/data/game/hulkfight.h"

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int value);
};
struct Object {
    char padding[0x14];
    float x, y, z;
    void FUN_00317610(int a, Receiver* receiver, int result, int value);
    void FUN_00301410(int a, Receiver* receiver, int value);
};
void Object::FUN_00301410(int a, Receiver* receiver, int value) {
    x *= (*(float*)&DAT_003f3388);
    y *= (*(float*)&DAT_003f3388);
    z *= (*(float*)&DAT_003f3388);
    int result = receiver->slot4(value);
    FUN_00317610(a, receiver, result, value);
}