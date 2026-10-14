class Obj_18ef20 {
    char pad[0x30];

  public:
    char Set(int value);
};
char Obj_18ef20::Set(int value) {
    *((int*)((char*)this + 0x30)) = value;
    return 1;
}
