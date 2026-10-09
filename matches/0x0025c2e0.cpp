struct AudioDevice {
    void** vt;
};
class OmHalStream {
  public:
    char pad[4];
    AudioDevice* mDevice;
    void vfunc_5(int);
};
void OmHalStream::vfunc_5(int param_2) {
    void* local;
    void** vt = mDevice->vt;
    ((void (*)(void**, void**))vt[4])(vt, &local);
    vt = mDevice->vt;
    ((void (*)(void**, void*))vt[5])(vt, (char*)local + param_2);
}