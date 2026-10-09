extern unsigned char gFlag;
class Other {
  public:
    void First();
    void Second();
};
class Thing {
  public:
    char pad[0x30];
    Other* a;
    Other* b;
    void Run();
};
void Thing::Run() {
    gFlag = 1;
    a->First();
    b->Second();
}