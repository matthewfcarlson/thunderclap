class Obj {
  public:
    char pad[0x40];
    float m_angle;
    bool Set(float angle);
};

bool Obj::Set(float angle) {
    m_angle = angle * 0.0174532925f;
    return true;
}
