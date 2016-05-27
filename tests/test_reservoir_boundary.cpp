#include "../../tests/test_fixture_case.h"

namespace {

    class ReservoirBoundaryTest : public CaseTestFixture {


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
        EXPECT_TRUE(true);
    }
}
