// The words of CUnlockable and its subclasses past the vftable (typ1). The game's classes are polymorphic; the
// sources' local classes derive from these words (a polymorphic class with a non-polymorphic base puts its vftable
// first and the base after it, at +0x04 on the 32-bit builds and +0x08 on the 64-bit ones, as the game's layout has
// it), so a field read is the field's own place on every build. Offsets are the 32-bit ones, of the whole object.
#ifndef HULK_DECLS_UNLOCKABLES_H
#define HULK_DECLS_UNLOCKABLES_H

// An 8-byte name id: 0x0027af00 zeroes both words, 0x0027af50 (empty) destroys it.
struct HulkUnlockableId {
    unsigned int lo;
    unsigned int hi;
};

// CUnlockable (vftable 0x0040449c; 0x00091bc0 constructs it, 0x00091be0 / vfunc_0 0x000933a0 destroy it).
struct HulkUnlockableWords {
    int word04;                             // +0x04 (no reference found)
    unsigned char enabled;                  // +0x08 0x00091bc0 sets 1
    unsigned char pad09[7];                 // +0x09
    HulkUnlockableId id;                    // +0x10 0x00091bc0 (0x0027af00)
    void* data;                             // +0x18 0x00091bc0 sets 0; 0x00091be0 frees it (0x00267090)
};

// CUnlockableMove (vftable 0x004044b4; 0x00091ea0 / 0x000934d0 construct it, 0x00091ef0 / vfunc_0 0x00093470 destroy).
struct HulkUnlockableMoveWords : HulkUnlockableWords {
    int word1c;                             // +0x1c
    unsigned char flag20;                   // +0x20 0x00091ea0 sets 0
    unsigned char pad21[3];
    int value24;                            // +0x24 0
    int value28;                            // +0x28 -1
    unsigned char flag2c;                   // +0x2c 0
    unsigned char flag2d;                   // +0x2d 0
    unsigned char pad2e[2];
    int value30;                            // +0x30 0
    int word34;                             // +0x34
    HulkUnlockableId id38;                  // +0x38 (0x0027af00)
    HulkUnlockableId id40;                  // +0x40 (0x0027af00)
    unsigned char flag48;                   // +0x48 0
    unsigned char pad49[3];
};

// CUnlockableCheat (vftable 0x004044ac; 0x00091de0 / 0x00091da0 construct it); CUnlockableMovie (vftable
// 0x004044c4) adds a byte at +0x30.
struct HulkUnlockableCheatWords : HulkUnlockableWords {
    int word1c;                             // +0x1c
    unsigned char flag20;                   // +0x20 0
    unsigned char pad21[3];
    unsigned int value24;                   // +0x24 0x00091da0 sets -1
    char code[8];                           // +0x28 0x00091de0 prints its argument into it (0x00267760, 8 bytes)
};

// CUnlockableBlonskyFile (vftable 0x004044a4; 0x00091c80 constructs it, 0x00091cc0 destroys it).
struct HulkUnlockableBlonskyFileWords : HulkUnlockableWords {
    int word1c;                             // +0x1c
    HulkUnlockableId id20;                  // +0x20 (0x0027af00)
    unsigned char text28[0x40];             // +0x28 0x00091c80 clears the first byte
    unsigned char text68[0x40];             // +0x68 (cleared)
    unsigned char flagA8;                   // +0xa8 (cleared)
    unsigned char padA9[3];
};

// CUnlockableGallery (vftable 0x004044cc; 0x00092230 constructs it, 0x00092270 destroys it).
struct HulkUnlockableGalleryWords : HulkUnlockableWords {
    int word1c;                             // +0x1c
    int value20;                            // +0x20 0x00092230 sets 0
    unsigned char text24[0x40];             // +0x24 (cleared)
    unsigned char text64[0x40];             // +0x64 (cleared)
    int wordA4;                             // +0xa4
    HulkUnlockableId idA8;                  // +0xa8 (0x0027af00; 0x00092270 destroys it)
    unsigned char textB0[0x14];             // +0xb0 (cleared)
    unsigned char textC4[0x40];             // +0xc4
    unsigned char flag104;                  // +0x104
    unsigned char pad105[3];
};

// The 32-bit sizes (each class's XBE size less its vftable pointer); nothing on 64-bit. No code.
#define HULK_UNLOCKABLE_SIZE32(T, n) typedef char hulk_unlockable_size32_##T[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
HULK_UNLOCKABLE_SIZE32(HulkUnlockableWords, 0x18);
HULK_UNLOCKABLE_SIZE32(HulkUnlockableMoveWords, 0x48);
HULK_UNLOCKABLE_SIZE32(HulkUnlockableCheatWords, 0x2c);
HULK_UNLOCKABLE_SIZE32(HulkUnlockableBlonskyFileWords, 0xa8);
HULK_UNLOCKABLE_SIZE32(HulkUnlockableGalleryWords, 0x104);

#endif
