

# include "Event.h"
# include <string>
Event::Event(const std::string &name) {
    this->name=name;
}
std::string Event::getname() const {
    return this->name;
}



