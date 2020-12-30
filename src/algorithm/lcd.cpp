//---------------------------------------------------------------------------------------------------------------------
// function: least common denominator
//---------------------------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb 
{
    void Calc::lcd(Calc& a, Calc& b)
    {
        if(a.whole_ != Zero.whole_){
            brb::log("not improper fraction", "");
            a.imp_frac();
        }
        if(b.whole_ != Zero.whole_){
            brb::log("not improper fraction", "");
            b.imp_frac();
        }
        a.mul_alg(a.numerator_, b.denominator_);
        b.mul_alg(b.numerator_, a.denominator_);
        a.mul_alg(a.denominator_, b.denominator_);
        b.denominator_ = a.denominator_;
    }
}