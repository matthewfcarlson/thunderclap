class SeqEvent { public: virtual int vfunc_0(void*); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
class SeqEventB { public: virtual bool vfunc_0(void*); };
class TempoCheck { public: bool check(void*); };
bool __cdecl CheckTempoData(void*, void*);
class SeqEventVarTempo : public SeqEvent { public: char pad[4]; virtual int vfunc_0(void*); };
int SeqEventVarTempo::vfunc_0(void* p) {
  if (((SeqEventB*)this)->SeqEventB::vfunc_0(p) && ((TempoCheck*)((char*)this+8))->check(p) && CheckTempoData(p, (char*)this+0x10)) return 1;
  return 0;
}
