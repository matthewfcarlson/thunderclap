class Object {
    char pad[0x30];

  public:
    Object* vfunc_7();
};
Object* Object::vfunc_7() {
    return (Object*)((char*)this + 0x30);
}