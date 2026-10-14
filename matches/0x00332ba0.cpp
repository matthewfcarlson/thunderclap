class Obj {
  public:
    char pad[0x88];
    void Set(int value);
};
void Obj::Set(int value) {
    *(int*)((char*)this + 0x88) = value;
}
