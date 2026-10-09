struct SoundState { char pad[0x14]; unsigned flags; };
extern "C" void __stdcall IDirectSoundBuffer_Stop(int);
extern "C" void __stdcall IDirectSoundBuffer_GetCurrentPosition(int, int*, unsigned);
struct Object { char pad0[8]; int state; char pad1[0x0c]; int pos; int gap; int buffers[1]; char pad2[0x3c]; SoundState* sound; };
void __cdecl FUN_00258e50(Object* p) {
 p->state=2;
 unsigned n=(p->sound->flags>>4)&0x1f;
 if (n <= 0u) return;
 int* out = &p->pos;
 int* b = &p->buffers[0];
 do {
   IDirectSoundBuffer_Stop(*(int*)((char*)*b+0x7c));
   IDirectSoundBuffer_GetCurrentPosition(*(int*)((char*)*b+0x7c),out,0);
   ++b;
 } while(--n);
}
