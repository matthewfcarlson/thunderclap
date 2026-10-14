extern "C" void FUN_002705f0();
extern "C" void FUN_00364780();
extern "C" int atexit(void (*)());

void FUN_003617e0() {
    FUN_002705f0();
    atexit(FUN_00364780);
}