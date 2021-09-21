#ifndef I_INSTRUCTION_HPP
# define I_INSTRUCTION_HPP

# include "Mindopen.hpp"

class IInstruction {
public:
    virtual ~IInstruction(void) {}

    virtual char get_op() const = 0;
    virtual void execute(Mindopen &mindopen) = 0;
};

#endif
