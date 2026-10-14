class Obj_193960 {
  public:
    char pad[0x54];
    int mValue;
    bool SetThing(int value);
};

bool Obj_193960::SetThing(int value) {
    mValue = value;
    return true;
}