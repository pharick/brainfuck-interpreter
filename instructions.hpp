#ifndef INSTRUCTIONS_HPP
# define INSTRUCTIONS_HPP

# include <iostream>
# include "IInstruction.hpp"

class NextInstruction: public IInstruction {
    char const _op;

public:
    NextInstruction(void);
    NextInstruction(NextInstruction const &src);
    ~NextInstruction(void);
    NextInstruction &operator =(NextInstruction const &other);

    char get_op() const;
    void execute(Mindopen &mindopen);
};

class PrevInstruction: public IInstruction {
    char const _op;

public:
    PrevInstruction(void);
    PrevInstruction(PrevInstruction const &src);
    ~PrevInstruction(void);
    PrevInstruction &operator =(PrevInstruction const &other);

    char get_op() const;
    void execute(Mindopen &mindopen);
};

class IncInstruction: public IInstruction {
    char const _op;

public:
    IncInstruction(void);
    IncInstruction(IncInstruction const &src);
    ~IncInstruction(void);
    IncInstruction &operator =(IncInstruction const &other);

    char get_op() const;
    void execute(Mindopen &mindopen);
};

class DecInstruction: public IInstruction {
    char const _op;

public:
    DecInstruction(void);
    DecInstruction(DecInstruction const &src);
    ~DecInstruction(void);
    DecInstruction &operator =(DecInstruction const &other);

    char get_op() const;
    void execute(Mindopen &mindopen);
};

class PrintInstruction: public IInstruction {
    char const _op;

public:
    PrintInstruction(void);
    PrintInstruction(PrintInstruction const &src);
    ~PrintInstruction(void);
    PrintInstruction &operator =(PrintInstruction const &other);

    char get_op() const;
    void execute(Mindopen &mindopen);
};

class InputInstruction: public IInstruction {
    char const _op;

public:
    InputInstruction(void);
    InputInstruction(InputInstruction const &src);
    ~InputInstruction(void);
    InputInstruction &operator =(InputInstruction const &other);

    char get_op() const;
    void execute(Mindopen &mindopen);
};

class WhileBeginInstruction: public IInstruction {
    char const _op;

public:
    WhileBeginInstruction(void);
    WhileBeginInstruction(WhileBeginInstruction const &src);
    ~WhileBeginInstruction(void);
    WhileBeginInstruction &operator =(WhileBeginInstruction const &other);

    char get_op() const;
    void execute(Mindopen &mindopen);
};

class WhileEndInstruction: public IInstruction {
    char const _op;

public:
    WhileEndInstruction(void);
    WhileEndInstruction(WhileEndInstruction const &src);
    ~WhileEndInstruction(void);
    WhileEndInstruction &operator =(WhileEndInstruction const &other);

    char get_op() const;
    void execute(Mindopen &mindopen);
};

#endif
