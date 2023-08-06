// https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

#include <gtest/gtest.h>

int
main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}