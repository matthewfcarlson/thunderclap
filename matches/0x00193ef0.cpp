class Base {
  public:
    Base();
    virtual void dummy();
    char pad[4];
};
class Part {
  public:
    Part();
};
class MissilePunchTrack : public Base {
  public:
    MissilePunchTrack();
    char pad2[4];
    int a;
    float b;
    float c;
    Part part;
};
MissilePunchTrack::MissilePunchTrack() : Base(), a(0), b(-1.0f), c(6.2831855f), part() {
    *(int*)((char*)this + 8) = 1;
}