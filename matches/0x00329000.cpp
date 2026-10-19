class d3dVertexProgram {
  public:
    virtual void hulk_slot_Fn(); void Fn();
    virtual ~d3dVertexProgram();
    d3dVertexProgram();
};

void d3dVertexProgram::Fn() {}

d3dVertexProgram::~d3dVertexProgram() {}

d3dVertexProgram::d3dVertexProgram() {
    Fn();
}
