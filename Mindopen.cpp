#include "Mindopen.hpp"

IInstruction *Mindopen::_createNextInstruction(void) {
    return (new NextInstruction());
}

IInstruction *Mindopen::_createPrevInstruction(void) {
    return (new PrevInstruction());
}

IInstruction *Mindopen::_createIncInstruction(void) {
    return (new IncInstruction());
}

IInstruction *Mindopen::_createDecInstruction(void) {
    return (new DecInstruction());
}

IInstruction *Mindopen::_createPrintInstruction(void) {
    return (new PrintInstruction());
}

IInstruction *Mindopen::_createInputInstruction(void) {
    return (new InputInstruction());
}

IInstruction *Mindopen::_createWhileBeginInstruction(void) {
    return (new WhileBeginInstruction());
}

IInstruction *Mindopen::_createWhileEndInstruction(void) {
    return (new WhileEndInstruction());
}

Mindopen::Mindopen(void) {
    this->_arr = new std::vector<char>(30000, 0);
    this->_it = this->_arr->begin();
}

Mindopen::Mindopen(Mindopen const &src) {
    this->_arr = new std::vector<char>(*src._arr);
    this->_it = this->_arr->begin();
}

Mindopen::~Mindopen(void) {
    delete this->_arr;
    while (!this->_instrs.empty()) {
        IInstruction *instr = this->_instrs.front();
        delete instr;
        this->_instrs.pop_front();
    }
}

Mindopen &Mindopen::operator =(Mindopen const &other) {
    delete this->_arr;
    this->_arr = new std::vector<char>(*other._arr);
    return (*this);
}

void Mindopen::pushInstruction(char op) {
    IInstruction *(*methods[])(void) = {
        &Mindopen::_createNextInstruction,
        &Mindopen::_createPrevInstruction,
        &Mindopen::_createIncInstruction,
        &Mindopen::_createDecInstruction,
        &Mindopen::_createPrintInstruction,
        &Mindopen::_createInputInstruction,
        &Mindopen::_createWhileBeginInstruction,
        &Mindopen::_createWhileEndInstruction
    };
    char ops[] = {'>', '<', '+', '-', '.', ',', '[', ']'};

    for (int i = 0; i < 8; i++) {
        if (ops[i] == op) {
            this->_instrs.push_back(methods[i]());
            return ;
        }
    }

    throw WrongInstructionException();
}

void Mindopen::incInstr() {
    if (this->_instr == --this->_instrs.end())
        throw CycleException();

    this->_instr++;
}

void Mindopen::decInstr() {
    if (this->_instr == this->_instrs.begin())
        throw CycleException();

    this->_instr--;
}

void Mindopen::incCell() {
    if (this->_it == --this->_arr->end())
        throw OutOfMemoryException();
    this->_it++;
};

void Mindopen::decCell() {
    if (this->_it == this->_arr->begin())
        throw OutOfMemoryException();
    this->_it--;
};

std::vector<char>::iterator Mindopen::getCell() {
    return (this->_it);
}

char Mindopen::getCurrentOp() const {
    return ((*this->_instr)->get_op());
}

void Mindopen::execute(void) {
    this->_instr = this->_instrs.begin();
    while (this->_instr != this->_instrs.end()) {
        (*this->_instr)->execute(*this);
        this->_instr++;
    }
}

const char *Mindopen::WrongInstructionException::what() const throw() {
    return ("Wrong instruction");
}

const char *Mindopen::CycleException::what() const throw() {
    return ("Cycle error");
}

const char *Mindopen::OutOfMemoryException::what() const throw() {
    return ("Out of memory");
}
