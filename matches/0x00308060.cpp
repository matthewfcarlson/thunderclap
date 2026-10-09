extern int WorldCollisionObjectLoader_vftable;
class WorldCollisionObjectLoader {
public:
    virtual void Dummy();
    int a;
    int b;
    int c;
    int d;
    WorldCollisionObjectLoader();
};
WorldCollisionObjectLoader::WorldCollisionObjectLoader() {
    a = 0;
    b = 0x07010025;
    c = 0;
    d = 0;
    *(int*)this = (int)&WorldCollisionObjectLoader_vftable;
}
