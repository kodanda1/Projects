/**
 * @file MachineTest.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "gtest/gtest.h"

#include <MachineFactory.h>
#include <Machine.h>

TEST(MachineTest, Constructor)
{
    MachineFactory factory(L"images");
    auto machine = factory.CreateMachine();

    ASSERT_NE(nullptr, machine);
}

TEST(MachineTest, Location)
{
    MachineFactory factory(L"images");
    auto machine = factory.CreateMachine();

    machine->SetLocation(wxPoint(123, 456));
    auto position = machine->GetLocation();
    ASSERT_EQ(123, position.x);
    ASSERT_EQ(456, position.y);
}

TEST(MachineTest, MachineTime)
{
    MachineFactory factory(L"images");
    auto machine = factory.CreateMachine();

    machine->SetFrameRate(30);
    machine->SetSpeed(1);
    machine->SetMachineFrame(123);

    // The Standin machine does not implment GetMachineTime(), so
    // this test is disabled. You should be able to enable it for your machine

//    ASSERT_NEAR(123.0 / 30.0, machine->GetMachineTime(), 0.001);
//
//    // Speed should not matter
//    machine->SetSpeed(2.0);
//    ASSERT_NEAR(123.0 / 30.0, machine->GetMachineTime(), 0.001);
//
//    // Different frame rate
//    machine->SetFrameRate(15);
//    machine->SetMachineFrame(201);
//    ASSERT_NEAR(201.0 / 15.0, machine->GetMachineTime(), 0.001);
}


TEST(MachineTest, MachineNumber)
{
    MachineFactory factory(L"images");
    auto machine = factory.CreateMachine();

    // Try machine number 1
    machine->SetMachineNumber(1);
    ASSERT_EQ(1, machine->GetMachineNumber());

    // Try machine number 2
    machine->SetMachineNumber(2);
    ASSERT_EQ(2, machine->GetMachineNumber());

    // Ensure we can go back to machine number 1
    machine->SetMachineNumber(1);
    ASSERT_EQ(1, machine->GetMachineNumber());
}