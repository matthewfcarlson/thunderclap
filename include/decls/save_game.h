// The save-game open (drive1, D141): the records its request chain passes. Only the TUs on that chain include this
// (not records.h: an addition there moves MSVC 7.1's code in TUs that do not use it, D74 / D139).
//   CMemoryCardManager 0x0008cbe0 -> the slot's InstanceDrive slot 36 0x00276fd0 / 35 0x00276f00 -> core::File's save
//   constructor 0x002763a0 -> core::SaveGameOpenRequest (0x00275060 builds it, vfunc_1 0x00273cb0 runs it on the drive
//   thread) -> XboxSaveDrive::vfunc_9 0x00279630.
#ifndef HULK_DECLS_SAVE_GAME_H
#define HULK_DECLS_SAVE_GAME_H

#include "decls/data/records.h"

// A save's extra image: the memory-card manager allocates it (8 bytes on the 32-bit build: 0x0008c470, 0x0008cbe0);
// the save drive's open writes `data` to the save's image file when it creates the save, and its size estimate
// (vfunc_5 0x00278340) counts it.
struct GameSaveImage {
    void* data;                             // +0x00 0 for none
    unsigned int length;                    // +0x04
};
typedef char hulk_save_image_size32_[(sizeof(void*) != 4 || sizeof(GameSaveImage) == 8) ? 1 : -1];

// core::SaveGameOpenRequest (vftable 0x0042ba40; 0x00275060 constructs it in a "FileRequest" pool item, 0x1c bytes
// on the 32-bit build): records.h CoreRequest (its `file` the core::File it opens), then the open's arguments.
struct CoreSaveGameOpenRequest {
    CoreRequest request;                    // +0x00
    unsigned int mode;                      // +0x0c 0 open, 1 / 2 create, 3 replace (vfunc_9)
    unsigned char writable;                 // +0x10
    char pad11[3];
    GameSaveImage* image;                   // +0x14 the save's extra image (0 for none)
    unsigned int size;                      // +0x18 the payload's size
};
typedef char hulk_save_open_request_size32_[(sizeof(void*) != 4 || sizeof(CoreSaveGameOpenRequest) == 0x1c) ? 1 : -1];

#endif
