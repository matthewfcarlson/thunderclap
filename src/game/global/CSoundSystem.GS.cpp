// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f0ab0..0x001f2db0 (kind game, layer game, confidence high), dominant class CSoundSystem
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fddead73 {
#define TREE_TU_END }
namespace fn_fddead73 {} using namespace fn_fddead73;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fddead73 {
struct CSoundCommand_PlayDialogueEvent_nv_1f1740 {
    CSoundCommand_PlayDialogueEvent* FUN_001f0630(const char*, void*, unsigned, unsigned);
};
struct Manager_1f1740 { void FUN_001ef260(CSoundCommand_PlayDialogueEvent*); };
extern void* __cdecl FUN_0008d710(unsigned, unsigned);
struct CSoundCommand_PlayMissionDialogueEvent_nv_1f17f0 {
    CSoundCommand_PlayMissionDialogueEvent* FUN_001f0760(const char*, void*, unsigned, unsigned, unsigned, unsigned);
};
struct Manager_1f17f0 { void FUN_001ef260(CSoundCommand_PlayMissionDialogueEvent*); };
struct CSoundCommand_PlayFightDialogueEvent_nv_1f18b0 {
    CSoundCommand_PlayFightDialogueEvent* FUN_001f06c0(const char* name, void* data, unsigned a, unsigned b, unsigned c);
};
struct Manager_1f18b0 {
    void FUN_001ef260(CSoundCommand_PlayFightDialogueEvent* item);
};
} // namespace fn_fddead73
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void * __cdecl memset(void *, int, unsigned int);
#endif
namespace fn_fddead73 {
class Mgr_1f1970 {
public:
    void FUN_001ef260(void *p);
};
struct CSoundCommand_PlayMusicEvent_nv_1f1970 {
    void *FUN_001f0810(const char *name, int b, int c);
};
void *__cdecl FUN_0008d710(int size, int tag);
struct Frame_1f1970 {
    Mgr_1f1970 *mgr;
    char buf[0x40];
};
class Mgr_1f1a20 {
public:
    void FUN_001ef260(void *p);
};
struct CSoundCommand_PlayAmbienceEvent_nv_1f1a20 {
    void *FUN_001f0880(const char *name, int b, int c);
};
struct Frame_1f1a20 {
    Mgr_1f1a20 *mgr;
    char buf[0x40];
};
class Mgr_1f1ad0 {
public:
    void FUN_001ef260(void *p);
};
struct CSoundCommand_PlaySFXEvent_nv_1f1ad0 {
    void *FUN_001f08f0(const char *name, int b, int c);
};
struct Frame_1f1ad0 {
    Mgr_1f1ad0 *mgr;
    char buf[0x40];
};
class Mgr_1f1b80 {
public:
    void FUN_001ef260(void *p);
};
struct CSoundCommand_CueNISEvent_nv_1f1b80 {
    void *FUN_001f0960(const char *name, int b, int c);
};
struct Frame_1f1b80 {
    Mgr_1f1b80 *mgr;
    char buf[0x40];
};


// 0x001f1740 FUN_001f1740 (172 B): equivalent/0x001f1740.cpp
// sym: ?FUN_001f1740@fn_fddead73@@YGXPBDPAXII@Z @1df0a9ea5744 @w812ef91cdec9
// STATUS: equivalent (tools/equiv.py level 3: 18759 inputs, branch coverage 11/12, incomplete)
// FUN_001f1740 @ 0x001f1740
void __stdcall FUN_001f1740(const char* name, void* value, unsigned a, unsigned b) {
 if (name && value) {
 Manager_1f1740* manager = (*(Manager_1f1740**)&DAT_004e3710);
 if (manager) {
 char buffer[64] = {0};
 unsigned i=0;
 do { buffer[i]=name[i]; } while(name[i++]);
 CSoundCommand_PlayDialogueEvent* p=(CSoundCommand_PlayDialogueEvent*)FUN_0008d710(32,6);
 if(p) p=((CSoundCommand_PlayDialogueEvent_nv_1f1740*)(((CSoundCommand_PlayDialogueEvent*)(p))))->FUN_001f0630(name,value,a,b);
 manager->FUN_001ef260(p);
 }
 }
}


// 0x001f17f0 FUN_001f17f0 (186 B): equivalent/0x001f17f0.cpp
// sym: ?FUN_001f17f0@fn_fddead73@@YGXPBDPAXIIII@Z @93b401b7eb56 @wd42ea0632b9c
// STATUS: equivalent (tools/equiv.py level 3: 18759 inputs, branch coverage 11/12, incomplete)
// FUN_001f17f0 @ 0x001f17f0
void __stdcall FUN_001f17f0(const char* name, void* data, unsigned a, unsigned b, unsigned c, unsigned d) {
 if(name && data) {
  Manager_1f17f0* manager=(*(Manager_1f17f0**)&DAT_004e3710);
  if(manager) {
   char buffer[64]={0};
   unsigned n=0; do {buffer[n]=name[n];} while(name[n++]);
   CSoundCommand_PlayMissionDialogueEvent* item=(CSoundCommand_PlayMissionDialogueEvent*)FUN_0008d710(0x48,6);
   if(item) item=((CSoundCommand_PlayMissionDialogueEvent_nv_1f17f0*)(((CSoundCommand_PlayMissionDialogueEvent*)(item))))->FUN_001f0760(name,data,a,b,c,d);
   manager->FUN_001ef260(item);
  }
 }
}


// 0x001f18b0 FUN_001f18b0 (181 B): equivalent/0x001f18b0.cpp
// sym: ?FUN_001f18b0@fn_fddead73@@YGXPBDPAXIII@Z @eb30eaa558b3 @wcd545f89b79b
// STATUS: equivalent (tools/equiv.py level 3: 18759 inputs, branch coverage 11/12, incomplete)
// FUN_001f18b0 @ 0x001f18b0
void __stdcall FUN_001f18b0(const char* name, void* data, unsigned a, unsigned b, unsigned c) {
    if (name && data) {
        Manager_1f18b0* manager = (*(Manager_1f18b0**)&DAT_004e3710);
        if (manager) {
            char buffer[64] = {0};
            unsigned i = 0;
            do { buffer[i] = name[i]; } while (name[i++]);
            CSoundCommand_PlayFightDialogueEvent* item = (CSoundCommand_PlayFightDialogueEvent*)FUN_0008d710(40, 6);
            if (item) item = ((CSoundCommand_PlayFightDialogueEvent_nv_1f18b0*)(((CSoundCommand_PlayFightDialogueEvent*)(item))))->FUN_001f06c0(name, data, a, b, c);
            manager->FUN_001ef260(item);
        }
    }
}


// 0x001f1970 FUN_001f1970 (167 B): matches/0x001f1970.cpp
// sym: ?FUN_001f1970@fn_fddead73@@YGXPBDHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2855 inputs, branch coverage 11/12, incomplete)
// FUN_001f1970 @ 0x001f1970
void __stdcall FUN_001f1970(const char *name, int b, int c)
{
    Frame_1f1970 f;
    if (name != 0) {
        if (b != 0) {
            f.mgr = (*(Mgr_1f1970**)&DAT_004e3710);
            if (f.mgr != 0) {
                memset(f.buf, 0, sizeof f.buf);
                strcat(f.buf, name);
                CSoundCommand_PlayMusicEvent *j = (CSoundCommand_PlayMusicEvent *)FUN_0008d710(0x20, 6);
                f.mgr->FUN_001ef260(j != 0 ? ((CSoundCommand_PlayMusicEvent_nv_1f1970*)(((CSoundCommand_PlayMusicEvent*)(j))))->FUN_001f0810(name, b, c) : 0);
            }
        }
    }
}


// 0x001f1a20 FUN_001f1a20 (167 B): matches/0x001f1a20.cpp
// sym: ?FUN_001f1a20@fn_fddead73@@YGXPBDHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2855 inputs, branch coverage 11/12, incomplete)
// FUN_001f1a20 @ 0x001f1a20
void __stdcall FUN_001f1a20(const char *name, int b, int c)
{
    Frame_1f1a20 f;
    if (name != 0) {
        if (b != 0) {
            f.mgr = (*(Mgr_1f1a20**)&DAT_004e3710);
            if (f.mgr != 0) {
                memset(f.buf, 0, sizeof f.buf);
                strcat(f.buf, name);
                CSoundCommand_PlayAmbienceEvent *j = (CSoundCommand_PlayAmbienceEvent *)FUN_0008d710(0x20, 6);
                f.mgr->FUN_001ef260(j != 0 ? ((CSoundCommand_PlayAmbienceEvent_nv_1f1a20*)(((CSoundCommand_PlayAmbienceEvent*)(j))))->FUN_001f0880(name, b, c) : 0);
            }
        }
    }
}


// 0x001f1ad0 FUN_001f1ad0 (167 B): matches/0x001f1ad0.cpp
// sym: ?FUN_001f1ad0@fn_fddead73@@YGXPBDHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2855 inputs, branch coverage 11/12, incomplete)
// FUN_001f1ad0 @ 0x001f1ad0
void __stdcall FUN_001f1ad0(const char *name, int b, int c)
{
    Frame_1f1ad0 f;
    if (name != 0) {
        if (b != 0) {
            f.mgr = (*(Mgr_1f1ad0**)&DAT_004e3710);
            if (f.mgr != 0) {
                memset(f.buf, 0, sizeof f.buf);
                strcat(f.buf, name);
                CSoundCommand_PlaySFXEvent *j = (CSoundCommand_PlaySFXEvent *)FUN_0008d710(0x20, 6);
                f.mgr->FUN_001ef260(j != 0 ? ((CSoundCommand_PlaySFXEvent_nv_1f1ad0*)(((CSoundCommand_PlaySFXEvent*)(j))))->FUN_001f08f0(name, b, c) : 0);
            }
        }
    }
}


// 0x001f1b80 FUN_001f1b80 (167 B): matches/0x001f1b80.cpp
// sym: ?FUN_001f1b80@fn_fddead73@@YGXPBDHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2855 inputs, branch coverage 11/12, incomplete)
// FUN_001f1b80 @ 0x001f1b80
void __stdcall FUN_001f1b80(const char *name, int b, int c)
{
    Frame_1f1b80 f;
    if (name != 0) {
        if (b != 0) {
            f.mgr = (*(Mgr_1f1b80**)&DAT_004e3710);
            if (f.mgr != 0) {
                memset(f.buf, 0, sizeof f.buf);
                strcat(f.buf, name);
                CSoundCommand_CueNISEvent *j = (CSoundCommand_CueNISEvent *)FUN_0008d710(0x20, 6);
                f.mgr->FUN_001ef260(j != 0 ? ((CSoundCommand_CueNISEvent_nv_1f1b80*)(((CSoundCommand_CueNISEvent*)(j))))->FUN_001f0960(name, b, c) : 0);
            }
        }
    }
}

} // namespace fn_fddead73
