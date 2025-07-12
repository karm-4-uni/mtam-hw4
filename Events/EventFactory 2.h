
#pragma once
#include <memory>
#include <string>

class Event;

class EventFactory {
public:
    std::shared_ptr<Event> createEvent(const std::string& name);
};

