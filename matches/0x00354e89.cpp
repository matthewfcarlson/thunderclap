extern "C" volatile unsigned long* KeTickCount_exref;
unsigned long FUN_00354e89(void) {
    return *KeTickCount_exref;
}