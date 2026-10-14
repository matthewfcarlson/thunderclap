class Obj_16f4d0 {
  public:
    char pad[0x40];
    float m_angle;
    bool Set(float angle);
};

bool Obj_16f4d0::Set(float angle) {
    m_angle = angle * 0.0174532925f;
    return true;
}
