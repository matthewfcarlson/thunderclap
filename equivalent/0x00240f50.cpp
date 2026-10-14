// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 28/30, incomplete)
// FUN_00240f50 @ 0x00240f50
struct SoundState_240f50 {char pad0[0x1c]; int list; int pad20; unsigned int timestamp; char pad28[0xc]; void* device; unsigned int current[12]; unsigned int desired[12]; char pad98[4]; float volume; float fadeOut; float fadeIn; unsigned char active;};
extern SoundState_240f50* DAT_004e5ce0;
extern unsigned int __cdecl FUN_00267f80(); extern void* __cdecl FUN_00257ec0(void*); extern void* __cdecl FUN_00257ee0(void*); extern void __cdecl FUN_00258f90(void*, int);
namespace DSOUND {extern void __stdcall IDirectSound_SetI3DL2Listener(void*, void*, int); extern void __stdcall IDirectSound_CommitDeferredSettings(void*); extern int __cdecl DirectSoundDoWork();}
int __cdecl FUN_00240f50() {
 unsigned int now = FUN_00267f80(); SoundState_240f50* state = DAT_004e5ce0;
 unsigned int elapsed = now > state->timestamp ? now - state->timestamp : state->timestamp - now;
 state->timestamp = now; state = DAT_004e5ce0;
 if (!state->active) { if (state->volume > 0.0f) { if (state->fadeOut > 0.0f) state->volume -= (float)elapsed / state->fadeOut; else state->volume = 0.0f; } state = DAT_004e5ce0; if (state->volume < 0.0f) {state->volume = 0.0f; state = DAT_004e5ce0;} }
 if (state->active) {if (state->volume < 1.0f) {if (state->fadeIn > 0.0f) state->volume += (float)elapsed / state->fadeIn; else state->volume = 1.0f; state = DAT_004e5ce0;} if (state->volume > 1.0f) {state->volume = 1.0f; state = DAT_004e5ce0;} }
 void* item = FUN_00257ec0(&state->list);
 while (item) {FUN_00258f90(item, 0); item = FUN_00257ee0(item);}
 state = DAT_004e5ce0;
 if (!state->active && state->volume == 0.0f) {state->active = 1; for (int i=0;i<12;++i) {state = DAT_004e5ce0; state->current[i] = state->desired[i];} state = DAT_004e5ce0; DSOUND::IDirectSound_SetI3DL2Listener(state->device,state->current,1); state = DAT_004e5ce0;}
 DSOUND::IDirectSound_CommitDeferredSettings(state->device); return DSOUND::DirectSoundDoWork();
}