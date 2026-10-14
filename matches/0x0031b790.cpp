class Base_31b790 {
  public:
    Base_31b790();
};
extern int device_vftable;
class Device_31b790 {
  public:
    Base_31b790 base;
    Device_31b790();
};
Device_31b790::Device_31b790() {
    *(int*)this = (int)&device_vftable;
}
