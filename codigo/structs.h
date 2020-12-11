#define NILL -1

#define units_n 5

#define inst_n 64

#define register_n 32

enum registers
{
    zero = 0b00000,
    at = 0b00001,
    v0 = 0b00010,
    v1 = 0b00011,
    a0 = 0b00100,
    a1 = 0b00101,
    a2 = 0b00110,
    a3 = 0b00111,
    t0 = 0b01000,
    t1 = 0b01001,
    t2 = 0b01010,
    t3 = 0b01011,
    t4 = 0b01100,
    t5 = 0b01101,
    t6 = 0b01110,
    t7 = 0b01111,
    s0 = 0b10000,
    s1 = 0b10001,
    s2 = 0b10010,
    s3 = 0b10011,
    s4 = 0b10100,
    s5 = 0b10101,
    s6 = 0b10110,
    s7 = 0b10111,
    t8 = 0b11000,
    t9 = 0b11001,
    k0 = 0b11010,
    k1 = 0b11011,
    gp = 0b11100,
    sp = 0b11101,
    fp = 0b11110,
    ra = 0b11111
};

enum units
{
    MULT1 = 0,
    MULT2 = 1,
    DIV = 2,
    ADD = 3,
    LOG = 4
};

enum instructionFormat
{
    R,
    I
};

enum operations
{
    Move = 39,
    Add = 32,
    Sub = 34,
    And = 36,
    Or = 37,
    Slt = 42,
    Mult = 24,
    Div = 26,
    Li = 9,
    Addi = 8,
    Andi = 12,
    Ori = 13
};

typedef struct Instruction_R // R instruction format
{
    unsigned int opcode : 6; // Always zero
    unsigned int rs : 5;     // Origin register 1
    unsigned int rt : 5;     // Origin register 2
    unsigned int rd : 5;     // Destination register
    unsigned int shamt : 5;  // Shift operator
    unsigned int funct : 6;  // Specifies the operation
} Instruction_R;

typedef struct Instruction_I // I instruction format
{
    unsigned int opcode : 6;     // Specifies the operation
    unsigned int rs : 5;         // Origin register
    unsigned int rt : 5;         // Destination register
    unsigned int immediate : 16; // Immediate value
} Instruction_I;

typedef struct FunctionUnity
{
    int name;
    bool busy;
    char *operation;
    unsigned int fi : 5;
    unsigned int fj : 5;
    unsigned int fk : 5;
    int qj;
    int qk;
    int rj; // -1 = NILL, 0 = False, 1 = True
    int rk; // -1 = NILL, 0 = False, 1 = True
    bool clear;
    int instruction_n;
} FunctionUnity;

typedef struct Scoreboarding
{
    FunctionUnity FUs[5];
} Scoreboarding;

typedef struct Pipeline
{
    unsigned int issue;
    int issueCheck : 2;
    unsigned int read;
    int readCheck : 2; // -1 = Can't be done, 0 = Pending, 1 = Done
    unsigned int execute;
    int executeCheck : 2; // -1 = Can't be done, 0 = Pending, 1 = Done
    unsigned int write;
    int writeCheck : 2;
} Pipeline;

typedef struct Instruction
{
    unsigned int type : 1;
    unsigned int operation : 6;
    unsigned int operand1 : 5;  // Destination
    unsigned int operand2 : 5;  // Origin 1
    unsigned int operand3 : 16; // Origin 2 / Immediate
    int value2;
    int value3;
    int FU_name;
    Pipeline pipeline;
} Instruction;

typedef struct InstConfig
{
    int configs[64]; // We have one position for each possible operation in MIPS 32
} InstConfig;

typedef struct RegisterMemory
{
    int value;
    int FU;
} RegisterMemory;

typedef struct thread_info
{
    pthread_t thread_id;
    int thread_num;
    char *configFileName;
    char *outputFileName;
    char *programName;
    int memoryLength;
} thread_info;