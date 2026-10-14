extern "C" char DAT_00415a40[];
struct Sub_15bde0 {
    void init();
};
struct HeliLocomotionTrack {
    char data[0xa0];
    void parent();
    void ctor();
};
void HeliLocomotionTrack::ctor() {
    Sub_15bde0* p = (Sub_15bde0*)((char*)this + 0xa0);
    *(volatile unsigned long*)this = ((int)DAT_00415a40);
    p->init();
    parent();
}
