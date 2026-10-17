// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00333780 @ 0x00333780
extern float DAT_003f32dc;
extern float DAT_003f32e0;
struct Object {
    char pad[0x30];
    float value;
    void FUN_003335e0();
    void FUN_00333780(float input);
};
void Object::FUN_00333780(float input) {
    if (input < DAT_003f32e0)
        value = DAT_003f32e0;
    else if (input > DAT_003f32dc)
        value = DAT_003f32dc;
    else
        value = input;
    FUN_003335e0();
}