typedef unsigned char u8;
struct Buf { u8 d[32]; void init(); void fini(); };
u8 __cdecl seq_helper(int, Buf*);
namespace audio {
struct SeqEvent {
  virtual void vfunc_0();
  virtual u8 vfunc_1(int);
  virtual void vfunc_2();
  virtual void vfunc_3();
  virtual void vfunc_4();
  virtual void vfunc_5();
};
}
u8 audio::SeqEvent::vfunc_1(int p) {
  Buf b;
  b.init();
  u8 r = seq_helper(p, &b);
  b.fini();
  return r;
}
