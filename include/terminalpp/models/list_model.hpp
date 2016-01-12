#ifndef TERMINALPP_MODELS_LIST_MODEL_HPP_
#define TERMINALPP_MODELS_LIST_MODEL_HPP_

#include "terminalpp/core.hpp"
#include <functional>
#include <memory>

namespace terminalpp { namespace models {

//* =========================================================================
/// \brief A Concept that contains an list of objects
//* =========================================================================
template <class Element>
class list_model
{
public :
    //* =====================================================================
    /// \brief Constructor
    //* =====================================================================
    template <class Model>
    explicit list_model(Model &&mdl)
      : self_(new model<Model>(std::forward<Model>(mdl)))
    {
    }

    //* =====================================================================
    /// \brief Returns the number of elements in the list.
    //* =====================================================================
    u32 size() const
    {
        return self_->size();
    }

    //* =====================================================================
    /// \brief Adds an element to the end of the list.
    //* =====================================================================
    void add(Element const &element)
    {
        self_->add(element);
    }

    //* =====================================================================
    /// \brief Adds an element to the end of the list.
    //* =====================================================================
    void add(Element &&element)
    {
        self_->add(std::forward<Element>(element));
    }

    //* =====================================================================
    /// \brief Returns an element in the list at the specified index.
    //* =====================================================================
    Element &get(u32 index)
    {
        return self_->get(index);
    }

    //* =====================================================================
    /// \brief Returns an element in the list at the specified index.
    //* =====================================================================
    Element const &get(u32 index) const
    {
        return self_->get(index);
    }

    //* =====================================================================
    /// \brief Removes the element at the specified index.
    //* =====================================================================
    void remove(u32 index)
    {
        self_->remove(index);
    }

private :
    struct concept
    {
        virtual ~concept(){}
        virtual u32 size() const = 0;
        virtual void add(Element const &element) = 0;
        virtual void add(Element &&element) = 0;
        virtual Element &get(u32 index) = 0;
        virtual Element const &get(u32 index) const = 0;
        virtual void remove(u32 index) = 0;
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

        virtual void add(Element const &element) override
        {
            mdl_.add(element);
        }

        virtual void add(Element &&element) override
        {
            mdl_.add(std::forward<Element>(element));
        }

        virtual Element &get(u32 index) override
        {
            return mdl_.get(index);
        }

        virtual Element const &get(u32 index) const override
        {
            return mdl_.get(index);
        }

        virtual void remove(u32 index) override
        {
            mdl_.remove(index);
        }

        Model mdl_;
    };

    std::unique_ptr<concept> self_;
};

}}

#endif
