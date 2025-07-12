
#pragma once

#include "Job.h"

class Charactor;
class Warrior: public Job {
public:
    Warrior();
    ~Warrior()  = default ;
    void doJob(Charactor& charactor) override;
    const std::string getjob() const override;
    void SolarEclipse(Charactor& charactor) override;
    void applyin(std::shared_ptr<Player> player, std::shared_ptr<Encounter> encounter) override;
    void applyin(std::shared_ptr<Player> player, std::shared_ptr<::SolarEclipse> solar) override;
    void takeDamge(std::shared_ptr<Enemy> enemy) override;
};
