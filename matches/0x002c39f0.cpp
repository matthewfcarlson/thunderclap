namespace pure3d {
class Entity {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[12];
};
} // namespace pure3d
namespace content {
class LoadObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
} // namespace content
extern void work(void*);
namespace pure3d {
class TextBible : public Entity, public content::LoadObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
void TextBible::vfunc_0() {
    TextBible obj;
    work(&obj);
}
} // namespace pure3d