class TextureFontLoader {
  public:
    int a;
    int m4;
    int m8;
    int mc;
    int m10;
    TextureFontLoader();
};
TextureFontLoader::TextureFontLoader() {
    m4 = 0;
    m8 = 0x22000;
    mc = 0;
    m10 = 0;
    *(int*)this = 0x42d1b0;
}