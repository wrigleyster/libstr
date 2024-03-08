#include <libstr/cstr.h>
#include <cstring>

cstr&
cstr::
operator=(char* str) noexcept{
    str_.reset(str);
    return *this;
}

cstr&
cstr::
operator=(cstr&& o) noexcept {
    str_ = std::move(o.str_);
    return *this;
}


cstr&
cstr::
reinit(std::size_t size){
    str_.reset(static_cast<char*>(::malloc(size+1)));
    str_.get()[size] = '\0';
    return *this;
}

std::size_t
cstr::
strlen() const {
    return ::strlen(this->str_.get());
}
