// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 12/12)
// XAPILIB::GetOverlappedResult @ 0x0020a250
struct Overlapped_20a250 {
    int status;
    unsigned int transferred;
    unsigned int offset;
    unsigned int offsetHigh;
    void* event;
};
unsigned int __stdcall FUN_0020c6f7(void* handle, unsigned int timeout);
namespace XAPILIB {
void __stdcall SetLastError(unsigned int error);
void __stdcall XapiSetLastNTError(int status);
int __stdcall GetOverlappedResult(void* handle, Overlapped_20a250* operation, unsigned int* transferred, int wait);
}
int __stdcall XAPILIB::GetOverlappedResult(void* handle, Overlapped_20a250* operation, unsigned int* transferred, int wait)
{
    if (operation->status == 0x103) {
        unsigned int result = 0x102;
        if (wait) {
            void* event = operation->event;
            if (!event) event = handle;
            result = FUN_0020c6f7(event, 0xffffffffU);
        }
        if (result == 0x102) {
            SetLastError(0x3e4);
            return 0;
        }
        if (result != 0) return 0;
    }
    *transferred = operation->transferred;
    int status = operation->status;
    if (status >= 0) return 1;
    XapiSetLastNTError(status);
    return 0;
}
