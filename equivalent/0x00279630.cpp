// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 68/84, incomplete)
// core::XboxSaveDrive::vfunc_9 @ 0x00279630
typedef unsigned int U;
extern "C" unsigned int strlen(const char *);
extern "C" char *strcpy(char *, const char *);
extern const char *DAT_004ce26c;
extern const char *DAT_004ce270;
extern U *DAT_0052c270;
extern U DAT_0052c27c;
extern void __cdecl FUN_0026b800(char *initial, int a, U b, int c, int d, int e, int f);
extern int __stdcall FUN_0035618d(const char *drive, const char *initial, int flags, int a, char *path, int size);
extern int __stdcall FUN_003563f0(const char *drive, const char *initial);
extern int __stdcall FUN_00208b9c(const char *drive, void *freeAvail, void *total, void *totalFree);
extern U __stdcall FUN_002109f1(const char *path, U access, U share, U security, U disposition, U attrs, U tmpl);
extern U __stdcall FUN_002101d4(U handle, U distance, U high, U method);
extern int __stdcall FUN_00210150(U handle);
extern int __stdcall FUN_0021007a(U handle, const void *buffer, U count, U *written, U overlapped);
extern void __stdcall FUN_0020bbc2(U handle);
extern U __cdecl FUN_00278150(U size);
namespace XAPILIB { extern U __stdcall GetLastError(); }

struct Blob {
    char *data;
    U size;
};
struct ULarge {
    U low;
    U high;
};
// The function's stack locals, laid out in the order the original keeps them.
struct Frame {
    char pad[7];
    char changed;
    char drive[4];
    U written;
    U access;
    U disposition;
    ULarge freeAvail;
    ULarge totalFree;
    ULarge total;
    char path[0x104];
    char initial[0x104];
};

namespace core {
struct XboxSaveDrive {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual U vfunc_5(Blob *blob, U size);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual int vfunc_9(U a1, U mode, bool writing, Blob *blob, U size, U *outHandle, U *outAmount);
    char pad[0xb0];
    U error;
    char pad2[0x10];
    U count;
    char pad3[0x12];
    char letter;
    char pad4;
    U handles[4];
    bool FUN_002788c0();
    U FUN_002787c0(U);
    char FUN_002789e0(U);
    char FUN_00278ef0(U, U, bool);
    char FUN_00278a00(U, U *);
    char FUN_00279490(U, U);
};
}

int core::XboxSaveDrive::vfunc_9(U a1, U mode, bool writing, Blob *blob, U size, U *outHandle, U *outAmount)
{
    if (!FUN_002788c0())
        return 0;
    Frame f;
    f.drive[0] = letter;
    f.drive[1] = ':';
    f.drive[2] = '\\';
    f.drive[3] = 0;
    FUN_0026b800(f.initial, 2, a1, 1, 0, 0x202, 0);
    f.access = writing ? 0xc0000000 : 0x80000000;
    f.disposition = writing ? 3 : 1;
    int status = FUN_0035618d(f.drive, f.initial, 3, 0, f.path, 0x104);
    if (status != 0 && status != 3) {
        error = FUN_002787c0(status);
        return 0;
    }
    U pathLen = strlen(f.path);
    f.changed = (status == 3) || (mode != 0 && mode != 1);
    if (mode == 3) {
        if (status != 3) {
            U e = FUN_002787c0(FUN_003563f0(f.drive, f.initial));
            error = e;
            if (e)
                return 0;
        }
    } else if (mode == 0 && status == 3) {
        FUN_002789e0(status);
        return 0;
    }
    if (f.changed) {
        if (!FUN_00208b9c(f.drive, &f.freeAvail, &f.total, &f.totalFree))
            goto fail;
        U available = f.freeAvail.high ? 0xffffffff : f.freeAvail.low;
        if (available < vfunc_5(blob, size)) {
            error = 7;
            return 0;
        }
        if (!FUN_002789e0(FUN_0035618d(f.drive, f.initial, 1, 0, f.path, 0x104)))
            return 0;
        pathLen = strlen(f.path);
        if (blob->data) {
            strcpy(f.path + pathLen, DAT_004ce26c);
            U h = FUN_002109f1(f.path, 0xc0000000, 3, 0, 2, 0x80, 0);
            if (h == (U)-1)
                goto fail;
            f.written = 0;
            if (FUN_002101d4(h, blob->size, 0, 0) != blob->size || !FUN_00210150(h) ||
                FUN_002101d4(h, 0, 0, 0) != 0 ||
                !FUN_0021007a(h, blob->data, blob->size, &f.written, 0)) {
                FUN_0020bbc2(h);
                goto fail;
            }
            FUN_0020bbc2(h);
        }
    }
    strcpy(f.path + pathLen, DAT_004ce270);
    {
        U h = FUN_002109f1(f.path, 0xc0000000, 3, 0, f.changed ? 1 : 3, 0x80, 0);
        *outHandle = h;
        if (h == (U)-1)
            goto fail;
        if (f.changed) {
            U bytes = FUN_00278150(size);
            if (FUN_002101d4(h, bytes, 0, 0) != bytes || !FUN_00210150(*outHandle) ||
                !FUN_00278ef0(*outHandle, bytes, !writing)) {
                FUN_0020bbc2(*outHandle);
                goto fail;
            }
        }
        FUN_0020bbc2(*outHandle);
        h = FUN_002109f1(f.path, f.access, f.disposition, 0, 3, 0x80, 0);
        *outHandle = h;
        if (h == (U)-1) {
            FUN_0020bbc2(h);
            goto fail;
        }
        if (!FUN_00278a00(h, &f.written)) {
            FUN_0020bbc2(*outHandle);
            return 0;
        }
    }
    {
        U fileSize = f.written;
        if (f.changed) {
            for (U i = 0; i < 4; ++i) {
                if (handles[i] == (U)-1) {
                    handles[i] = *outHandle;
                    break;
                }
            }
        } else {
            if (fileSize < 0x18 || !FUN_00279490(*outHandle, 0) || *DAT_0052c270 != f.written) {
                FUN_0020bbc2(*outHandle);
                DAT_0052c27c = 0;
                error = 12;
                return 0;
            }
        }
        *outAmount = fileSize - ((fileSize + 0x2013) / 0x2014) * 20 - 4;
        ++count;
        error = 0;
        return 1;
    }
fail:
    FUN_002789e0(XAPILIB::GetLastError());
    return 0;
}
