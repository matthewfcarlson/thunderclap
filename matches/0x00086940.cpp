class A_86940 {
  public:
    void Run();
};
class B_86940 {
  public:
    void Finish();
};
class Thing_86940 {
  public:
    char pad[0x18];
    A_86940* a;
    char pad2[0x14];
    B_86940* b;
    void Run();
};
void Thing_86940::Run() {
    a->Run();
    b->Finish();
}