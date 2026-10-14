class Obj_f72c0 {
  public:
    char pad[0x18];
    unsigned long* data;
    unsigned long long Get(int index);
};
unsigned long long Obj_f72c0::Get(int index) {
    return ((unsigned long long*)data)[index];
}