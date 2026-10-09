typedef unsigned int u32;
struct JointRelativeTrack {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
  virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
  virtual int v10(u32 a, u32 b, u32 c);
};
struct Result { int Init(JointRelativeTrack*, u32); };
extern int __cdecl Check5(u32, int, void*, void*, int);
extern void* __cdecl Alloc(int);
extern char g_a;
extern char g_b;
int JointRelativeTrack::v10(u32 a, u32 b, u32 c) {
  if (Check5(c, 0, &g_b, &g_a, 0)) {
    Result* r = (Result*)Alloc(100);
    if (r) return r->Init(this, c);
  }
  return 0;
}
