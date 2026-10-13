class Body {
  public:
    Body* GetBody();
};
Body* Body::GetBody() {
    return (Body*)((char*)this + 0x20);
}
