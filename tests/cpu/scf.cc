#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SCF_0_TO_1)
{
    cpu.scf();
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), CARRY_FLAG_BYTE_MASK);
}

TEST_F(CPUTest, SCF_1_TO_0)
{
    cpu.set8byteRegister(CPU::R8::F, CARRY_FLAG_BYTE_MASK);
    cpu.scf();
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), CARRY_FLAG_BYTE_MASK);
}