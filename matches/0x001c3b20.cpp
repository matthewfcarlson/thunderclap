class Sub_1c3b20 {
  public:
    void Fn();
};

class C_1c3b20 {
  public:
    char pad[8];
    Sub_1c3b20* mSub;
    void Forward();
};

void C_1c3b20::Forward() {
    mSub->Fn();
}
