#include "decls/data/records.h"
#include "gen/core.h"

// CloseHandle (the XDK row 0x0020bbc2)
extern "C" int __stdcall FUN_0020bbc2(void*);

// closes a file of the drive (records.h CoreXboxDrive: its count of open files)
int core::XboxDrive::vfunc_10(void* __p0, int q) { void * p = (void *)__p0;

    FUN_0020bbc2(p);
    --((CoreXboxDrive*)this)->openFiles;
    return 1;
}
