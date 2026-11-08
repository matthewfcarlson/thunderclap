// core::DriveThread's IMutable base (+0xc of records.h CoreDriveThread): enters the device's critical section
class DriveThreadMutable_272fa0 {
  public:
    const void* vftableMutable;
    int refs;
    void* lock;
    void vfunc_0_adjc();
};
extern "C" void __cdecl FUN_0026d850(void*);
void DriveThreadMutable_272fa0::vfunc_0_adjc() {
    FUN_0026d850(lock);
}
