
#include <memory>
#include <string>
class Event;
class EventFactory {

    std::string name;

public:
    std::shared_ptr<Event> createevent( std::string name );


};
