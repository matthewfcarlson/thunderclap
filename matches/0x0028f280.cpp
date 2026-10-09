extern int shaderVtable;
class ShaderLoader {
  public:
    int vptr;
    int a;
    int b;
    int c;
    int d;
    ShaderLoader();
};
ShaderLoader::ShaderLoader() {
    a = 0;
    b = 0x11000;
    c = 0;
    d = 0;
    vptr = (int)&shaderVtable;
}