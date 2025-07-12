
#pragma once
#include <string>

#include "../Players/Player.h"


class Event:public std::enable_shared_from_this<Event>{

protected:
 std::string name;
public:
    virtual ~Event() = default;
     Event()=default;
 Event(const std::string& name);
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
   virtual  std::string getDescription() const = 0;
    virtual  void applyEvent( std::shared_ptr<Player>player);

public:
 std::string getname() const;
};
