typedef unsigned int uint;
extern "C" void FUN_003479bc(uint);
void FUN_002705b0(uint param_1) {
    if (param_1) {
        FUN_003479bc(*(uint*)((char*)param_1 - 4));
    }
}