class Object {
  public:
    int GetValue();

    char pad[0x58];
    int mValue;
};

int Object::GetValue() {
    return mValue;
}