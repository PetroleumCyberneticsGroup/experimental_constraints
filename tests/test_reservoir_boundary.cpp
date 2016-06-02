#include <gtest/gtest.h>
#include "Optimization/experimental_constraints/reservoir_boundary.h"
#include "Optimization/tests/test_resource_cases.h"
#include "Model/tests/test_resource_grids.h"
#include "Utilities/tests/test_resource_settings.h"


namespace {

    class ReservoirBoundaryTest : public ::testing::Test, public TestResources::TestResourceCases,
                                  public TestResources::TestResourceGrids,
                                  public TestResources::TestResourceSettings {


    public:
        ReservoirBoundaryTest() { }

    public:
        virtual ~ReservoirBoundaryTest() { }

        virtual void TearDown() {

        }

        virtual void SetUp() {

        }
    };

    TEST_F(ReservoirBoundaryTest, Initialization) {

        auto test_boundary = Optimization::Constraints::ReservoirBoundary(constraint_settings_reservoir_boundary_, variable_property_container_, grid_5spot_);

        EXPECT_FALSE(test_boundary.CaseSatisfiesConstraint(test_case_5_));
        test_boundary.SnapCaseToConstraints(test_case_5_);
        EXPECT_TRUE(test_boundary.CaseSatisfiesConstraint(test_case_5_));
    }
}
