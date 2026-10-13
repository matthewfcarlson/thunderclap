class Obj {
  public:
    char pad[0x20];
    float mValue;
    float Get();
};

float Obj::Get() {
    return mValue;
}
