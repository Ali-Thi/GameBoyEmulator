#pragma once

#include <cpu.hh>
#include <gtest/gtest.h>

class CPUTest : public testing::Test {
protected:
    CPU::CPU cpu;
};