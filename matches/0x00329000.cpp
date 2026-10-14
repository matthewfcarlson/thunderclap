class d3dVertexProgram {
  public:
    virtual void Fn();
    virtual ~d3dVertexProgram();
    d3dVertexProgram();
};

void d3dVertexProgram::Fn() {}

d3dVertexProgram::~d3dVertexProgram() {}

d3dVertexProgram::d3dVertexProgram() {
    Fn();
}
