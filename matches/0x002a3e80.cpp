extern int vftable;
class RenderObjectLoader {
  public:
    int pad;
    int mValue;
    RenderObjectLoader();
};
RenderObjectLoader::RenderObjectLoader() {
    mValue = 0;
    *(int*)this = (int)&vftable;
}