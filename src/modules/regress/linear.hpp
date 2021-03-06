/* ----------------------------------------------------------------------- *//**
 *
 * @file linear.hpp
 *
 *//* ----------------------------------------------------------------------- */

#ifndef MADLIB_REGRESS_LINEAR_H
#define MADLIB_REGRESS_LINEAR_H

#include <modules/common.hpp>

namespace madlib {

namespace modules {

namespace regress {

/**
 * @brief Linear-regression functions
 */
struct LinearRegression {
    enum What { kCoef, kRSquare, kTStats, kPValues };
    
    class TransitionState;
    
    static AnyValue transition(AbstractDBInterface &db, AnyValue args);
    static AnyValue mergeStates(AbstractDBInterface &db, AnyValue args);
    
    static AnyValue coefFinal(AbstractDBInterface &db, AnyValue args);
    static AnyValue RSquareFinal(AbstractDBInterface &db, AnyValue args);
    static AnyValue tStatsFinal(AbstractDBInterface &db, AnyValue args);
    static AnyValue pValuesFinal(AbstractDBInterface &db, AnyValue args);
    
    template <What what>
    static AnyValue final(AbstractDBInterface &db, const TransitionState &state);
};

} // namespace regress

} // namespace modules

} // namespace regress

#endif
