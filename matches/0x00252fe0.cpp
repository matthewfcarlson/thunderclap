class SeqEvent { public: bool vfunc_0(void*); };
class PosHelper { public: bool test(void*); };
class SeqEventVarPosDist { public: virtual int vfunc_0(void*); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); char pad[4]; };
int SeqEventVarPosDist::vfunc_0(void* p) {
  if (((SeqEvent*)this)->vfunc_0(p)) {
    if (((PosHelper*)((char*)this + 8))->test(p)) return 1;
  }
  return 0;
}
