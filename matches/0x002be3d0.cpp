class Other {
  public:
    void call(void*);
};
class Sprite {
    char pad[0x78];

  public:
    void vfunc_11(Other*);
};
void Sprite::vfunc_11(Other* obj) {
    obj->call((char*)this + 0x78);
}
