// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00258f40 @ 0x00258f40
struct SoundBuffer_258f40 { char pad[0x7c]; void *handle; };
struct SoundInfo { char pad[0x14]; unsigned flags; };
struct SoundPlayer { char pad0[0x20]; SoundBuffer_258f40 *buffers[16]; SoundInfo *info; unsigned char FUN_00258f40(); };
namespace DSOUND { int __stdcall IDirectSoundBuffer_GetStatus(void *, unsigned *); }
// equiv-conv: FUN_00258f40 eax
unsigned char SoundPlayer::FUN_00258f40()
{
    unsigned count = (info->flags >> 4) & 31;
    for (unsigned i = 0; i < count; ++i) {
        unsigned status;
        DSOUND::IDirectSoundBuffer_GetStatus(buffers[i]->handle, &status);
        if (status & 1) return 1;
    }
    return 0;
}
