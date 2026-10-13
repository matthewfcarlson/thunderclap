// cl-flags: /O1
class Obj {
  public:
    char pad[12];
    int mValue;
    int Get();
};

int Obj::Get() {
    return mValue;
}
