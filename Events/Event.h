
#pragma once
#include <memory>
#include <string>


class Charactor;

class Player;
class Event :public std::enable_shared_from_this<Event> {
 friend class Charactor;
 friend class Player;
 protected:
  std::string name;
 Event() = default;
 virtual  std::string getDescription() const = 0;
   //virtual  void applyEvent( std::shared_ptr<Charactor> charactor);
   virtual  void applyEventP( std::shared_ptr<Player> player);

  public:
 Event(const std::string &name);
   std::string getname() const;
};
