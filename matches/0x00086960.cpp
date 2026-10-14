extern unsigned char gFlag_86960;
class Other_86960 {
  public:
    void First();
    void Second();
};
class Thing_86960 {
  public:
    char pad[0x30];
    Other_86960* a;
    Other_86960* b;
    void Run();
};
void Thing_86960::Run() {
    gFlag_86960 = 1;
    a->First();
    b->Second();
}