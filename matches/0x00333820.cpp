class Body_333820 {
  public:
    char pad[0x70];
    int mX;
    void Helper();
    void SetX(int v);
};

void Body_333820::SetX(int v) {
    mX = v;
    Helper();
}
