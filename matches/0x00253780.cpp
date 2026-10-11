extern "C" char DAT_0042a1f0[];
class Base {
  public:
    int a;
    int b;
    Base();
};
class SeqEventVarPitch : public Base {
  public:
    float value;
    SeqEventVarPitch();
};
SeqEventVarPitch::SeqEventVarPitch() {
    *(int*)this = ((int)DAT_0042a1f0);
    value = 1.0f;
}