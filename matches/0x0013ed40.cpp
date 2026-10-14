class Obj {
    char pad[0x20];
    float mAngle;

  public:
    bool SetAngle(float angle);
};

bool Obj::SetAngle(float angle) {
    mAngle = angle * 0.0174532925f;
    return true;
}
