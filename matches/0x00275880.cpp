typedef unsigned int u32;
extern void __stdcall FUN_00275600(int);
extern void FUN_002705f0();
extern char* _strncpy(char*, const char*, unsigned int);
class DriveCreateDirectoryRequest {
  public:
    void* vptr;
    char pad4[8];
    char path[16];
    DriveCreateDirectoryRequest* Create(int a, char* p);
};
DriveCreateDirectoryRequest* DriveCreateDirectoryRequest::Create(int a, char* p) {
    FUN_00275600(a);
    vptr = (void*)0x42bbc0;
    FUN_002705f0();
    _strncpy(path, p, 0x10);
    path[16] = 0;
    return this;
}
