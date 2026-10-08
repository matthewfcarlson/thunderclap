class Base { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(unsigned int); virtual void f7(); virtual void f8(); };
struct Data { char pad[0x154]; unsigned int field; };
struct Inner { char pad[0x204]; Data* data; };
class pure3d_d3dExtVertexProgram : public Base { public: Inner* ptr; virtual void f6(unsigned int); };
void pure3d_d3dExtVertexProgram::f6(unsigned int x) { ptr->data->field = x; }