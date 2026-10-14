class C {
  public:
    char pad[0x24];
    float m_rad;
    bool SetRadians(float deg);
};

bool C::SetRadians(float deg) {
    m_rad = deg * 0.01745329252f;
    return true;
}
