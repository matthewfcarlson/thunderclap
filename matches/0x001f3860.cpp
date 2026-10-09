typedef unsigned char byte;
extern void __cdecl release(void *);
extern void __cdecl destroy(void *);
extern int vtable;
struct CSoundSequenceVoice { int *vf; void *m; CSoundSequenceVoice *FUN_001f3860(byte); };
CSoundSequenceVoice * CSoundSequenceVoice::FUN_001f3860(byte flags) {
 vf=&vtable;
 if(m) { release(m); m=0; }
 if(flags&1) destroy(this);
 return this;
}