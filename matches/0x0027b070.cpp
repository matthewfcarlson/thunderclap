class Entity {
public:
    int vptr;
    int a;
    int b;
    int c;
    Entity();
};
Entity::Entity() { a=0; vptr=0x42c180; b=0; c=0; }