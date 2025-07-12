//
// Created by Admin on 03/07/2025.
//
#pragma once
#define MAGICIAN_H
#include "Job.h"
class Magician: public Job {
public:
    Magician( ) ;
    ~Magician() = default;
    void doJob(Charactor& charactor) override;
      const std::string getjob() const override;
    void SolarEclipse(Charactor& charactor) override;
    void applyin(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy) override;
    void applyin(std::shared_ptr<Player> player) override;
};
