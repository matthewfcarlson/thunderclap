struct Sub {
    char pad[0x38];
    char value;
};
class Obj {
  public:
    Sub sub;
    char* Get();
};
char* Obj::Get() {
    return &sub.value;
}
