#include "terminalpp/views/container_view.hpp"

namespace terminalpp { namespace views {

void container_view::draw(draw_context &dc, rectangle const &region) const
{
}

extent container_view::get_preferred_size() const
{
    return {};
}

void container_view::set_size(extent const &size)
{
}

extent container_view::get_size() const
{
    return {};
}

boost::any container_view::event(event_context &ec, boost::any const &ev)
{
    return {};
}

}}
