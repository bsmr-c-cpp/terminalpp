#ifndef TERMINALPP_LAYOUT_HPP_
#define TERMINALPP_LAYOUT_HPP_

#include "terminalpp/rectangle.hpp"
#include <boost/any.hpp>
#include <memory>
#include <utility>

namespace terminalpp { 

namespace views {
    class view;
}

namespace layouts {

//* =========================================================================
/// \brief A Concept class that encapsulates everything necessary for a view
/// to lay its components out.
//* =========================================================================
class layout
{
public :
    template <class Model>
    explicit layout(Model &&mdl)
      : self_(new model<Model>(std::forward<Model>(mdl)))
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
        std::vector<boost::any>         const &hints) const
    {
        return self_->get_preferred_size(preferred_sizes, hints);
    }

    //* =====================================================================
    /// \brief Performs a layout of the specified components within the
    /// specified bounds.
    /// \returns a vector of the rectangles that the views should be 
    /// positioned and sized to in order to fulfil this layout.
    //* =====================================================================
    std::vector<terminalpp::rectangle> do_layout(
        std::vector<terminalpp::extent> const &preferred_sizes,
        std::vector<boost::any>         const &hints,
        terminalpp::extent                     size) const
    {
        return self_->do_layout(preferred_sizes, hints, size);
    }

private :
    struct concept
    {
        virtual ~concept(){}
        virtual terminalpp::extent get_preferred_size(
            std::vector<terminalpp::extent> const &preferred_sizes,
            std::vector<boost::any>         const &hints) const = 0;
        virtual std::vector<terminalpp::rectangle> do_layout(
            std::vector<terminalpp::extent> const &preferred_sizes,
            std::vector<boost::any>         const &hints,
            terminalpp::extent                     size) const = 0;
    };

    template <class Model>
    struct model : concept
    {
        model(Model &&mdl)
          : mdl_(std::forward<Model>(mdl))
        {
        }

        terminalpp::extent get_preferred_size(
            std::vector<terminalpp::extent> const &preferred_sizes,
            std::vector<boost::any>         const &hints) const override
        {
            return mdl_.get_preferred_size(preferred_sizes, hints);
        }

        std::vector<terminalpp::rectangle> do_layout(
            std::vector<terminalpp::extent> const &preferred_sizes,
            std::vector<boost::any>         const &hints,
            terminalpp::extent                     size) const override
        {
            return mdl_.do_layout(preferred_sizes, hints, size);
        }

        Model mdl_;
    };

    std::unique_ptr<concept> self_;
};

}}

#endif
