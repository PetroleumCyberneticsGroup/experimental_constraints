#ifndef FIELDOPT_RESERVOIRBOUNDARY_H
#define FIELDOPT_RESERVOIRBOUNDARY_H

#include <constraints/well_spline_constraint.h>
#include "../constraints/constraint.h"
#include "../constraints/well_spline_constraint.h"
#include "../../Model/reservoir/grid/grid.h"

namespace Optimization { namespace Constraints {

class ReservoirBoundary : public Constraint, WellSplineConstraint
{
public:
    ReservoirBoundary(const Utilities::Settings::Optimizer::Constraint &settings,
                          Model::Properties::VariablePropertyContainer *variables, Model::Reservoir::Grid::Grid *grid);

    // Constraint interface
public:
    bool CaseSatisfiesConstraint(Case *c);
    void SnapCaseToConstraints(Case *c);

private:
    int imin_, imax_, jmin_, jmax_, kmin_, kmax_;
    QList<int> index_list_;
    Model::Reservoir::Grid::Grid *grid_;
    Well affected_well_;
    QList<int> getListOfCellIndices();

};
    }
}


#endif //FIELDOPT_RESERVOIRBOUNDARY_H
