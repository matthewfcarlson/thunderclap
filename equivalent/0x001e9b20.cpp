// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001e9b20 @ 0x001e9b20
struct Sound_1e9b20 { char pad[0xc]; int handle; };
extern Sound_1e9b20 *DAT_004e3698;
void *__cdecl FUN_00240750();
void __cdecl FUN_002416c0(void *mixer, int handle, float volume);
void __cdecl FUN_00242f60(void *mixer, int handle, float volume);

class Mixer {
public:
    char pad0[0x514];
    Sound_1e9b20 *current;
    void FUN_001e9b20(unsigned int volume);
};

// Fades the previous sound out, starts the new one at `volume`, and makes it current.
void Mixer::FUN_001e9b20(unsigned int volume)
{
    if (current == 0)
        return;
    Sound_1e9b20 *old = DAT_004e3698;
    if (old != 0) {
        if (FUN_00240750() != 0) {
            void *mixer = FUN_00240750();
            FUN_002416c0(mixer, old->handle, (float)volume);
        }
    }
    Sound_1e9b20 *next = current;
    if (FUN_00240750() != 0) {
        void *mixer = FUN_00240750();
        FUN_00242f60(mixer, next->handle, (float)volume);
    }
    DAT_004e3698 = current;
}
