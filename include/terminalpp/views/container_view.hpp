#ifndef TERMINALPP_VIEWS_CONTAINER_VIEW_HPP_
#define TERMINALPP_VIEWS_CONTAINER_VIEW_HPP_

#include "terminalpp/rectangle.hpp"
#include <boost/any.hpp>

namespace terminalpp { namespace views {

class draw_context;
class event_context;

class TERMINALPP_EXPORT container_view
{
public :
    //* =====================================================================
    /// \brief Commands the view to draw a specific region of the component
    /// on to the given context.
    //* =====================================================================
    void draw(draw_context &dc, rectangle const &region) const;

    //* =====================================================================
    /// \brief Returns how large the view thinks it should be in ideal
    /// circumstances.
    //* =====================================================================
    extent get_preferred_size() const;

    //* =====================================================================
    /// \brief Sets the size of the view.
    //* =====================================================================
    void set_size(extent const &size);

    //* =====================================================================
    /// \brief Returns the size of the view.
    //* =====================================================================
    extent get_size() const;

    //* =====================================================================
    /// \brief Sends an arbitrary event to the view.
    //* =====================================================================
    boost::any event(event_context &ec, boost::any const &ev);
};

}}

#endif
