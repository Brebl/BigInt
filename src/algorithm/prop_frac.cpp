//---------------------------------------------------------------------------------------------------------------------
// function:    turn improper to proper fraction
//---------------------------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
    void Calc::prop_frac()
    {
        // example: 19/8 -> 2 3/8
        this->div_alg(this->numerator_, this->denominator_, this->whole_, this->numerator_, this->denominator_);
        this->downsize(*this);
    }
}