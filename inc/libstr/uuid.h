#pragma once
#include <uuid/uuid.h>
#include <string>

struct UUID {
    static UUID random();
    static UUID fromString(const char* str);
    std::string string() const;
    friend std::ostream& operator<<(std::ostream& out, UUID const& uuid);
private:
    uuid_t _uuid;
};
