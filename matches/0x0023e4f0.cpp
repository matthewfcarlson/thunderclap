class Sub {
  public:
    char pad[0x14];
};

class Obj {
  public:
    char pad[0x14];
    Sub sub;
    Sub* Get();
};

Sub* Obj::Get() {
    return &sub;
}
