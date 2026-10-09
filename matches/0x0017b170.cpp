typedef unsigned int u32;
extern int desc1;
extern int desc2;
int __cdecl check(void* obj, int z, void* d1, void* d2, int z2);
void* __cdecl alloc(int size);
struct Result { int init(void* self, void* p); };
struct Track {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
  virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual void v8(); virtual void v9();
  virtual int v10(u32, u32, void*);
};
struct JointPivotTrackerTrack : Track {
  int v10(u32 a, u32 b, void* c);
};
int JointPivotTrackerTrack::v10(u32 a, u32 b, void* c) {
  if (check(c, 0, &desc1, &desc2, 0)) {
    Result* p = (Result*)alloc(0x84);
    if (p) return p->init(this, c);
  }
  return 0;
}
