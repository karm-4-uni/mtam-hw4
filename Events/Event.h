
#pragma once


class Event {

public:
    virtual ~Event() = default;
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
   virtual  std::string getDescription() const = 0;
    virtual  void applyEvent(Charactor &currcharactor);


};
