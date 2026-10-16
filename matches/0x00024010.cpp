class Obj {
  public:
    char pad[0x118];
    __int64 value;
    __int64 Get();
};
__int64 Obj::Get() {
    return value;
}