// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 10/10)
// audio::SeqEventContainer::vfunc_5 @ 0x00260910
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void FUN_00344f51_2();
    virtual void FUN_00344f51_3();
    virtual void vfunc_4();
    virtual unsigned int vfunc_5();
    SeqEvent *nextLink;
    char pad[4];
};
struct SeqEventContainer : SeqEvent {
    SeqEvent *firstLink;
    unsigned int vfunc_5();
};
unsigned int SeqEventContainer::vfunc_5() {
    unsigned int maximum = 0;
    SeqEvent *event = firstLink ? (SeqEvent *)((char *)firstLink - 4) : 0;
    while (event) {
        unsigned int value = event->vfunc_5();
        if (value > maximum) maximum = value;
        SeqEvent *link = event->nextLink;
        event = link ? (SeqEvent *)((char *)link - 4) : 0;
    }
    return maximum + 1;
}
}