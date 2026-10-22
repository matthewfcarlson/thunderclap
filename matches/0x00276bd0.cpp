void* __cdecl FUN_00273560(int);
struct DriveCancelRequest_276bd0 {
    void* FUN_00275c80(void*);
};
struct DriveObject {
    int FUN_00272b60(void*, void*, int);
};
namespace core {
struct InstanceDrive {
    char pad[12];
    DriveObject* object;
    void* field10;
    int vfunc_18();
};
int InstanceDrive::vfunc_18() {
    DriveCancelRequest_276bd0* entry = (DriveCancelRequest_276bd0*)FUN_00273560(12);
    void* result = entry ? entry->FUN_00275c80(this) : 0;
    return object->FUN_00272b60(result, field10, 1);
}
} // namespace core