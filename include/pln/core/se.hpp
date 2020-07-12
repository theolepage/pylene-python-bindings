#pragma once

namespace pln {
    class se_t
    {
    public:
        auto get_structuring_element() const;

    private:
        virtual void polymorphic() const noexcept = 0 ; // Used to allow the dynamic cast
    };
}