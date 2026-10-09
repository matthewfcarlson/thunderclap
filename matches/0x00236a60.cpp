class Params {
  public:
    void* x;
    int value;
    Params();
};
Params::Params() : x(0), value(0) {
    x = (void*)0x427f28;
}