namespace XAPILIB { unsigned long __stdcall GetLastError(); }
unsigned long __stdcall FUN_002101d4(void* handle, unsigned long offset, unsigned long a, unsigned long whence);
void __stdcall FUN_00210150(void* handle);
int __stdcall FUN_0021007a(void* handle, void* buffer, unsigned long count, void* output, unsigned long overlapped);
unsigned long __stdcall FUN_002109b6(void* handle, unsigned long a);

struct XboxDrive {
    char pad[0xb4];
    unsigned long error;
    char pad2[4];
    unsigned char flags;
    unsigned long FUN_0026f3e0(unsigned long err);
    int FUN_0026f990(void* handle, unsigned long a2, unsigned long a3, unsigned long offset, void* buffer,
                     unsigned long count, void* output, unsigned long* position, unsigned long a9);
};

int XboxDrive::FUN_0026f990(void* handle, unsigned long a2, unsigned long a3, unsigned long offset, void* buffer,
                            unsigned long count, void* output, unsigned long* position, unsigned long a9)
{
    if (!(flags & 1))
        return 0;
    unsigned long end = offset + count;
    if (end > *position) {
        FUN_002101d4(handle, end, 0, 0);
        FUN_00210150(handle);
    }
    if (FUN_002101d4(handle, offset, 0, 0) == offset) {
        if (FUN_0021007a(handle, buffer, count, output, 0)) {
            *position = FUN_002109b6(handle, 0);
            error = 0;
            return 1;
        }
    }
    error = FUN_0026f3e0(XAPILIB::GetLastError());
    return 0;
}
