// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_002411b0 @ 0x002411b0
#include "decls/data/platform/xbox/unknown.h"

extern "C" void * __cdecl _alloca(unsigned int);
extern "C" void __cdecl thunk_FUN_002710d0(void **, const char *, int, int, int, int, int, int);
namespace DSOUND { extern "C" void __stdcall IDirectSound_DownloadEffectsImage(void *, void *, unsigned int, void *, void *); extern "C" void __cdecl DirectSoundUseFullHRTF(); }
struct SoundGlobal { char pad[0x34]; void *device; };
struct Image {
 virtual void slot0(); virtual void release(); virtual void slot2(); virtual void read(void *buffer, unsigned int size, int flag);
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual unsigned int size();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void reset(); virtual void slot22(); virtual bool valid();
};
void __cdecl FUN_002411b0() {
 Image *image = 0;
 struct DownloadInfo { unsigned int first; unsigned int second; unsigned int third; } info;
 thunk_FUN_002710d0((void **)&image, "img\\dspimage.bin", 0, 0, 1, 0, 1, 1);
 image->reset();
 if (image->valid()) {
   char *buffer = (char *)_alloca((image->size() + 3) & ~3);
   image->read(buffer, image->size(), 1);
   image->reset();
   info.first = 0; info.second = 1; info.third = 0;
   DSOUND::IDirectSound_DownloadEffectsImage((*(SoundGlobal**)&DAT_004e5ce0)->device, buffer, image->size(), &info.first, &info.third);
 }
 DSOUND::DirectSoundUseFullHRTF();
 if (image) image->release();
}
