// A drive's media block and the memory-card manager's slots (drive1, 2026-11-18; decls/data/records.h includes this,
// the memory-card sources include it alone). The media block is core::Drive's +0x60 (records.h CoreDrive.media):
// 0x00278b50 (XboxSaveDrive) and 0x0026f290 (XboxDrive) fill it, 0x002728d0 returns its address and
// core::DriveMediaRequest::vfunc_1 0x00274520 copies it (21 words on the 32-bit build) into a caller's block: the
// memory-card manager keeps two per slot. As 32-bit byte offsets the 64-bit builds missed every word after the label's
// pointer alignment, and the manager's 0xc8-byte slot was too small for them.
#ifndef HULK_DECLS_DRIVE_MEDIA_H
#define HULK_DECLS_DRIVE_MEDIA_H

#include "compat/ptr.h"

// The label: a pointer to a constant name (0x0026f570, drive D:), the name in place ("Xbox Hard Disk", 0x0026f570)
// or the memory unit's name (0x00278b50 converts 0x41 bytes into it; 0x00278500 clears its first byte).
union CoreDriveLabel {
    const char* text;                       // +0x00
    char buffer[0x44];                      // +0x00 (0x41 bytes written, then 3 unused)
};

struct CoreDriveMedia {
    unsigned int result;                    // +0x00 the last query's result (0 ready; 0x0008c920 waits for 0)
    unsigned int size;                      // +0x04 the medium's free size (0x0008c740 reports it in 16 KiB blocks)
    unsigned int count;                     // +0x08 size / sectorSize
    unsigned int sectorSize;                // +0x0c (0x200 by default; FileOpenRequest / SaveGameOpenRequest read it)
    CoreDriveLabel label;                   // +0x10 (0x0008c710 converts it to the slot's wide name)
};

// One memory-card slot of CMemoryCardManager (0x0008c470 allocates the U: slot, 0xc8 bytes on the 32-bit build;
// 0x0008c740 / 0x0008c810 / 0x0008c870 / 0x0008ca30 / 0x0008c590 / 0x0008c680 / 0x0008c920 / 0x0008ca70 / 0x0008cbe0 /
// 0x0008cd80 index the manager's array of them)
struct GameMemoryCardSlot {
    void* drive;                            // +0x00 the core::InstanceDrive on the unit (0x00271530's result)
    void* file;                             // +0x04 the save open on it (released before another opens)
    CoreDriveMedia pending;                 // +0x08 the instance drive's slot 4 (an asynchronous media query) fills it
    CoreDriveMedia media;                   // +0x5c its slot 11 (the query, waited for) fills it: 0x0008c920
    unsigned int result;                    // +0xb0 0x0008c470: the drive's slot 40 (its open)
    int status[5];                          // +0xb4 per save game (0x0008c920; 1 at 0x0008c470 / 0x0008c870)
};
// a compile error on the 32-bit builds unless the slot is the XBE's 0xc8 bytes (0x0008c470's allocation)
typedef char hulk_memory_card_slot_size32_[(sizeof(void*) != 4 || sizeof(GameMemoryCardSlot) == 0xc8) ? 1 : -1];

// CMemoryCardManager's words (gen/global.h; 0x0008c7f0 constructs it, CGameFlowManager.new_plain.cpp allocates it):
// the methods above reach their slot through `slots`
struct GameMemoryCardManager {
    const void* vftable;                    // +0x00 core::IDriveErrorCallback (0x004004f4)
    int parameter;                          // +0x04 0x0008c470's argument (the instance drive's open size)
    GameMemoryCardSlot* slots;              // +0x08 0x0008c470 allocates the U: slot
};

#endif
