class Helper { public: unsigned getA(); unsigned getB(); };
class StreamStringReader {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual bool vfunc_6();
    char pad[8]; Helper *field_c; char pad10; bool field11;
};
bool StreamStringReader::vfunc_6() {
    if (field11) return false;
    unsigned a = field_c->getA();
    unsigned b = field_c->getB();
    return a >= b;
}