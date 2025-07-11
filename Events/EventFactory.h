
#include <string>
#include <memory>
class Event;
class EventFactory {

    std::string name;

public:
    std::shared_ptr<Event> createEvent( const std::string& name );


};
