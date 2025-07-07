//
// Created by Admin on 03/07/2025.
//
#pragma once

#ifndef ARCHER_H
#define ARCHER_H
#include "Job.h"
#endif //ARCHER_H
class Archer: public Job {
public:
    Archer( ) ;
    ~Archer()  = default ;
    void doJob(Charactor& charactor) override;
    const std::string getjob() const override;
    void SolarEclipse( Charactor& charactor) override;
};