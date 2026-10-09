class SeqEvent { public: virtual int vfunc_0(void *); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
class SeqEventCheck { public: bool CheckBase(void *p); };
bool Read1(void *, void *);
bool Read2(void *, void *);
bool Read3(void *, void *);
class SeqEventChannelVolumes : public SeqEvent { public: int vfunc_0(void *); };
int SeqEventChannelVolumes::vfunc_0(void *p) {
    if (((SeqEventCheck *)this)->CheckBase(p)) {
        if (Read1(p, (char *)this + 0x18)) {
            if (Read2(p, (char *)this + 0x1c)) {
                if (Read3(p, (char *)this + 8)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
