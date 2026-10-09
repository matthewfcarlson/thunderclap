// Same code shape as 0x0011c270 (propagated; names are from that function)
void __cdecl Cleanup(int);
class PathLocatorTestCondition {
public:
    int a,b;
    virtual ~PathLocatorTestCondition();
    int d;
    virtual void F();
};
PathLocatorTestCondition::~PathLocatorTestCondition() { Cleanup(d); F(); }