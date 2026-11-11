// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e9e70..0x001eab10 (kind game, layer game, confidence high), dominant class CSoundResourceManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fc0e1b37 {
#define TREE_TU_END }
namespace fn_fc0e1b37 {} using namespace fn_fc0e1b37;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc0e1b37 {
struct Key_1ea0c0 { unsigned int low, high; };
} // namespace fn_fc0e1b37
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif
namespace fn_fc0e1b37 {
struct Item_1ea0c0 { void FUN_001e9bf0(); };
struct Owner_1ea0c0 {
 Item_1ea0c0* FUN_001e98b0(Key_1ea0c0*);
 void FUN_001ea0c0(const char* text);
};
struct Text_1ea630 {
    char data[0x2c];
    void FUN_00247270(const char *s, int len, int flags);
};
struct Handle_1ea630 {
    char data[0xa0];
    void FUN_002458f0(Text_1ea630 *src);
};
extern "C" int __cdecl FUN_00246100(Handle_1ea630 *h);
struct Frame_1ea630 {
    Text_1ea630 text;
    Handle_1ea630 handle;
};
struct CSoundResourceManager_nv_1ea630 {
    void FUN_001ea5a0(int id);
};


// 0x001ea0c0 FUN_001ea0c0 (194 B): equivalent/0x001ea0c0.cpp
// sym: ?FUN_001ea0c0@Owner_1ea0c0@fn_fc0e1b37@@QAEXPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 10/10)
// FUN_001ea0c0 @ 0x001ea0c0
void Owner_1ea0c0::FUN_001ea0c0(const char* text) {
 if (DAT_0049caa0) {
 unsigned __int64 hash = FUN_002672f0(text,0,0);
 Key_1ea0c0 key;
 key.low = (unsigned int)hash; key.high = (unsigned int)(hash >> 32);
 Item_1ea0c0* item = FUN_001e98b0(&key);
 if (!item) {
 unsigned int length=0;
 while(text[length]) ++length;
 if(length < 31) {
 char buffer[64] = {0};
 sprintf(buffer,"%s_%s",text,text);
 hash=FUN_002672f0(text,0,0);
 key.low=(unsigned int)hash; key.high=(unsigned int)(hash >> 32);
 item=FUN_001e98b0(&key);
 }
 }
 if(item) item->FUN_001e9bf0();
 }
}

} // namespace fn_fc0e1b37

// 0x001ea630 CSoundResourceManager::vfunc_3 (114 B): equivalent/0x001ea630.cpp
// sym: ?vfunc_3@CSoundResourceManager@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19928 inputs, branch coverage 2/2)
// CSoundResourceManager::vfunc_3 @ 0x001ea630
void CSoundResourceManager::vfunc_3(hulk_intptr __p0, int unused) { const char * name = (const char *)__p0;

    Frame_1ea630 f;
    int len = 0;
    while (name[len] != 0)
        len++;
    f.text.FUN_00247270(name, len, 0);
    f.handle.FUN_002458f0(&f.text);
    ((CSoundResourceManager_nv_1ea630*)this)->FUN_001ea5a0(FUN_00246100(&f.handle));
}

