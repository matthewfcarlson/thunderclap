class Obj_14c830 {
  public:
    char Pad[0x20];
    int Value;
    char Fn(int arg);
};

char Obj_14c830::Fn(int arg) {
    Value = arg;
    return 1;
}
