// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002beca0 @ 0x002beca0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void* __cdecl FUN_0008d690(unsigned size);
void* __cdecl thunk_FUN_0008d690(unsigned size);
struct ImageConverter_2beca0 { ImageConverter_2beca0* FUN_002de230(); };
class ImageLoader_2beca0 { public: virtual void v0(); ImageLoader_2beca0* FUN_002c0c40(); };
struct Table_2beca0 { Table_2beca0* FUN_002af2d0(); };
namespace pure3d {
class SpriteLoader {
public:
    virtual void v0();
    int f4, f8, fc, f10;
    ImageConverter_2beca0* lookup;
    ImageLoader_2beca0* child;
    Table_2beca0* table;
    char f20, f21;
    SpriteLoader();
};
SpriteLoader::SpriteLoader() {
    f4 = 0;
    f8 = 0x19005;
    fc = 0;
    f10 = 0;
    f20 = 0;
    f21 = 0;
    void* m = FUN_0008d690(4);
    lookup = m ? ((ImageConverter_2beca0*)m)->FUN_002de230() : 0;
    void* c = thunk_FUN_0008d690(0x1c);
    ImageLoader_2beca0* ch = c ? ((ImageLoader_2beca0*)c)->FUN_002c0c40() : 0;
    child = ch;
    ch->v0();
    void* t = FUN_0008d690(0xa4);
    table = t ? ((Table_2beca0*)t)->FUN_002af2d0() : 0;
}
}
