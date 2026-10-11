namespace fight {
class Base {
  public:
    Base();
    virtual void V();
};
class TrackFactory : public Base {
  public:
    TrackFactory();
    virtual void V();
};
void TrackFactory::V() {}
TrackFactory::TrackFactory() {}
} // namespace fight
