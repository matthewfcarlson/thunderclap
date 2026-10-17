// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventVarPosDist::vfunc_2 @ 0x002532d0
namespace audio {
class SeqEventVarPosDist;
class SeqActionVarPosDist {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    char padding[4];
    SeqEventVarPosDist *event;
    int value;
};
class SeqEventVarPosDist {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void *);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
}
extern "C" void * __cdecl FUN_00247530(void *);
struct ActionList { int FUN_0025dc20(audio::SeqActionVarPosDist *); };
extern char DAT_004e6ff0;
inline void * __cdecl operator new(unsigned int, void *p) { return p; }
int audio::SeqEventVarPosDist::vfunc_2(void *list) {
    void *memory = FUN_00247530(&DAT_004e6ff0);
    audio::SeqActionVarPosDist *action = 0;
    if (memory) {
        action = new (memory) audio::SeqActionVarPosDist;
        action->event = this;
        action->value = 0;
    }
    return ((ActionList *)list)->FUN_0025dc20(action);
}