class Foo_15afd0 {
  public:
    char pad[0x50];
    float m_rad;
    bool Set(float deg);
};

bool Foo_15afd0::Set(float deg) {
    m_rad = deg * 0.0174532925f;
    return true;
}
