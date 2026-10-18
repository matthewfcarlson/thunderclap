class Sub_1c3b20 {
  public:
    int Fn(int, int);
};

class C_1c3b20 {
  public:
    char pad[8];
    Sub_1c3b20* mSub;
    int Forward(int, int);
};

int C_1c3b20::Forward(int a0, int a1) {
    return mSub->Fn(a0, a1);
}
