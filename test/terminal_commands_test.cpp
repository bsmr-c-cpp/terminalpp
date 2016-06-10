#include <terminalpp/terminal.hpp>
#include "expect_sequence.hpp"
#include <gtest/gtest.h>

TEST(terminal_commands, request_device_attributes_writes_correct_sequence)
{
    terminalpp::terminal terminal;
    expect_sequence(
        "\x1B[c",
        terminal.request_device_attributes());
}
