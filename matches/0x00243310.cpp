// om::EntityType's constructor: the om::Type constructor (0x002584d0) with the two type keys, then the own field.
// The base class is named by its constructor's address so that the native links bind the call by address; the two
// keys are passed by address (the callers' references).
typedef unsigned __int64 U64_243310;
class FUN_002584d0 {
  public:
    virtual void f();
    char pad[0x64];
    FUN_002584d0(const U64_243310*, const U64_243310*, int, int);
};
class EntityType : public FUN_002584d0 {
  public:
    EntityType(const U64_243310*, const U64_243310*, int, int, int);
    int value;
    virtual void f();
};
EntityType::EntityType(const U64_243310* a, const U64_243310* b, int c, int d, int e)
    : FUN_002584d0(a, b, d, e), value(c) {}
