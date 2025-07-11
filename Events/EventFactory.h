
#include <memory>
#include <string>
#include <string>
#include <memory>
class Event;
class EventFactory {
    std::string name;

public:
 static    std::shared_ptr<Event> createEvent( const std::string& name );
};


