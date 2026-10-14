class Obj_1938f0 {
  public:
    char Set(int value);
};
char Obj_1938f0::Set(int value) {
    *((int*)((char*)this + 0x3c)) = value;
    return 1;
}