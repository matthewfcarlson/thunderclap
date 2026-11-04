class Obj_16f210 {
  public:
    virtual void V();
    char pad[12];
    char SetTimeEnd_0016f210(int value);
};
char Obj_16f210::SetTimeEnd_0016f210(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}