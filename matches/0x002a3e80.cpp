extern int vftable_2a3e80;
class RenderObjectLoader {
  public:
    int pad;
    int mValue;
    RenderObjectLoader();
};
RenderObjectLoader::RenderObjectLoader() {
    mValue = 0;
    *(int*)this = (int)&vftable_2a3e80;
}