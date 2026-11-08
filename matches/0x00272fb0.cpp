// Same code shape as 0x00272fa0 (propagated; names are from that function)
// core::DriveThread's IMutable base (+0xc of records.h CoreDriveThread): leaves the device's critical section
class DriveThreadMutable_272fb0 {
  public:
    const void* vftableMutable;
    int refs;
    void* lock;
    void vfunc_0_adjc();
};
extern "C" void __cdecl FUN_0026d840(void*);
void DriveThreadMutable_272fb0::vfunc_0_adjc() {
    FUN_0026d840(lock);
}
