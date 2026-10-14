class Obj {
  public:
    char pad[0x54];
    int mValue;
    bool SetThing(int value);
};

bool Obj::SetThing(int value) {
    mValue = value;
    return true;
}