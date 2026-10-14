class Target_ac790 {
    char pad[0x18];

  public:
    int value;
    unsigned char flag;
    void Set(int x);
};
void Target_ac790::Set(int x) {
    value = x;
    flag = 1;
}