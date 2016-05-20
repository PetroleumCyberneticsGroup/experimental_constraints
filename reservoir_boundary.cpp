//
// Created by einar on 5/20/16.
//

#include "reservoir_boundary.h"

namespace Optimization { namespace Constraints {

        ReservoirBoundary::ReservoirBoundary(const Utilities::Settings::Optimizer::Constraint &settings,
                                             Model::Properties::VariablePropertyContainer *variables)
                : Constraint(settings, variables) { }

        bool ReservoirBoundary::CaseSatisfiesConstraint(Case *c) {
            return false;
        }

        void ReservoirBoundary::SnapCaseToConstraints(Case *c) {

        }
    }
}
