class EntityType_25e6c0 {
  public:
    EntityType_25e6c0(int, int, int, int, int);
    virtual void f();
};
class MetaEntityType : public EntityType_25e6c0 {
  public:
    MetaEntityType(int, int, int, int, int);
    virtual void f();
};
MetaEntityType::MetaEntityType(int a, int b, int c, int d, int e) : EntityType_25e6c0(a, b, c, d, e) {}