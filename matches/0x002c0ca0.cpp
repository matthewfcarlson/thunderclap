extern char vtImage[];
extern char vtIRef[];
class Helper { public: void cleanup(); };
void destroy(void*);
void destroyThis(void*);
class ImageLoader {
public:
    void* vptr;
    char pad[0x10];
    Helper* mPtr;
    ImageLoader* f2(unsigned char p);
};
ImageLoader* ImageLoader::f2(unsigned char p) {
    Helper* h = mPtr;
    vptr = vtImage;
    if (h) {
        h->cleanup();
        destroy(h);
    }
    vptr = vtIRef;
    if (p & 1) destroyThis(this);
    return this;
}
