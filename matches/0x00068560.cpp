class Obj_68560 {
  public:
    char pad[0x10];
    int mValue;
    char SetTimeEnd_00068560(int value);
};

char Obj_68560::SetTimeEnd_00068560(int value) {
    mValue = value;
    return 1;
}