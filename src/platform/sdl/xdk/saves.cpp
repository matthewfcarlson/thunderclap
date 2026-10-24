// Saves / storage for the native image. Two builds of the same imports:
//   HULK_NATIVE_SDL (tools/native_fs.py): save-game folders and signatures on the SDL3 file backend
//   (src/platform/sdl/fs/hulk_saves.h, docs/native-files-saves.md). Without it: the first skeleton's stand-ins
//   (each counts and logs its calls, xdk_shim.h, and returns 0).
//
// What the game's call sites say these are (core::XboxSaveDrive, equivalent/0x00279630, 0x00279220, 0x002793b0,
// 0x00278ab0, 0x002788c0, 0x00278b50, 0x00278ef0, matches/0x00278180, 0x002781c0):
//   0x0035618d XCreateSaveGame(root "U:\", name UTF-16, disposition, 0, path out, size) -> error code (0 = ok; 3 =
//              OPEN_EXISTING of a missing save); the path ends with a backslash, the game appends "SaveImage.xbx"
//              and "save.dat"
//   0x003563f0 XDeleteSaveGame(root, name UTF-16) -> error code
//   0x003564c0 XFindFirstSaveGame(root, find data) -> HANDLE (-1 + GetLastError 18 when none); the find data is
//              0x344 bytes: a WIN32_FIND_DATA, the directory (260 bytes) and the save's name UTF-16 at +0x244 (128)
//   0x003565ca XFindNextSaveGame(handle, find data) -> BOOL;   0x00356611 XFindClose(handle)
//   0x002120e1/f5/143 XCalculateSignatureBegin(0) -> handle / Update(handle, data, size) / End(handle, 20 bytes)
//   0x00209237 XFormatUtilityDrive() -> BOOL (empties Z:);  0x003ebfe2 XMountMUA(port, unit, &letter) and
//   0x003ec280 XUnmountMU(port, unit): no memory units here (the controller layer never reports one);
//   0x00209b29 XMUNameFromDriveLetter(letter, name out, size) -> error code
#if defined(HULK_NATIVE_SDL)
#include "imports.h"
#include "../crt/host_crt.h"
#include "../fs/hulk_saves.h"

template <class T> static T* P(hulk_uptr a) { return (T*)a; }

// our handles are small tagged indices (hulk_fs.h, hulk_saves.h): the game holds them in HANDLE-sized words
static HulkFsHandle fh(hulk_uptr h) { return (HulkFsHandle)h; }

static hulk_u32 fail(unsigned err, hulk_u32 value) {
    hulk_host_SetLastError(err);
    return value;
}

static hulk_uptr fail_h(unsigned err) {   // a HANDLE result: INVALID_HANDLE_VALUE
    hulk_host_SetLastError(err);
    return HULK_INVALID_UPTR;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_XFormatUtilityDrive(void) {
    HULK_XDK_TRACE("XFormatUtilityDrive");
    unsigned err = hulk_fs_clear_drive('Z');
    return err ? fail(err, 0) : 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XMUNameFromDriveLetter(hulk_u32 letter, hulk_uptr name, hulk_u32 size) {
    HULK_XDK_TRACE("XMUNameFromDriveLetter");
    (void)letter;
    if (name && size)
        *P<unsigned short>(name) = 0;
    return HULK_ERR_DEVICE_NOT_CONNECTED;
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_XCalculateSignatureBegin(hulk_u32 flags) {
    HULK_XDK_TRACE("XCalculateSignatureBegin");
    HulkFsHandle h;
    unsigned err = hulk_sig_begin(flags, &h);
    return err ? fail_h(err) : (hulk_uptr)h;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureUpdate(hulk_uptr h, hulk_uptr data, hulk_u32 size) {
    HULK_XDK_TRACE("XCalculateSignatureUpdate");
    return hulk_sig_update(fh(h), P<const void>(data), size);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureEnd(hulk_uptr h, hulk_uptr out) {
    HULK_XDK_TRACE("XCalculateSignatureEnd");
    unsigned char sig[HULK_SIGNATURE_BYTES];
    unsigned err = hulk_sig_end(fh(h), sig);
    if (err)
        return err;
    if (out)
        for (int i = 0; i < HULK_SIGNATURE_BYTES; i++)
            P<unsigned char>(out)[i] = sig[i];
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCreateSaveGame(hulk_uptr root, hulk_uptr name, hulk_u32 disposition, hulk_u32 reserved,
                                                         hulk_uptr path, hulk_u32 path_size) {
    HULK_XDK_TRACE("XCreateSaveGame");
    (void)reserved;
    unsigned err = hulk_save_create(P<const char>(root), P<const unsigned short>(name), disposition,
                                    path ? P<char>(path) : 0, path ? path_size : 0);
    if (err)
        hulk_host_SetLastError(err);
    return err;
}

// 0x003563f0 is XDeleteSaveGame (the import table's name carries a second guess)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XDeleteSaveGame_XFindFirstSaveGame(hulk_uptr root, hulk_uptr name) {
    HULK_XDK_TRACE("XDeleteSaveGame_XFindFirstSaveGame");
    unsigned err = hulk_save_delete(P<const char>(root), P<const unsigned short>(name));
    if (err)
        hulk_host_SetLastError(err);
    return err;
}

// XGAME_FIND_DATA: WIN32_FIND_DATA (0x140), the directory path (260), the save's name (UTF-16 x 128) = 0x344
static void fill_save_find(hulk_uptr data, const HulkSaveFind& f) {
    hulk_u32* w = P<hulk_u32>(data);
    for (int i = 0; i < 0x344 / 4; i++)
        w[i] = 0;
    w[0] = f.directory.attributes;
    HulkU64 t[3] = {f.directory.create_time, f.directory.access_time, f.directory.write_time};
    for (int i = 0; i < 3; i++) {
        w[1 + i * 2] = (hulk_u32)t[i];
        w[2 + i * 2] = (hulk_u32)(t[i] >> 32);
    }
    char* name = P<char>(data) + 44;
    for (int i = 0; i < 259 && f.directory.name[i]; i++)
        name[i] = f.directory.name[i];
    char* dir = P<char>(data) + 0x140;
    for (int i = 0; i < 259 && f.path[i]; i++)
        dir[i] = f.path[i];
    unsigned short* wn = P<unsigned short>(data + 0x244);
    for (int i = 0; i < HULK_SAVE_NAME_CHARS - 1 && f.name[i]; i++)
        wn[i] = f.name[i];
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_XFindFirstSaveGame(hulk_uptr root, hulk_uptr data) {
    HULK_XDK_TRACE("XFindFirstSaveGame");
    HulkSaveFind f;
    HulkFsHandle h;
    unsigned err = hulk_save_find_first(P<const char>(root), &f, &h);
    if (err)
        return fail_h(err);
    if (data)
        fill_save_find(data, f);
    return (hulk_uptr)h;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindNextSaveGame(hulk_uptr h, hulk_uptr data) {
    HULK_XDK_TRACE("XFindNextSaveGame");
    HulkSaveFind f;
    unsigned err = hulk_save_find_next(fh(h), &f);
    if (err)
        return fail(err, 0);
    if (data)
        fill_save_find(data, f);
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindClose(hulk_uptr h) {
    HULK_XDK_TRACE("XFindClose");
    unsigned err = hulk_fs_close(fh(h));
    return err ? fail(err, 0) : 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XMountMUA(hulk_u32 port, hulk_u32 unit, hulk_uptr letter) {
    HULK_XDK_TRACE("XMountMUA");
    (void)port; (void)unit; (void)letter;
    return HULK_ERR_DEVICE_NOT_CONNECTED;       // no memory units
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XUnmountMU(hulk_u32 port, hulk_u32 unit) {
    HULK_XDK_TRACE("XUnmountMU");
    (void)port; (void)unit;
    return 0;
}

#else  // !HULK_NATIVE_SDL

// Stand-ins for saves / storage: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_CDECL hulk_xdk_XFormatUtilityDrive(void) {
    HULK_XDK_TRACE("XFormatUtilityDrive");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XMUNameFromDriveLetter(hulk_u32 a0, hulk_uptr a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("XMUNameFromDriveLetter");
    return 0;
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_XCalculateSignatureBegin(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XCalculateSignatureBegin");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureUpdate(hulk_uptr a0, hulk_uptr a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("XCalculateSignatureUpdate");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureEnd(hulk_uptr a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XCalculateSignatureEnd");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCreateSaveGame(hulk_uptr a0, hulk_uptr a1, hulk_u32 a2, hulk_u32 a3, hulk_uptr a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    HULK_XDK_TRACE("XCreateSaveGame");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XDeleteSaveGame_XFindFirstSaveGame(hulk_uptr a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XDeleteSaveGame_XFindFirstSaveGame");
    return 0;
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_XFindFirstSaveGame(hulk_uptr a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XFindFirstSaveGame");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindNextSaveGame(hulk_uptr a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XFindNextSaveGame");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindClose(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("XFindClose");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XMountMUA(hulk_u32 a0, hulk_u32 a1, hulk_uptr a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("XMountMUA");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XUnmountMU(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XUnmountMU");
    return 0;
}

#endif  // HULK_NATIVE_SDL
