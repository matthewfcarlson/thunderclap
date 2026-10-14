class Obj_24b2d0 {
  public:
    char pad[0x78];
    unsigned char index;
    unsigned char enabled;
    Obj_24b2d0* Get();
};
Obj_24b2d0* Obj_24b2d0::Get() {
    if (!enabled)
        return 0;
    return (Obj_24b2d0*)((char*)this + index * 12);
}