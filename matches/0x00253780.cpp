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
    *(int*)this = 0x42a1f0;
    value = 1.0f;
}