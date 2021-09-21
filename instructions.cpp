#include "instructions.hpp"

NextInstruction::NextInstruction(void): _op('>') {}
NextInstruction::NextInstruction(NextInstruction const &src): _op('>') {
    (void)src;
}
NextInstruction::~NextInstruction(void) {}
NextInstruction &NextInstruction::operator =(NextInstruction const &other) {
    (void)other;
    return (*this);
}

char NextInstruction::get_op() const {
    return (this->_op);
}

void NextInstruction::execute(Mindopen &mindopen) {
    mindopen.incCell();
}

PrevInstruction::PrevInstruction(void): _op('<') {}
PrevInstruction::PrevInstruction(PrevInstruction const &src): _op('<') {
    (void)src;
}
PrevInstruction::~PrevInstruction(void) {}
PrevInstruction &PrevInstruction::operator =(PrevInstruction const &other) {
    (void)other;
    return (*this);
}

char PrevInstruction::get_op() const {
    return (this->_op);
}

void PrevInstruction::execute(Mindopen &mindopen) {
    mindopen.decCell();
}

IncInstruction::IncInstruction(void): _op('+') {}
IncInstruction::IncInstruction(IncInstruction const &src): _op('+') {
    (void)src;
}
IncInstruction::~IncInstruction(void) {}
IncInstruction &IncInstruction::operator =(IncInstruction const &other) {
    (void)other;
    return (*this);
}

char IncInstruction::get_op() const {
    return (this->_op);
}

void IncInstruction::execute(Mindopen &mindopen) {
    std::vector<char>::iterator it = mindopen.getCell();
    (*it)++;
}

DecInstruction::DecInstruction(void): _op('-') {}
DecInstruction::DecInstruction(DecInstruction const &src): _op('-') {
    (void)src;
}
DecInstruction::~DecInstruction(void) {}
DecInstruction &DecInstruction::operator =(DecInstruction const &other) {
    (void)other;
    return (*this);
}

char DecInstruction::get_op() const {
    return (this->_op);
}

void DecInstruction::execute(Mindopen &mindopen) {
    std::vector<char>::iterator it = mindopen.getCell();
    (*it)--;
}

PrintInstruction::PrintInstruction(void): _op('.') {}
PrintInstruction::PrintInstruction(PrintInstruction const &src): _op('.') {
    (void)src;
}
PrintInstruction::~PrintInstruction(void) {}
PrintInstruction &PrintInstruction::operator =(PrintInstruction const &other) {
    (void)other;
    return (*this);
}

char PrintInstruction::get_op() const {
    return (this->_op);
}

void PrintInstruction::execute(Mindopen &mindopen) {
    std::cout << *mindopen.getCell();
}

InputInstruction::InputInstruction(void): _op(',') {}
InputInstruction::InputInstruction(InputInstruction const &src): _op(',') {
    (void)src;
}
InputInstruction::~InputInstruction(void) {}
InputInstruction &InputInstruction::operator =(InputInstruction const &other) {
    (void)other;
    return (*this);
}

char InputInstruction::get_op() const {
    return (this->_op);
}

void InputInstruction::execute(Mindopen &mindopen) {
    *mindopen.getCell() = std::cin.get();
}

WhileBeginInstruction::WhileBeginInstruction(void): _op('[') {}
WhileBeginInstruction::WhileBeginInstruction(WhileBeginInstruction const &src): _op('[') {
    (void)src;
}
WhileBeginInstruction::~WhileBeginInstruction(void) {}
WhileBeginInstruction &WhileBeginInstruction::operator =(WhileBeginInstruction const &other) {
    (void)other;
    return (*this);
}

char WhileBeginInstruction::get_op() const {
    return (this->_op);
}

void WhileBeginInstruction::execute(Mindopen &mindopen) {
    if (*mindopen.getCell())
        return ;

    unsigned int open = 0;

    mindopen.incInstr();
    while (mindopen.getCurrentOp() != ']' || open != 0)
    {
        if (mindopen.getCurrentOp() == '[')
            open++;
        if (mindopen.getCurrentOp() == ']')
            open--;

        mindopen.incInstr();
    }
}

WhileEndInstruction::WhileEndInstruction(void): _op(']') {}
WhileEndInstruction::WhileEndInstruction(WhileEndInstruction const &src): _op(']') {
    (void)src;
}
WhileEndInstruction::~WhileEndInstruction(void) {}
WhileEndInstruction &WhileEndInstruction::operator =(WhileEndInstruction const &other) {
    (void)other;
    return (*this);
}

char WhileEndInstruction::get_op() const {
    return (this->_op);
}

void WhileEndInstruction::execute(Mindopen &mindopen) {
    if (!*mindopen.getCell())
        return ;

    unsigned int open = 0;

    mindopen.decInstr();
    while (mindopen.getCurrentOp() != '[' || open != 0)
    {
        if (mindopen.getCurrentOp() == ']')
            open++;
        if (mindopen.getCurrentOp() == '[')
            open--;

        mindopen.decInstr();
    }
}
