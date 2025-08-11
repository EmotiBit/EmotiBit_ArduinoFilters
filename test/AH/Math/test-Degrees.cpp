#include <AH/Math/Degrees.hpp>
#include <cmath>
#include <gtest/gtest.h>

using namespace AH;

TEST(Degrees, rad2deg) {
    ASSERT_FLOAT_EQ(rad2deg(PI), 180);
    ASSERT_FLOAT_EQ(rad2deg((float)PI), 180);
    ASSERT_FLOAT_EQ(rad2deg(2 * PI), 360);
    ASSERT_FLOAT_EQ(rad2deg(1.), 57.29577951308232);
}

TEST(Degrees, deg2rad) {
    ASSERT_FLOAT_EQ(deg2rad(180.), PI);
    ASSERT_FLOAT_EQ(deg2rad(360.), 2 * PI);
    ASSERT_FLOAT_EQ(deg2rad(57.29577951308232), 1);
}

TEST(Degrees, deg) {
    ASSERT_FLOAT_EQ(180_deg, PI);
    ASSERT_FLOAT_EQ(360_deg, 2 * PI);
    ASSERT_FLOAT_EQ(57.29577951308232_deg, 1);
}