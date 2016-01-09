#ifndef TERMINALPP_LAYOUTS_GRID_LAYOUT_HPP_
#define TERMINALPP_LAYOUTS_GRID_LAYOUT_HPP_

#include "terminalpp/rectangle.hpp"
#include <boost/any.hpp>
#include <vector>

namespace terminalpp { 

namespace views {
    class view;
}

namespace layouts {

class TERMINALPP_EXPORT grid_layout
{
public :
    //* =====================================================================
    /// \brief Constructor
    //* =====================================================================
    constexpr grid_layout(terminalpp::extent const &dimensions)
      : dimensions_(dimensions)
    {
    }

    //* =====================================================================
    /// \brief Returns the preferred size of this layout.
    /// \par
    /// The preferred size of the layout is the size that the layout would be
    /// if all views in it were at their preferred sizes.
    //* =====================================================================
    terminalpp::extent get_preferred_size(
        std::vector<terminalpp::extent> const &preferred_sizes,
        std::vector<boost::any>         const &hints) const;

    //* =====================================================================
    /// \brief Performs a layout of the specified components within the
    /// specified bounds.
    /// \returns a vector of the rectangles that the views should be 
    /// positioned and sized to in order to fulfil this layout.
    //* =====================================================================
    std::vector<terminalpp::rectangle> do_layout(
        std::vector<terminalpp::extent> const &preferred_sizes,
        std::vector<boost::any>         const &hints,
        terminalpp::extent                     size) const;
        
private :
    terminalpp::extent dimensions_;
};

}}

#endif
