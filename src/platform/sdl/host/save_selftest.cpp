// The save round trip of the native builds (drive1, D141): with HULK_SAVE_SELFTEST=1 the image writes a save through
// the game's own path right after it mounts the U: save drive, reads it back the same way, compares, reports and exits.
// Host side, C linkage; the link puts hulk_nhook_save_selftest at 0x0008c470's entry (native_hooks.h). Without the
// variable the hook only calls the mount. tests/native_host/save_roundtrip_test.py runs it.
//
// The path: CMemoryCardManager::FUN_0008cbe0 (the save: the slot's InstanceDrive slot 36 -> core::File's save
// constructor 0x002763a0 -> core::SaveGameOpenRequest -> XboxSaveDrive::vfunc_9 on the drive thread; core::File slot 10
// -> FileWriteRequest -> the drive's slot 13 -> 0x0027a460 -> the signed block writer 0x00279c50; slot 14 -> the
// commit 0x00279af0), then the load as FUN_0008ca70 does it once it has found the save: the slot's InstanceDrive slot
// 36 with the name (open, not create), core::File slot 22 (wait), 23 (open?), 9 (read -> FileReadRequest -> the
// drive's slot 12 -> 0x0027a370 -> the block reader 0x00279bb0 and the signature check 0x00279490), 1 (release). The
// save enumeration FUN_0008ca70 starts with (the drive's find, DriveFindFirstRequest) is not on records yet. The SDL
// shim's save backend stores the files under HULK_SAVE_DIR.
#if !defined(_WIN32)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern "C" {
// the game's functions, through the link's thunks to the tree's definitions (native_bind.py)
void hulk_orig_0008c470(void* manager, unsigned int value);   // the U: mount (CMemoryCardManager's set-up)
void* FUN_0008cbe0(void* manager, int index, int unused, const void* data, int size, const unsigned short* name);
void hulk_native_log(const char* line);   // entry_posix.cpp: a trace line
extern void* DAT_004dd6ec;                 // the CGame singleton (pointer-sized natively)
}

static const int kSaveSize = 0xbe8;   // the game's save (CGameFlowManager.GS.cpp's and unk_088ea0.GS.cpp's callers)

// MS-ABI virtual slots (arm64: `this` first, as a C call); the objects are the game's (their vftables the game's)
template <class F> static F slot(void* object, int index) { return (F)(*(void***)object)[index]; }
// CMemoryCardManager's words (decls/drive_media.h GameMemoryCardManager): the slots, each starting with its drive
static void* slot_drive(void* manager) { return **(void***)((char*)manager + 2 * sizeof(void*)); }

static void report(const char* line) {
    fprintf(stderr, "%s\n", line);
    hulk_native_log(line);
}

extern "C" void hulk_nhook_save_selftest(void* manager, unsigned int value) {
    hulk_orig_0008c470(manager, value);
    const char* on = getenv("HULK_SAVE_SELFTEST");
    if (!on || !*on || *on == '0')
        return;
    static unsigned char data[kSaveSize], back[kSaveSize];
    for (int i = 0; i < kSaveSize; ++i)
        data[i] = (unsigned char)(i * 7 + 3);
    static const unsigned short name[] = {'S', 'E', 'L', 'F', 'T', 'E', 'S', 'T', 0};
    char line[256];
    // The save pauses and resumes the sound manager (0x0008cbe0: CGame's +sound, 0x001eb870 / 0x001eb890, which act
    // only when its flag is set). At the mount CGame is not built yet: lend a zeroed stand-in whose every word points
    // at a zeroed block (the sound manager's flag 0: no pause), and take it back after.
    static void* zero_block[0x100];
    static void* game_standin[0x100];
    void* saved_game = DAT_004dd6ec;
    if (!saved_game) {
        for (int i = 0; i < 0x100; ++i)
            game_standin[i] = zero_block;
        DAT_004dd6ec = game_standin;
    }
    void* wrote = FUN_0008cbe0(manager, 0, 0, data, kSaveSize, name);
    snprintf(line, sizeof(line), "save-selftest: write result %p", wrote);
    report(line);
    memset(back, 0, sizeof(back));
    int read = -1, opened = 0;
    void* drive = slot_drive(manager);
    void* file = 0;
    static const char narrow[] = "SELFTEST";
    if (drive) {
        typedef void (*Open)(void*, void**, const char*, unsigned, unsigned, void*, unsigned, unsigned);
        slot<Open>(drive, 36)(drive, &file, narrow, 0, 0, 0, 0, 1);   // read-only, open the existing save
    }
    if (file) {
        typedef int (*Wait)(void*);
        typedef char (*IsOpen)(void*);
        typedef void (*Read)(void*, void*, int, int);
        typedef void (*Release)(void*);
        read = slot<Wait>(file, 22)(file);
        opened = slot<IsOpen>(file, 23)(file);
        if (read == 0 && opened) {
            slot<Read>(file, 9)(file, back, kSaveSize, 1);
            read = slot<Wait>(file, 22)(file);
        }
        slot<Release>(file, 1)(file);
    }
    const char* ascii = narrow;
    DAT_004dd6ec = saved_game;
    int same = memcmp(data, back, kSaveSize) == 0;
    snprintf(line, sizeof(line), "save-selftest: read result %d (open %d) name \"%s\" data %s", read, opened, ascii,
             same ? "identical" : "DIFFERENT");
    report(line);
    int ok = wrote == 0 && read == 0 && same;
    report(ok ? "save-selftest: ok" : "save-selftest: FAILED");
    fflush(stderr);
    _exit(ok ? 0 : 1);
}
#endif
