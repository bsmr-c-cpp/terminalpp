#include <terminalpp/views/default_event_context.hpp>
#include <terminalpp/views/event_context.hpp>
#include <gtest/gtest.h>

TEST(default_event_context_test, default_event_context_is_an_event_context)
{
    terminalpp::views::event_context ec{
        terminalpp::views::default_event_context{}};
}