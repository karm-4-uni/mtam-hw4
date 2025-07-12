

#include <string>

# include "Event.h"
# include <string>

#include "Enemy.h"

Event::Event(const std::string &name) {
    this->name=name;
}
std::string Event::getname() const {
    return this->name;
}




