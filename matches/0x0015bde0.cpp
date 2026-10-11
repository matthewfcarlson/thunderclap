extern "C" char DAT_00415a40[];
struct Sub {
    void init();
};
struct HeliLocomotionTrack {
    char data[0xa0];
    void parent();
    void ctor();
};
void HeliLocomotionTrack::ctor() {
    Sub* p = (Sub*)((char*)this + 0xa0);
    *(volatile unsigned long*)this = ((int)DAT_00415a40);
    p->init();
    parent();
}
