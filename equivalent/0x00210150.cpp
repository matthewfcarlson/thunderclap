// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00210150 @ 0x00210150
struct FileSize { unsigned low; unsigned high; };
struct IoStatus { unsigned status; unsigned information; };
typedef int (__stdcall *InformationRoutine)(unsigned, IoStatus*, FileSize*, unsigned, unsigned);
extern InformationRoutine DAT_003f2c50;
extern InformationRoutine DAT_003f2c40;
namespace XAPILIB { void __stdcall XapiSetLastNTError(int status); }
int __stdcall FUN_00210150(unsigned handle)
{
    IoStatus io;
    FileSize size;
    FileSize endOfFile;
    FileSize allocation;
    int status = DAT_003f2c50(handle, &io, &size, 8, 14);
    if (status < 0) {
        XAPILIB::XapiSetLastNTError(status);
        return 0;
    }
    InformationRoutine setInformation = DAT_003f2c40;
    endOfFile = size;
    status = setInformation(handle, &io, &endOfFile, 8, 20);
    if (status >= 0) {
        allocation = size;
        status = setInformation(handle, &io, &allocation, 8, 19);
        if (status >= 0) return 1;
    }
    XAPILIB::XapiSetLastNTError(status);
    return 0;
}