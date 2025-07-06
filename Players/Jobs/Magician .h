//
// Created by Admin on 03/07/2025.
//
#include "Jobs/Job.h"
#ifndef MAGICIAN_H
#define MAGICIAN_H
#endif //MAGICIAN_H
class Magician: public Job {
public:
    Magician( ) ;;
    void doJob(Charactor& charactor) override;
      const std::string getjob() const override;
    void SolarEclipse(Charactor& charactor) override;
};