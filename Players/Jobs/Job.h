//
// Created by Admin on 03/07/2025.
//
#pragma once
#ifndef JOB_H
#define JOB_H
#include <memory>
#include <string>

#include "../../Encounter/Encounter.h"
#include "../../Encounter/Enemy.h"
#include "../../SpecialEvent/PotionsMerchant.h"
#include "../../SpecialEvent/SolarEclipse.h"


class Charactor;
class Job {
public:
      Job () ;
    ~Job()  = default ;
    virtual void doJob(Charactor& charactor); // nothing
    virtual const std::string getjob() const = 0;
    virtual  void SolarEclipse(Charactor& charactor) ;
    virtual void takeDamge(std::shared_ptr<Enemy>enemy);
    virtual void applyin(std::shared_ptr<Charactor>charactor,std::shared_ptr<PotionsMerchant>potions_merchant);
    virtual void applyin(std::shared_ptr<Charactor>charactor,std::shared_ptr<::SolarEclipse>solar);
    virtual void applyin(std::shared_ptr<Charactor>charactor,std::shared_ptr<Encounter>encounter);
    static std::unique_ptr<Job> fromString(const std::string& name) ;
};
#endif //JOB_H