struct Job {
    char pad0[8];
    char inner[0x30];
    unsigned char active;
    char pad1[11];
    int threadId;
    int handle;
};
extern "C" void __cdecl FUN_0026d940(Job*);
extern "C" void __cdecl FUN_0026d7a0(void*);
extern "C" int __cdecl FUN_0020c14b();
extern "C" void __stdcall FUN_0020bbc2(int);
extern "C" void __stdcall FUN_0020c6f7(int, int);
namespace XAPILIB {
void __stdcall ExitThread(int);
}
extern "C" char DAT_0052a188;
extern "C" void(__stdcall* DAT_003f2c8c)(void*);
extern "C" void(__stdcall* DAT_003f2c88)(void*);
void __cdecl FUN_0026dad0(Job* job) {
    FUN_0026d940(job);
    DAT_003f2c8c(&DAT_0052a188);
    if (job->active) {
        if (job->threadId == FUN_0020c14b()) {
            FUN_0026d7a0(job->inner);
            DAT_003f2c88(&DAT_0052a188);
            FUN_0020bbc2(job->handle);
            XAPILIB::ExitThread(0);
        }
        FUN_0026d7a0(job->inner);
        DAT_003f2c88(&DAT_0052a188);
        return;
    }
    FUN_0026d7a0(job->inner);
    DAT_003f2c88(&DAT_0052a188);
    FUN_0020c6f7(job->handle, -1);
    FUN_0020bbc2(job->handle);
}