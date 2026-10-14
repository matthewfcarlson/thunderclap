extern char vtImage[];
extern char vtIRef[];
class Helper_2c0ca0 {
  public:
    void cleanup();
};
void destroy(void*);
void destroyThis(void*);
class ImageLoader {
  public:
    void* vptr;
    char pad[0x10];
    Helper_2c0ca0* mPtr;
    ImageLoader* f2(unsigned char p);
};
ImageLoader* ImageLoader::f2(unsigned char p) {
    Helper_2c0ca0* h = mPtr;
    vptr = vtImage;
    if (h) {
        h->cleanup();
        destroy(h);
    }
    vptr = vtIRef;
    if (p & 1)
        destroyThis(this);
    return this;
}
