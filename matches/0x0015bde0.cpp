struct Sub { void init(); };
struct HeliLocomotionTrack { char data[0xa0]; void parent(); void ctor(); };
void HeliLocomotionTrack::ctor() {
    Sub* p = (Sub*)((char*)this + 0xa0);
    *(volatile unsigned long*)this = 0x415a40;
    p->init();
    parent();
}
