struct V {
    float x, y, z;
};
class Obj {
    char pad[0xb8];
    V angles;

  public:
    V Get();
};
V Obj::Get() {
    V result;
    result.x = angles.x * 57.295776f;
    result.y = angles.y * 57.295776f;
    result.z = angles.z * 57.295776f;
    return result;
}