#ifndef TERMINALPP_MODELS_CONTAINER_MODEL_HPP_
#define TERMINALPP_MODELS_CONTAINER_MODEL_HPP_

#include <terminalpp/views/view.hpp>
#include <boost/any.hpp>
#include <memory>
#include <utility>

namespace terminalpp { namespace models {

//* =========================================================================
/// \brief A Concept that models a container.
//* =========================================================================
class container_model
{
public :
    //* =====================================================================
    /// \brief Constructor
    //* =====================================================================
    template <class Model>
    explicit container_model(Model &&mdl)
      : self_(new model<Model>(std::forward<Model>(mdl)))
    {
    }

    //* =====================================================================
    /// \brief Returns the number of views in the container.
    //* =====================================================================
    u32 size() const
    {
        return self_->size();
    }

    //* =====================================================================
    /// \brief Adds a view to the container with a hint as to how to lay
    /// it out.
    //* =====================================================================
    void add(
        terminalpp::views::view &&view,
        boost::any const &hint)
    {
        self_->add(std::move(view), hint);
    }

private :
    struct concept
    {
        virtual ~concept(){}
        virtual u32 size() const = 0;
        virtual void add(
            terminalpp::views::view &&view,
            boost::any const &hint) = 0;
    };

    template <class Model>
    struct model : concept
    {
        model(Model &&mdl)
          : mdl_(std::forward<Model>(mdl))
        {
        }

        virtual u32 size() const override
        {
            return mdl_.size();
        }

        virtual void add(
            terminalpp::views::view &&view,
            boost::any const &hint) override
        {
            mdl_.add(std::move(view), hint);
        }

        Model mdl_;
    };

    std::unique_ptr<concept> self_;
};

}}

#endif
