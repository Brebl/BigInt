// --------------------------------------------------------------------------------------------------------------------
// function:    turn number to improper fraction
// --------------------------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
    void Calc::imp_frac()
    {
        // example: 2 3/8 -> 19/8
        if(this->denominator_ == Zero.numerator_){
            this->denominator_ = One.whole_;
        }
        this->mul_alg(this->whole_, this->denominator_);
        this->add_alg(this->numerator_, this->whole_);
        this->whole_ = Zero.whole_;
    }
}
