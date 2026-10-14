extern "C" char DAT_0042a1f0[];
class Base_253780 {
  public:
    int a;
    int b;
    Base_253780();
};
class SeqEventVarPitch : public Base_253780 {
  public:
    float value;
    SeqEventVarPitch();
};
SeqEventVarPitch::SeqEventVarPitch() {
    *(int*)this = ((int)DAT_0042a1f0);
    value = 1.0f;
}