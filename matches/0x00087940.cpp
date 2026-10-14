bool Check();
class Thing_87940 {
  public:
    char pad[4];
    int* state;
    void Set(int);
    void StepA();
    void StepB();
    void Target();
};
void Thing_87940::Target() {
    if (!Check())
        Set(1);
    while (*state != 8) {
        StepA();
        if (*state != 8)
            StepB();
    }
    Set(1);
}