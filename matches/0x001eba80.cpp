extern const float Zero_1eba80;
extern const float Limit;
class Inner_1eba80 {
  public:
    void Set(float);
};
struct Holder_1eba80 {
    Inner_1eba80* obj;
};
class C_1eba80 {
  public:
    Holder_1eba80* holder;
    char pad[0x10];
    float value;
    void F(float x);
};
void C_1eba80::F(float x) {
    if (!(x < Zero_1eba80) && !(x > Limit)) {
        holder->obj->Set(x);
        value = x;
    }
}
