class Thing {
  public:
    float Get();
};
class Owner {
    char pad[0xb8];
    Thing* thing;

  public:
    float Get();
};
float Owner::Get() {
    if (thing)
        return thing->Get();
    return -1.0f;
}