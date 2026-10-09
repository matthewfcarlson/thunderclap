// Same code shape as 0x00354e89 (propagated; names are from that function)
extern "C" volatile unsigned long* KeTickCount_exref;
unsigned long FUN_00354e89(void) {
    return *KeTickCount_exref;
}