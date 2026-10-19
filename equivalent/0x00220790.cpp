// STATUS: equivalent (tools/equiv.py level 3: 18290 inputs, branch coverage 0/0)
// FUN_00220790 @ 0x00220790
// FUN_00220790 @ 0x00220790
struct Object { char pad[0x18]; int value; char pad2[4]; int state; };
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
void FUN_00220650(int, Object*, int, int, int, int, int);
// equiv-conv: FUN_00220790 eax
void FUN_00220790(Object* object) {
    int value = object->value;
    int state = object->state;
    FUN_00220650(state, object, value, 0xff, value, 0xff, value);
    object->state = -1;
}
