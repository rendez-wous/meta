/**
 * @file smooth_hinge.cpp
 * @author Chase Geigle
 */

#include "classify/loss/smooth_hinge.h"

namespace meta
{
namespace classify
{
namespace loss
{

const util::string_view smooth_hinge::id = "smooth-hinge";

double smooth_hinge::loss(double prediction, double expected) const
{
    double z = prediction * expected;
    if (z <= 0)
        return 0.5 - z;
    if (z >= 1)
        return 0;
    return 0.5 * (1 - prediction * expected) * (1 - prediction * expected);
}

double smooth_hinge::derivative(double prediction, double expected) const
{
    double z = prediction * expected;
    if (z <= 0)
        return -expected;
    if (z >= 1)
        return 0;
    return -expected * (1 - z);
}
}
}
}
