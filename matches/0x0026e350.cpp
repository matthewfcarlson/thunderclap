class Primary {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

class Secondary {
  public:
    virtual void vfunc_2() = 0;
};

class ConsoleClient : public Primary, public Secondary {
  public:
    ConsoleClient();
    void vfunc_2();
};

ConsoleClient::ConsoleClient() {}
void ConsoleClient::vfunc_2() {
    int x = 0;
}
