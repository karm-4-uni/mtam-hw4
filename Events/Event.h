
#pragma once
#include <string>


class Charactor;

class Event {

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
    virtual  void applyEvent(Charactor& currcharactor);

public:
 std::string getname() const;
};
