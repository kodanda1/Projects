#include "gtest/gtest.h"
#include <pch.h>
#include <Aquarium.h>
#include <FishBeta.h>
#include <ids.h>
using namespace std;

TEST(AquariumTest, Construct){
    Aquarium aquarium;
}

TEST(AquariumTest, HitTest) {
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty aquarium";

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    fish1->SetLocation(100, 200);
    aquarium.Add(fish1);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
                                                     L"Testing fish at 100, 200";

    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
    fish2->SetLocation(100, 200);
    aquarium.Add(fish2);
    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish2) <<
                                                     L"Testing fish2 at 100, 200";
    ASSERT_EQ(aquarium.HitTest(300, 400), nullptr) <<
                                                     L"Testing fish at 300, 400";


}