class Inner_24580 {
  public:
    void Call(int);
};
class Holder_24580 {
  public:
    char pad[0x44];
    Inner_24580* inner;
};
class Obj_24580 {
  public:
    Holder_24580* owner;
    int pad[2];
    int count;
    int values[1];
    void Target(int unused);
};
void Obj_24580::Target(int unused) {
    for (int i = 0; i < count; ++i)
        owner->inner->Call(values[i]);
}
