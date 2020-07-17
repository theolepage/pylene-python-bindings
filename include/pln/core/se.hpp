#pragma once

namespace pln {
    class se_t
    {
    private:
        // Used to allow the dynamic cast
        virtual void polymorphic() const noexcept
        {}
    };
}