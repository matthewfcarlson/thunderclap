class SeqEvent {
public:
    virtual void vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
void Transform(int, void*);
class SeqEventVarVolume : public SeqEvent {
public:
    virtual void vfunc_0(int);
};
void SeqEventVarVolume::vfunc_0(int value) {
    SeqEvent::vfunc_0(value);
    Transform(value, (char*)this + 8);
}