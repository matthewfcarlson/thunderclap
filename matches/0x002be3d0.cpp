class Other_2be3d0 {
  public:
    void call(void*);
};
class Sprite {
    char pad[0x78];

  public:
    void vfunc_11(Other_2be3d0*);
};
void Sprite::vfunc_11(Other_2be3d0* obj) {
    obj->call((char*)this + 0x78);
}
