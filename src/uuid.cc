#include <libstr/uuid.h>
#include <sstream>

UUID
UUID::fromString(const char* str) {
    UUID uuid;
    ::uuid_parse(str, uuid._uuid);
    return uuid;
}

UUID
UUID::random() {
    UUID uuid;
    :: uuid_generate(uuid._uuid);
    return uuid;
}

std::string
UUID::string() const {
    std::ostringstream out;
    out << *this;
    return out.str();
}

std::ostream&
operator<<(std::ostream& out, UUID const& uuid) {
    int i = 0;
    while(i<4) out << static_cast<int>(uuid._uuid[i++]);
    out << '-';
    while(i<6) out << static_cast<int>(uuid._uuid[i++]);
    out << '-';
    while(i<8) out << static_cast<int>(uuid._uuid[i++]);
    out << '-';
    while(i<10) out << static_cast<int>(uuid._uuid[i++]);
    out << '-';
    while(i<16) out << static_cast<int>(uuid._uuid[i++]);
    return out;
}
