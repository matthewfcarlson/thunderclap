extern "C" char DAT_00528380[];
typedef unsigned long long QWORD_267aa0;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(QWORD_267aa0*);
}
QWORD_267aa0 FUN_00267aa0() {
    QWORD_267aa0 counter;
    XAPILIB::QueryPerformanceCounter(&counter);
    return counter / *(QWORD_267aa0*)((int)DAT_00528380);
}
