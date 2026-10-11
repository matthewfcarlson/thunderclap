extern "C" char DAT_00528380[];
typedef unsigned long long QWORD;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(QWORD*);
}
QWORD FUN_00267aa0() {
    QWORD counter;
    XAPILIB::QueryPerformanceCounter(&counter);
    return counter / *(QWORD*)((int)DAT_00528380);
}
