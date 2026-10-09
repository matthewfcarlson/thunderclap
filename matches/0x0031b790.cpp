class Base {
  public:
    Base();
};
extern int device_vftable;
class Device {
  public:
    Base base;
    Device();
};
Device::Device() {
    *(int*)this = (int)&device_vftable;
}
