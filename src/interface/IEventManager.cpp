
#include "interface/IEventManager.hpp"

std::ostream &operator<<(std::ostream &os, const LE::Key &key)
{
    os << "Key: " << key.key << " Type: " << key.type;
    os << "is already pressed: " << key._alreadyPressed;
    return os;
}

std::ostream &operator<<(std::ostream &os, const LE::Status &status)
{
    os << "Status: " << (status.success ? "Success" : "Failure") << std::endl;
    os << "Message: " << status.message << std::endl;
    return os;
}