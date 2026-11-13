// Records of the 18 managers CGame's set-up 0x00088020 allocates (x64t9-mgr; they replace x64t4's HULK_X2_88020 upper
// bound). Each is the words its constructor writes and the blocks between, as the original lays them out, with the
// words the original stores pointers in (the constructor, the manager's set-up call in 0x00088020 and its other
// methods: the evidence is named per record) as pointers, so they are 8 bytes natively. 0x00088020 allocates
// `sizeof(record)`; each constructor's own view of `this` checks HULK_MGR_SAME(view, record) on every build, and
// HULK_MGR_SIZE32 checks the XBE's size on the 32-bit builds. Included only by the constructors' sources and
// 0x00088020's (src/game/global/CTimeManager.GS.cpp).
#ifndef HULK_DECLS_MANAGERS_H
#define HULK_DECLS_MANAGERS_H

#define HULK_MGR_CAT2(a, b) a##b
#define HULK_MGR_CAT(a, b) HULK_MGR_CAT2(a, b)
// HULK_MGR_SIZE32(T, n): a compile error on the 32-bit builds unless sizeof(T) is n (the XBE's allocation)
#define HULK_MGR_SIZE32(T, n) \
    typedef char HULK_MGR_CAT(hulk_mgr_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
// HULK_MGR_SAME(View, Record): a compile error on every build unless the view's size is the record's
#define HULK_MGR_SAME(V, R) typedef char HULK_MGR_CAT(hulk_mgr_same_, __LINE__)[(sizeof(V) == sizeof(R)) ? 1 : -1]

// CPlatformManager (0x0008d850, 24 bytes): the vftable, the archive stream (0x0008e880 opens it), the window
// 0x0008dec0 stores (&DAT_004dd7e4) and the Pure3D context it creates there (0x00292560's result), two words
struct HulkPlatformManager {
    void* vftable;
    void* archive;
    void* window;
    void* context;
    int f10, f14;
};
HULK_MGR_SIZE32(HulkPlatformManager, 24);

// 0x0023f670 (8 bytes): the build string 0x0023f690 stores ("Hulk release ..." from 0x00088020) and a word
struct Hulk_23f670 {
    const char* build;
    int b;
};
HULK_MGR_SIZE32(Hulk_23f670, 8);

// CControllerManager (0x000aef10, 36 bytes): the vftable, its device manager (allocated there), four words, a flag
// and nine button-lock flags
struct HulkControllerManager {
    void* vftable;
    void* devices;
    int f08, f0c, f10, f14;
    char f18;
    char flags[9];
};
HULK_MGR_SIZE32(HulkControllerManager, 36);

// CGameControllerManager (0x000af310, 8 bytes): the vftable and its CGameController (allocated there)
struct HulkGameControllerManager {
    void* vftable;
    void* controller;
};
HULK_MGR_SIZE32(HulkGameControllerManager, 8);

// CHapticControllerManager (0x000b0500, 12 bytes): the vftable, two flags and its haptic device (allocated there)
struct HulkHapticControllerManager {
    void* vftable;
    char f04;
    unsigned char f05;
    void* device;
};
HULK_MGR_SIZE32(HulkHapticControllerManager, 12);

// CStatsManager (0x00091630, 0x10d0 bytes, no vftable): 50 stats of 16 words (two tUIDs, 0x0027af00, and their
// values: 0x00090630 / 0x00090720), the count, a word, the XP, the demo grades (0x00090270: names and text inline)
// and the secrets found. No word holds a pointer: the same size on every build.
struct HulkStatsManager {
    unsigned int stats[800];
    unsigned int count;
    unsigned int untouched;
    unsigned int xp;
    unsigned int grades[272];
    unsigned int secrets;
};
HULK_MGR_SIZE32(HulkStatsManager, 0x10d0);

// 0x0010b2c0 (1 byte): an empty object (its constructor registers three contexts and two callbacks)
struct Hulk_10b2c0 {
    char unused;
};
HULK_MGR_SIZE32(Hulk_10b2c0, 1);

// CUnlockablesManager (0x00094fb0, 0x1790 bytes, no vftable): 0x2fe unlockables (allocated there), 100 ids, a
// word and a pad, and 32 slots of 0x50 bytes (two words, two, sixteen ids)
struct HulkUnlockableSlot {
    int a, b;
    int pad8[2];
    int v[16];
};
struct HulkUnlockablesManager {
    void* items[0x2fe];
    int ids[100];
    int fd88;
    int padd8c;
    HulkUnlockableSlot slots[32];
};
HULK_MGR_SIZE32(HulkUnlockablesManager, 0x1790);

// CGameFlowManager (0x00089bf0, 0xad0 bytes, no vftable): five names, three id / index pairs (with 32-byte names),
// six values, ten handles, 100 entries of 24 bytes (two words and 16 bytes), the mode and four flags, and four
// pointers 0x0008bf80 stores: the shared triple (0xac0, CGame+4), a 12-byte object it allocates (0xac4), a 0x4ad0
// buffer it allocates (0xac8) and the unlockables manager (0xacc)
struct HulkGameFlowEntry {
    int first, second;
    char reserved[16];
};
struct HulkGameFlowManager {
    char text0[32], text1[32], text2[32], text3[32];
    int id0, index0;
    char pad88[32];
    int id1, index1;
    char padB0[32];
    int id2, index2;
    char name[32];
    int values[6];
    int handles[10];
    char text4[32];
    HulkGameFlowEntry entries[100];
    int mode;
    unsigned char flag0, flag1, flag2, flag3;
    void* links[4];
};
HULK_MGR_SIZE32(HulkGameFlowManager, 0xad0);

// CSoundRealTimeManager (0x001eb220, 28 bytes, no vftable): its resource (0x001f1270's object, allocated there),
// the owner (CGame, 0x00088020's `this`), the mode and a flag, three volumes and a count
struct HulkSoundRealTimeManager {
    void* resource;
    void* owner;
    unsigned char mode;
    unsigned char active;
    char padding[2];
    float first, second, third;
    unsigned int count;
};
HULK_MGR_SIZE32(HulkSoundRealTimeManager, 28);

// COverlayManager (0x000d6970, 48 bytes): the vftable, its view (0x000d6a20 allocates it; 0x000d6e70 releases it),
// the state, eight overlay items (0x000d6c70's items) and its camera (0x000d6a20; 0x000d6e70 releases it)
struct HulkOverlayManager {
    void* vftable;
    void* view;
    unsigned int state;
    void* items[8];
    void* camera;
};
HULK_MGR_SIZE32(HulkOverlayManager, 48);

// CSubtitleManager (0x001c0cd0, 96 bytes, no vftable): the time, a count, its events (allocated there), two flags,
// five words, a flag, its ten text buffers, the overlay table, the callback, two overlays and the entries (all
// allocated there), four words then CGame (0x001c0a40 stores it at 0x4c), a word, two flags, its shader loader and a
// last word
struct HulkSubtitleManager {
    float time;
    unsigned int count;
    void* events;
    unsigned char enabled, flag;
    char pad[2];
    unsigned int a, b, c, mode, d;
    unsigned char ready;
    char pad2[3];
    void* buffers;
    void* table;
    void* callback;
    void* resource1;
    void* resource2;
    void* entries;
    unsigned int e, f, g;
    void* context;
    unsigned int i;
    unsigned char j, k;
    char pad3[2];
    void* loader;
    unsigned int last;
};
HULK_MGR_SIZE32(HulkSubtitleManager, 96);

// CFEManager (0x000c0e40, 0x1d38 bytes): the words its constructor writes; pointers where 0x000c4ef0 (the set-up
// 0x00088020 calls with the other managers) stores objects or managers (0x20 the renderer, 0x24 the camera, 0x34 the
// flow manager, 0x40 the sound manager, 0x44 the haptic manager, 0x48 the platform manager, 0x4c the unlockables
// manager, 0x50 the stats manager, 0x58 the controller manager, 0x5c the subtitle manager, 0x60 the controller
// system, 0x64 the callback, 0x68 the shader) and where its release (CFEManager.GS.cpp's view) frees them (0x1c,
// 0x20, 0x24); the two lists of 128 strings 0x000b4b60 duplicates (0x6c, 0x26c); 128 records of four tUIDs and two
// words; the flags, names and words up to the end
struct HulkFERecord {
    unsigned int items[8];
    unsigned int tail[2];
};
struct HulkFEManager {
    void* vftable;
    unsigned int f4;
    unsigned char f8;
    char p9[7];
    unsigned int f10, f14, f18;
    void* f1c;
    void* f20;
    void* f24;
    unsigned char f28;
    char p29[3];
    unsigned int f2c, f30;
    void* f34;
    unsigned int f38, f3c;
    void* f40;
    void* f44;
    void* f48;
    void* f4c;
    void* f50;
    unsigned int f54;
    void* f58;
    void* f5c;
    void* f60;
    void* f64;
    void* f68;
    char* listA[128];
    char* listB[128];
    unsigned int f46c;
    HulkFERecord records[128];
    unsigned char f1870;
    char p1871[3];
    unsigned int f1874;
    unsigned char f1878;
    char p1879[3];
    unsigned int f187c, f1880;
    char p1884[0x180];
    unsigned char f1a04, f1a05, f1a06;
    char p1a07[0x1c1];
    unsigned char f1bc8, f1bc9;
    char p1bca[2];
    unsigned char f1bcc;
    char p1bcd[0x3f];
    unsigned char f1c0c;
    char p1c0d[0x3f];
    unsigned char f1c4c;
    char p1c4d[0x3f];
    unsigned char f1c8c;
    char p1c8d[0x1f];
    unsigned char f1cac;
    char p1cad[0x3f];
    int f1cec, f1cf0;
    unsigned int f1cf4, f1cf8, f1cfc;
    unsigned char f1d00;
    char p1d01[3];
    unsigned int f1d04, f1d08, f1d0c, f1d10, f1d14, f1d18, f1d1c;
    float f1d20;
    unsigned int f1d24, f1d28, f1d2c, f1d30, f1d34;
};
HULK_MGR_SIZE32(HulkFEManager, 0x1d38);

// CRenderManager (0x001bb990, 100 bytes): the vftable, its view (0x001b8690 allocates it), the fog colour and
// planes, a flag, five words (0x24 the cursor id, 0x001b9020), its overlay shader (allocated there), four flags and
// the colour words up to 0x60
struct HulkRenderManager {
    void* vftable;
    void* view;
    int f8, fc;
    float f10, f14;
    char f18;
    char pad19[3];
    int f1c, f20, f24, f28;
    void* overlay;
    char flags30[4];
    int f34, f38, f3c;
    int f40, f44, f48, f4c;
    float f50;
    int f54, f58, f5c, f60;
};
HULK_MGR_SIZE32(HulkRenderManager, 100);

// CWorldStreamManager::CMemoryPool (0x3c bytes; CWorldStreamManager's constructor builds 22 inline): the vftable, the
// state, the pool's name (0x002047c0 copies it), its id and count, the heap, the resource and the inventory 0x002047c0
// creates, and the inventory's size word (0x80)
struct HulkWorldMemoryPool {
    void* vftable;
    char state;
    char name[33];
    short id;
    short count;
    void* context;
    void* resource;
    int config;
    void* helper;
};
HULK_MGR_SIZE32(HulkWorldMemoryPool, 0x3c);
// CWorldStreamManager (0x00208210, 0xb00 bytes): the vftable, two names (0x00206320's), the current object (0x44),
// the 22 pools, two loaded rooms (0x00204720), three streams (0x00207960's table, objects 0x00203e90 takes), the
// selection, CGame (0x002062d0), an owner (0x00204de0) and a short table (0x002067d0), four words, the room flags
// (0x400 bytes), the slot count, ids and values (0x002071e0), the loaded ids, the temporary object, the name
// ("hulk"), two temporary files, the playing object (0x00207960) and the flags and words up to the end
struct HulkWorldStreamManager {
    void* vftable;
    char name1[0x20];
    char name2[0x20];
    void* f44;
    HulkWorldMemoryPool pools[22];
    void* rooms[2];
    void* streams[3];
    int selected;
    void* game;
    void* owner58c;
    void* table590;
    int f594, f598, f59c;
    char pad5a0[4];
    unsigned char flags[0x400];
    int f9a4;
    int slotCount;
    int slotIds[20];
    int slotVals[20];
    int fa4c;
    int ids[20];
    void* faa0;
    char name[0x20];
    char nameTerm;
    char padAC5[0x1f];
    void* fae4;
    void* fae8;
    void* faec;
    char faf0, faf1, faf2, faf3, faf4, faf5;
    char padAF6[2];
    int faf8, fafc;
};
HULK_MGR_SIZE32(HulkWorldStreamManager, 0xb00);

// CTimeManager (0x00087e30, 80 bytes, no vftable): words and the 64-bit time stamps (0x00267f40); no pointers
struct HulkTimeManager {
    unsigned int v, x;
    unsigned int a, b, c, d, e, f;
    unsigned int pad[6];
    unsigned int limit, other;
    unsigned int tail[4];
};
HULK_MGR_SIZE32(HulkTimeManager, 80);

// World (0x00088600, 160 bytes; DAT_004dd700): the vftable, the 21 managers 0x00088670 creates and stores (0x04 ...
// 0x50 the config, 0x54 CGame), the object at 0x58 (0x00088670), the world's name (0x00088e10 / 0x00088e40), a flag
// (0x9c) and the ready flag (0x9d)
struct HulkWorld {
    void* vftable;
    void* parts[21];
    void* f58;
    char name[0x40];
    char f9c;
    char ready;
};
HULK_MGR_SIZE32(HulkWorld, 160);

// CFMVManager (0x001b84f0, 0x138 bytes): the vftable, a word, two flags, the movie object (0x0c), the parameter,
// the movie's name, a flag, its state, the four managers 0x001b7260 stores (CGame+4's triple, the platform manager,
// the world stream manager, the unlockables manager; 0x118 ... 0x12c with the rumble buffer 0x001b7290 allocates at
// 0x124), two flags and a word
struct HulkFMVManager {
    void* vftable;
    int f04;
    char f08, f09;
    void* f0c;
    int f10;
    char f14[0x100];
    char f114;
    void* f118;
    void* f11c;
    void* f120;
    void* f124;
    int f128;
    void* f12c;
    char f130, f131;
    int f134;
};
HULK_MGR_SIZE32(HulkFMVManager, 0x138);

// The two small records 0x00088020 allocates inline: the shared triple (CGame+4: 1, 0, 0) and the pair 0x000d3ef0
// fills with the front end and controller managers
struct HulkGameTriple {
    int a, b, c;
};
HULK_MGR_SIZE32(HulkGameTriple, 12);
struct HulkManagerPair {
    void* a;
    void* b;
};
HULK_MGR_SIZE32(HulkManagerPair, 8);

#endif
