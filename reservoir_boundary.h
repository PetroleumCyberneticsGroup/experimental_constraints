#ifndef FIELDOPT_RESERVOIRBOUNDARY_H
#define FIELDOPT_RESERVOIRBOUNDARY_H

#include "../constraints/constraint.h"

namespace Optimization { namespace Constraints {

        class ReservoirBoundary : public Constraint {


        public:
            ReservoirBoundary(const Utilities::Settings::Optimizer::Constraint &settings,
                              Model::Properties::VariablePropertyContainer *variables);

            virtual bool CaseSatisfiesConstraint(Case *c);

            virtual void SnapCaseToConstraints(Case *c);


        };

    }
}


#endif //FIELDOPT_RESERVOIRBOUNDARY_H
