class Obj_192500 {
  public:
    char pad[0xa8];
    int value;
    int* Get();
};
int* Obj_192500::Get() {
    return &value;
}
