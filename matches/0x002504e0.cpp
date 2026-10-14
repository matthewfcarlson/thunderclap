class Obj_2504e0 {
  public:
    char pad[8];
    void* Get();
};

void* Obj_2504e0::Get() {
    return (char*)this + 8;
}
