void __cdecl Cleanup(int);
class PathLocatorTestCondition {
public:
    int a,b;
    virtual ~PathLocatorTestCondition();
    int d;
    virtual void F();
};
PathLocatorTestCondition::~PathLocatorTestCondition() { Cleanup(d); F(); }