class Base_3223a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(unsigned int);
    virtual void f7();
    virtual void f8();
};
struct Data_3223a0 {
    char pad[0x154];
    unsigned int field;
};
struct Inner_3223a0 {
    char pad[0x204];
    Data_3223a0* data;
};
class pure3d_d3dExtVertexProgram : public Base_3223a0 {
  public:
    Inner_3223a0* ptr;
    virtual void f6(unsigned int);
};
void pure3d_d3dExtVertexProgram::f6(unsigned int x) {
    ptr->data->field = x;
}