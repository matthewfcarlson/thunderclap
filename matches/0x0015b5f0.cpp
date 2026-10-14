struct Sub_15b5f0 {
    char pad[0x38];
    char value;
};
class Obj_15b5f0 {
  public:
    Sub_15b5f0 sub;
    char* Get();
};
char* Obj_15b5f0::Get() {
    return &sub.value;
}
