#pragma once

#include "Job.h"
class Archer: public Job {
public:
    Archer( ) ;
    ~Archer()  = default ;
    void doJob(Charactor& charactor) override;
    const std::string getjob() const override;
    void SolarEclipse( Charactor& charactor) override;
    void applyin(std::shared_ptr<Player> player) override;
    void applyin(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy) override;
};