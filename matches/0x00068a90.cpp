// cl-flags: /O1
class Obj {
  public:
    char pad[0x44];
    float value;
    char Set(float angle);
};
char Obj::Set(float angle) {
    value = angle * 0.0174532923847437f;
    return 1;
}
