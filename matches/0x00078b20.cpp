extern const float g_one_78b20;
class Object {
    char pad[0x80];

  public:
    float value;
};
int __fastcall target(Object* self) {
    return self->value == g_one_78b20;
}