// om::MetaEntityType's constructor: om::EntityType's (0x00243310), named by its address for the native links.
typedef unsigned __int64 U64_25e6c0;
class FUN_00243310 {
  public:
    FUN_00243310(const U64_25e6c0*, const U64_25e6c0*, int, int, int);
    virtual void f();
};
class MetaEntityType : public FUN_00243310 {
  public:
    MetaEntityType(const U64_25e6c0*, const U64_25e6c0*, int, int, int);
    virtual void f();
};
MetaEntityType::MetaEntityType(const U64_25e6c0* a, const U64_25e6c0* b, int c, int d, int e)
    : FUN_00243310(a, b, c, d, e) {}
