#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

# include <exception>
# include <vector>
# include <list>
# include <stack>

class IInstruction;
class Mindopen;

# include "instructions.hpp"

class Mindopen {
    std::vector<char>                         *_arr;
    std::vector<char>::iterator               _it;
    std::list<IInstruction *>                 _instrs;
    std::list<IInstruction *>::const_iterator _instr;

    static IInstruction *_createNextInstruction(void);
    static IInstruction *_createPrevInstruction(void);
    static IInstruction *_createIncInstruction(void);
    static IInstruction *_createDecInstruction(void);
    static IInstruction *_createPrintInstruction(void);
    static IInstruction *_createInputInstruction(void);
    static IInstruction *_createWhileBeginInstruction(void);
    static IInstruction *_createWhileEndInstruction(void);

public:
    Mindopen(void);
    Mindopen(Mindopen const &src);

    ~Mindopen(void);

    Mindopen &operator =(Mindopen const &other);

    void pushInstruction(char op);

    void incInstr();
    void decInstr();

    void incCell();
    void decCell();

    std::vector<char>::iterator getCell();

    char getCurrentOp() const;

    void execute(void);

    class WrongInstructionException: public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class CycleException: public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class OutOfMemoryException: public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif
