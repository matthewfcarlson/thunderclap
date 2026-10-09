extern void* file_vft;
extern void* file_vft4;
extern void* ref_vft;

class Sub { public: void fin(); };
class Ref { public: virtual void x(); virtual void y(); };

class File {
public:
 void* vp;
 void* vp4;
 int f8;
 Ref* r;
 char pad[0x11c];
 Sub sub;
 void vfunc_21();
 void shutdown();
};

void File::shutdown() {
 *(void**)this = &file_vft;
 *((void**)this + 1) = &file_vft4;
 vfunc_21();
 r->y();
 sub.fin();
 *(void**)this = &ref_vft;
}
