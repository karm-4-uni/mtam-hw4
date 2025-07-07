//
// Created by Admin on 03/07/2025.
//
#pragma once

#ifndef WORRIOR_H
#define WORRIOR_H
#include "Job.h"
#endif //WORRIOR_H

class Warrior: public Job {
public:
    Warrior( )  ;
    void doJob(Charactor& charactor) override;
    const std::string getjob() const override;
    void SolarEclipse(Charactor& charactor) override;
};