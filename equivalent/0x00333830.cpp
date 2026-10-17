// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 5/6, incomplete)
// FUN_00333830 @ 0x00333830
struct Object { char pad[0x38]; int value; void FUN_003335e0(); void FUN_00333830(float amount); };
void Object::FUN_00333830(float amount) {
    int result = (int)(amount * 255.0f);
    if (result < 0) result = 0;
    else if (result > 255) result = 255;
    value = result;
    FUN_003335e0();
}
