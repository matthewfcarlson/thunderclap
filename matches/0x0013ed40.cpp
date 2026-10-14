class Obj_13ed40 {
    char pad[0x20];
    float mAngle;

  public:
    bool SetAngle(float angle);
};

bool Obj_13ed40::SetAngle(float angle) {
    mAngle = angle * 0.0174532925f;
    return true;
}
