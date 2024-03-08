#pragma once
#include <string>
#include <memory>

class cstr{
    protected:
        std::unique_ptr<char, decltype(::free)*> str_{nullptr, ::free};
    public:
        cstr(cstr const&) = delete;
        cstr& operator=(cstr const&) = delete;

        cstr() = default;
        cstr(cstr&& o) noexcept :str_{std::move(o.str_)}{o.str_ = nullptr;}
        explicit
        cstr(char* mallocated_str):str_{mallocated_str,::free}{}

        virtual cstr&
        operator=(char* str) noexcept;

        cstr&
        operator=(cstr&& o) noexcept;

        char *
        operator&()noexcept{return str_.get();}

        virtual cstr&
        reinit(std::size_t size);

        [[nodiscard]]
        std::size_t
        strlen() const;

        std::string
        str(){return {str_.get()};}
};
