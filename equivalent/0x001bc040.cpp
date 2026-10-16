// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001bc040 @ 0x001bc040
#include "decls/address.h"
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strcpy(char*, const char*);
extern unsigned int DAT_004d9968;

struct Controller_1bc040 {
    int FUN_000ae960();
};

struct Profile_1bc040 {
    Controller_1bc040* FUN_000862c0();
};

struct World {
    char pad[0x54];
    Profile_1bc040* profile;
};

void __cdecl FUN_001bb0b0(const char* key);

// Shows the "controller lost" message for the active port (or for all ports).
void FUN_001bc040()
{
    struct Frame {
        char key[0x100];
        unsigned int cookie;
    } f;
    f.cookie = DAT_004d9968;
    int port = DAT_004dd700->profile->FUN_000862c0()->FUN_000ae960();
    if (port >= 0)
        sprintf(f.key, "TBS_LOST_CONTROLLER_XBOX_PORT_%d", port + 1);
    else
        strcpy(f.key, "TBS_LOST_CONTROLLER_XBOX_ALL");
    FUN_001bb0b0(f.key);
    __security_check_cookie(f.cookie);
}
