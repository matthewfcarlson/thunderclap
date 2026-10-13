extern int v[];
class Stream {
  public:
    void Init();
};
void Stream::Init() {
    *(int*)this = (int)v;
}
