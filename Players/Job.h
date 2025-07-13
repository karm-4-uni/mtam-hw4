#pragma once
#ifndef JOB_H
#define JOB_H
#include <memory>
#include <string>

#include "../Events/PotionsMerchant.h"
#include "../Events/SolarEclipse.h"
class Enemy;
class Encounter;
class Charactor;
class Job {
public:
    Job () ;
    ~Job()  = default ;
    virtual void doJob(Charactor& charactor); // nothing
    virtual const std::string getjob() const = 0;
    virtual  void SolarEclipse(Charactor& charactor) ;
    virtual void applyin(std::shared_ptr<Player>player)=0;
    virtual void applyin(std::shared_ptr<Player>player,std::shared_ptr<Enemy>enemy)=0;
    static std::shared_ptr<Job> fromString(const std::string &name) ;
};
#endif //JOB_H