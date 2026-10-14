typedef unsigned char byte_15cec0;
struct H {
    char p[8];
    void f();
};
extern char vft_15cec0[];
void release_obj(void* p);
struct GrappleLocomotionSteerTrack {
    void* vt;
    char pad[0x14];
    H h18, h20, h28, h30, h38;
    void g();
    GrappleLocomotionSteerTrack* vfunc_5(byte_15cec0 flag);
};
GrappleLocomotionSteerTrack* GrappleLocomotionSteerTrack::vfunc_5(byte_15cec0 flag) {
    vt = vft_15cec0;
    h38.f();
    h30.f();
    h28.f();
    h20.f();
    h18.f();
    g();
    if (flag & 1)
        release_obj(this);
    return this;
}
