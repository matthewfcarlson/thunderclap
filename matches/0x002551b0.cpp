extern "C" char DAT_0042a45c[];
class Base {
  public:
    Base();
};
class SeqEventLogicOr : public Base {
  public:
    char pad[8];
    int b, c, d;
    float f;
    SeqEventLogicOr();
};
SeqEventLogicOr::SeqEventLogicOr() {
    b = 0;
    c = 0;
    d = 0;
    *(int*)this = ((int)DAT_0042a45c);
    f = 0.5f;
}