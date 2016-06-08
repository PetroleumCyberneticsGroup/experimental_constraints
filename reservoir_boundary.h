#ifndef FIELDOPT_RESERVOIRBOUNDARY_H
#define FIELDOPT_RESERVOIRBOUNDARY_H

#include <constraints/well_spline_constraint.h>
#include "Optimization/constraints/constraint.h"
#include "Optimization/constraints/well_spline_constraint.h"
#include "Model/reservoir/grid/grid.h"

namespace Optimization {
    namespace Constraints {

        /*!
         * \brief The ReservoirBoundary class deals with imposing and checking reservoir boundary constraints
         *
         *  The class takes a boundary as input in the form of i,j and k min,max, i.e. a 'box' in
         *  the grid i,j,k coordinates. It can check wether or not a single well is inside the
         *  given box domain and, if needed, project the well onto the domain.
         */
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
