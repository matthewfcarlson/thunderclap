class Body {
  public:
    char pad[0x70];
    int mX;
    void Helper();
    void SetX(int v);
};

void Body::SetX(int v) {
    mX = v;
    Helper();
}
