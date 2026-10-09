class Target {
    char pad[0x14];

  public:
    int value;
    char pad2[4];
    unsigned char flag;
    void Set(int x);
};
void Target::Set(int x) {
    value = x;
    flag = 1;
}