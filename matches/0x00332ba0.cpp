class Obj_332ba0 {
  public:
    char pad[0x88];
    void Set(int value);
};
void Obj_332ba0::Set(int value) {
    *(int*)((char*)this + 0x88) = value;
}
